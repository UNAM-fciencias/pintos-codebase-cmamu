#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "userprog/process.h"

static void syscall_handler (struct intr_frame *);
static int32_t write_wrapper (int32_t *esp);
static void exit_wrapper (int32_t *esp);
static int32_t write (int file_descriptor, char* buffer, unsigned size);
static void exit (int exit_status);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  int32_t* esp = f->esp; // stack pointer
  int32_t syscall = *esp; // Que llamada a sistema estamos obteniendo
  esp++;

  // Llamar a process_wait()
  // Con semaforos inicializado en 0
  // Despertar cuando el proceso termina, es decir cuando exit() se invoca

  // las tres forman parte de que un proceso crea un proceso, llamada central exec, empezar por exec once
  // exec intenta ejecutar un proceso, si lo logra regresa el id del proceso creado. 

  // Wait espera a que si es regresado un id valido termine su ejecucion, syscall en lib tiene la definicion de
  // las funciones.


  switch(syscall) {
    case SYS_WRITE: {
      // registro eax nos sirve para almacenar ...
      //f->eax = write_wrapper (esp); // invocamos un wrapper, en ese w extraer los argumentos
      int fd = *esp;
      esp++;
      void* buffer = (void*)*esp;
      esp++;
      unsigned int size = *esp;
      putbuf(buffer, size);
      break;
    }
    case SYS_EXIT: {
      //exit_wrapper (esp);
      //printf("%s: exit(0)\n", thread_current()->name);
      // Obtención del argumento.
      int status = *esp;
      printf("%s: exit(%d)\n", thread_current()->name, status);      
      // Guardado del valor de salida.
      struct thread *cur = thread_current ();
      struct thread *padre = cur->padre;
      if (padre != NULL) {
        // Buscar al hijo en la lista de hijos
        // del padre y asignar el exit_status.
        struct list *hijos = &padre->hijos;
        struct list_elem *hijo_elem;
        if (!list_empty(hijos)) {
          for (hijo_elem = list_front(hijos); hijo_elem != list_end(hijos); hijo_elem = list_next(hijo_elem)) {
            struct process *hijo = list_entry(hijo_elem, struct process, elem);
            if (hijo->tid == cur->tid) {
              hijo->exit_status = status;
              sema_up(&padre->wait);
            }
          }
        }
      }

      thread_exit ();
      break;
    }
    case SYS_EXEC: {
      // 1.- extraer parametros de la llamada, ponerlo en un wraper?
      // 2.- Falta implementar, crear un nuevo proceso con un comando de usuario? -> usar process_execute
      // Aqui que en una lista se tengan todos sus hijos?
      
      // cachar cuando el proceso de usario no se pueda crear y regresar, debe de hacer el process_execute
      // trabajar con memoria compartida
      // modificar start_process?
      //char* cmd = (char*)*esp;
      //f->eax = process_execute(cmd);
      const char* cmd = (char*)*esp;
      f->eax = (uint32_t) process_execute(cmd);
      break;
    }
    case SYS_WAIT: {
	//int pid = (int)*esp;
	//f->eax = process_wait(pid);
	tid_t child_tid = *esp;
	f->eax = process_wait(child_tid);
	break;
    }
    default: {
      printf ("unsupported syscall\n");
      thread_exit ();
    }
  }
}

/* Write Syscall Implementation */
static int32_t 
write_wrapper (int32_t *esp) {
  // Extrae los argumentos
  int file_descriptor = *esp;
  char *buffer = (char *) *++esp; // ++ subes un escalonsito en el stack pointer 
  unsigned size = (unsigned) *++esp;
  return write (file_descriptor, buffer, size);
}

static int32_t 
write (int file_descriptor UNUSED, char* buffer, unsigned size) {
  putbuf (buffer, size);
  return size;
}

/* Write Syscall Implementation */
static void 
exit_wrapper (int32_t *esp) {
  int exit_status = *esp;
  exit (exit_status);
}

static void 
exit (int exit_status UNUSED) {
  thread_exit ();
}

#include "userprog/syscall.h"
#include "userprog/process.h" // P05.
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  uint32_t* esp = f->esp;
  uint32_t syscall = *esp;
  esp++;
  
  switch(syscall) {
    case SYS_WRITE: {
      int fd = *esp;
      esp++;
      void* buffer = (void*)*esp;
      esp++;
      unsigned int size = *esp;
      
      putbuf(buffer, size);
      
      break;
    }
    case SYS_EXIT: { // P05.

      // Obtención del argumento.
      int status = *esp;

      printf("%s: exit(%d)\n", thread_current()->name, status);

      // Guardado del valor de salida.
      struct thread *cur = thread_current ();
      struct thread *padre = cur->father;
      if (padre != NULL) {
        // Buscar al hijo en la lista de hijos
        // del padre y asignar el exit_status.
        struct list *hijos = &padre->children;
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
    case SYS_WAIT: { // P05.

      // Obtención del argumento.
      tid_t child_tid = *esp;

      f->eax = process_wait(child_tid);

      break;
    }
    case SYS_EXEC: { // P05.
      
      // Obtención del argumento.
      const char* cmd = (char*)*esp;

      f->eax = (uint32_t) process_execute(cmd);

      break;
    }
  }
}

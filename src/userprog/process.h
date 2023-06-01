#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

struct process {
  tid_t tid;                      /* El tid del proceso. */
  struct thread* t;               /* Referencia a este proceso. */
  int exit_status;                /* Valor de salida del hijo. */
  struct list_elem elem;          /* List element para la lista de hijos. */
};

#endif /* userprog/process.h */

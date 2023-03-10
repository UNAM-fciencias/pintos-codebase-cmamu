* Integrantes del equipo:
Adrian Aguilera Moreno. Cta. 421005200.
Kevin Jair Torres Valencia. Cta. 318331818.
##########################################################################################################

* Preguntas:
1. La función running_thread obtiene el struct thread del hilo en ejecución, la función utiliza el
valor del registro esp para obtener la estructura. ¿Por que no se utiliza una variable global tipo
apuntador que contenga el apuntador del hilo en ejecución y cuando el hilo cambia solamente
cambiar el apuntador por el nuevo hilo?

RESPUESTA. Por el tiempo de reacción. Podemos perder información, además el apuntador apunta a la pila y
no al heap, entonces tenemos un problema de actualización en un pequeño tiempo que puede ser suficiente
para provocar retrasos.

2. La función switch_threads es la encargada de cambiar de ejecución un hilo por otro. En resumen,
la función sustituye los valores de ciertos registros. El registro EIP (Instruction Pointer o Program
Counter) guarda el valor de la siguiente instrucción a ejecutar. ¿Por qué la función switch_threads
no sustituye dicho registro?

RESPUESTA. Porque la instrucción siempre es la misma, el proceso regresa al punto en donde fue intercambiado.

3. De las dos técnicas para implementar el calendarizador de prioridades: mantener la lista ordenada
o buscar el máximo. ¿Cúal es más factible utilizar? y ¿Por qué? 

RESPUESTA. Ambas tienen la misma complejidad, porque mantener la lista (ready_list) ordenda respecto a su
prioridad nos toma O(n) y encontrar, cada vez que se forma un proceso, su posición nos toma O(n). Sin embargo,
la lista ordenada nos permite realizar la intrucción yield para sacar el proceso actual y que entre el de mayor
prioridad. Si no tuvieramos la lista ordenada, gendríamos que buscar el de mayor prioridad para comparar prioridad
y para sustituir el courrent, aunque esto no altera la complejidad en tiempo.

4. Describe brevemente como lograste que tu solución cumpliera con ser un calendarizador preemptive.

RESPUESTA. La solución debía cumplir con que el proceso en ejecución fuese el de mayor prioridad siempre. Entonces
debímos revisar que
1. Todo elemento en la ready_list tenga una prioridad menor a la del proceso en ejecución, si no es el caso se
debía cambiar al proceso actual por el de mayor prioridad en la ready_list. Esto con la función yield si nuestra
ready_list esta ordenada (se introducen procesos en orden de prioridad), caso contrario debemos modificar yield
para que busque el de mayor prioridad.
2. Si un proceso es desbloqueado y tiene mayor prioridad que el proceso actual, se debe cambiar. Nuevamente usando yield,
pero antes el proceso a desbloquear debe estar en el tope de la lista (ser insertado en orden).
3. Cuando creamos un proceso y tiene mayor prioridad que el proceso actual, se debe cambiar. El código de create nos regala
el no modificar, pues invoca a unblock.
4. Cuando se cambia la prioridad de un proceso, entonces debemos verificar si esta prioridad es mayor a la del proceso actual.
O en otro caso, si al proceso actual se le decrementa la prioridad, debemos verificar si sigue siendo el mayor respecto a prioridad.
En ambos casos, se debe intercambiar si el proceso actual no tiene la prioridad más grande en contraste a algún proceso en la
ready_list.
##########################################################################################################

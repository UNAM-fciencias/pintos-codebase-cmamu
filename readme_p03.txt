* Integrantes del equipo:
Adrian Aguilera Moreno. Cta. 421005200.
Kevin Jair Torres Valencia. Cta. 318331818.
##########################################################################################################

* Preguntas:
1. ¿Por qué no utilizamos para el valor load_average simplemente el número de threads de la
ready_list?

RESPUESTA. Nosotros usamos envejecimiento de procesos. Si solo usaramos el número de threads
de la ready_list nuestros procesos en la all_list que no se encuentren en la ready_list estarán
con sus prioridades anteriores, lo que no es tan bueno, pues seguiriamos teniendo problemas
de hambruna. También. es posible que el conteo de esta manera siga trayendo problemas de
hambruna.

2. ¿Por qué razón al utilizar el módulo de punto flotante vuelve más lento al kernel?

RESPUESTA. Porque utiliza más bits, y están envueltos en una operación que no es atómica
como si son las operaciones definidas en bits.

3. ¿Como garantiza tu solución que los threads bloqueados (los que no están en la read\_list)
aumentan su prioridad cuando se desbloquean?

RESPUESTA. La all_list aumenta la prioridad de sus procesos por el tiempo en el que estos
han estado listos para ejecutarse (de hecho, desde que se crearon). Al entrar a la ready_list
los procesos han cambiado su prioridad y pueden ser competitivos respecto a otros procesos.

4. En la práctica 1 cambiaste la implementación de timer_sleep para que no se utilizara una espera
ocupada. ¿Una implementación de timer_sleep con espera ocupada afectaría en algo a tu implementación
del calendarizador MLFQ?

RESPUESTA. Sí, la espera ocupada implicaría un aumento en la complejidad del proceso de calendarización
con envejecimiento.

5. ¿Tu implementación afecta en algo la propiedad preemptive del calendarizador?

RESPUESTA. Sí, al realizar cambios de las prioridades podemos bajar la prioridad (regular) de un proceso,
de tal manera que este no tenga preferencia en un punto dado. Si comparamos las implementaciones podemos
notar que el proceso X con prioridad alta será preferente en n - X procesos, con la nueva implementación
esto no necesariamente es cierto (la prioridad bajará).
##########################################################################################################

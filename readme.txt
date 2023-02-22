* Integrantes del equipo:
Adrian Aguilera Moreno. Cta. 421005200.
Kevin Jair Torres Valencia. Cta. TODO. Agrega número de cuenta.

TODO. Revisarlas y complementarlas.
* Preguntas:
1. Pintos es un Kernel para un sistema con un solo núcleo,
¿Qué cambios deberían hacerse en su proceso de inicialización
(booting) para que funcione en un sistema multi-núcleo?

RESPUESTA. Se le debe enviar interrupciones o señales al resto
de los núcleos (el responsable de esto es el thread main) y
asignarles tareas en cuanto estén desocupados.

2. ¿Para qué sirve el stack de un proceso?

RESPUESTA. Para almacenar las tareas que este debe realizar.

3. ¿Qué diferencia hay entre el thread idle y el thread main?

RESPUESTA. El proceso main debe crear el primer proceso de usuario para generar el resto de procesos,
podríamos decir que este inicia nuestro sistema. Mientras que el proceso idle recibe instrucciones,
como oprimir una letra, mover el touch pad, etc. Y así manda una seríe de interrupciones para indicar
estas operaciones.

4. Si suponemos que solamente existe un thread en ejecución y dicho thread se bloquea (utilizando la
función thread_block). ¿De que forma se podrá despertar el thread si es el único en ejecución?

RESPUESTA. El timer se encargará de despertar (manda una interrupción) el proceso luego de haber pasado
un cierto número de ticks (los indicados, hasta antes de despertarlo) o, en otro caso el thread
será despertado cuando sea requerido (eso lo puede indicar el proceso idle).

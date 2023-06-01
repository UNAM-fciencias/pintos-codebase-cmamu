* Integrantes del equipo:
Adrian Aguilera Moreno. Cta. 421005200.
Kevin Jair Torres Valencia. Cta. 318331818.
##########################################################################################################
--> Preguntas:

1. ¿Por qué el espacio virtual de memoria del Kernel esta junto al 
espacio virtual del proceso de usuario?

Es por que utiliza una tabla de páginas única que abarca tanto el 
espacio de usuario como el espacio del kernel. Esto significa que 
toda la memoria disponible para el sistema, tanto para el kernel 
como para los procesos de usuario, se encuentra en el mismo espacio 
de direcciones virtuales, lo que simplifica la gestión de la memoria 
para el sistema operativo. Además, se tiene acceso directo a la 
memoria de los procesos de usuario, lo que resulta útil para realizar 
operaciones como la lectura y escritura de archivos y la comunicación 
entre procesos.

2. ¿De que forma se garantiza que un proceso de usuario solamente pueda 
acceder a su propia memoria?

Mediante tablas de página, por que:
Cada proceso tiene su propia tabla de páginas que mapea su espacio virtual 
de memoria a las direcciones físicas de la memoria física. Además, la tabla 
de páginas se configura de forma que el proceso de usuario solo tenga acceso 
a su propia memoria y no pueda acceder a la memoria del kernel o la memoria 
de otros procesos. Esto se logra marcando ciertas páginas de la tabla de 
páginas como protegidas y estableciendo permisos de acceso distintos para 
las páginas de kernel y de usuario.

3. ¿Por qué es el sistema operativo es el encargado de colocar los 
parámetros iniciales de un proceso?

Para asegurar que el proceso comience de manera adecuada y con la 
información necesaria. Esto se debe a que el sistema operativo 
tiene control sobre la gestión de la memoria y puede asignar las 
páginas necesarias para alojar la pila del proceso y sus datos iniciales.
Además, el sistema operativo puede garantizar que los parámetros se 
coloquen en la pila de una manera ordenada y coherente con las 
convenciones del sistema y arquitectura utilizada.

4. ¿En qué casos el sistema operativo no puede cargar un programa de usuario?

Algunos casos son cuando:

-Falta de espacio en la memoria: Si no hay suficiente espacio disponible en 
la memoria para alojar el programa y sus datos, el sistema operativo no 
podrá cargar el programa.

-Acceso no autorizado: Si el programa intenta acceder a recursos o áreas 
de memoria que no le corresponden o que no están autorizadas, el sistema 
operativo puede inhabilitar la carga del programa para garantizar la 
seguridad y estabilidad del sistema.

-Errores en el archivo binario: Si el archivo binario del programa está 
dañado o contiene errores de sintaxis, el sistema operativo no podrá 
cargar el programa adecuadamente.

-Incompatibilidad de arquitectura: Si el programa se diseñó para una 
arquitectura de hardware diferente de la utilizada por PintOS, el 
sistema operativo no podrá cargarlo.

En general, el sistema operativo debe realizar diversas comprobaciones 
antes de proceder a cargar un programa de usuario para garantizar la 
estabilidad y seguridad del sistema.

5. ¿Cual es la diferencia entre modo kernel y modo usuario del CPU?

La diferencia es que el modo kernel es utilizado por el sistema 
operativo para tener acceso a los recursos del sistema, mientras 
que el modo usuario es utilizado por los procesos para realizar 
tareas limitadas y específicas dentro del sistema operativo.

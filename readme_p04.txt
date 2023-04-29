* Integrantes del equipo:
Adrian Aguilera Moreno. Cta. 421005200.
Kevin Jair Torres Valencia. Cta. 318331818.
##########################################################################################################
*Preguntas:

1. Describe tu solución a detalle.

R./ Para poder actualizar la prioridad,obtenemos el thread de mayor prioridad de la ready_list 
y comparamos. Si la prioridad del thread actual es menor al mas alto de prioridad en 
priority_thread, se agrega a la lista. La lista se encuentra clasificada e insertados los 
elemenemtos en orden de acuerdo a su prioridad. Cuando se tiene el caso de que el thread adquiere 
una nueva prioridad no surte efecto hasta que el thread (que se cedio) se ha liberado toda la 
prioridad que ha recibido bajo donación. Para determinar el bloqueo que espera el thread, 
si lo hay, nos permitiría donar prioridad, haciendo un comparador de lista de waiters en un 
semáforo.

2. La implementación de semáforos de pintos utiliza un while en lugar de un if, explica porque es
necesario esto.

R./ Porque se debe realizar una asignación de, digamos "prioridades", dónde cada proceso (semáforo) indica
si debe o no aumentar esta. Un if solo verificaría estas condiciones una vez y probablemente no se
daría acceso a secciones críticas mientras llega otro a verificar la condición. Sin embargo, con el
while no desperdiciamos tiempo.

3. ¿Por qué es mejor utilizar primitivas de sincronización en lugar de apagar y encender la interrup-
ciones directamente?

R./ Si apagamos y encendemos las interrumpciones no permitimos interrupciones emergentes y de mayor
prioridad, con las primitivas de sincronización esto no sucede de esta manera.

4. En pintos un lock es un semaphore inicializado en 1 ¿Por qué no usar directamente un semaphore?

R./ Porque es posible que no se coordinen en tiempo real, sin embargo, el lock nos permite tener condiciones
necesarias para acceder a los valores [1,...] requeridos y al llegar a 0 incluimos un pequeño bucle
hasta regresar a 1 nuestro semaphore.
##########################################################################################################
## Instrucciones

En forma individual, utilizando la técnica de programación de búsqueda avanzada, construye un programa en C++ que implemente el algoritmo de A*.

Un laberinto se da como una matriz binaria N * N de bloques donde el punto origen es el bloque superior izquierdo, es decir, la posición [0][0] y el punto destino es el bloque inferior derecho, es decir, la posición [N-1][N-1] . Un Bot (agente virtual) saldrá de la posición fuente y tiene que llegar a la posición destino. El Bot puede moverse en cuatro direcciones: 'U'(up), 'D'(down), 'L''(left), 'R'(right). El valor de 0 (cero) en un bloque o celda en la matriz representa que esta bloqueado y no se puede ser cruzado. El valor de 1 en una bloque o celda en la matriz representa que se puede cruzar por ahí.

A continuación se muestra un ejemplo de laberinto.

    Input: 
    N = 4
    m[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}}
    Output:
    DDRDRR
    DRDDRR

Sube tu programa que se debe llamar A0XXXXXXX_Act5.5.cpp o un archivo ZIP que se llame A0XXXXXXX_Act5.5.ZIP, si tienes más de un archivo. El archivo ZIP contiene una carpeta (folder) llamada A0XXXXXXX_Act5.5, y dentro se encuentra el archivo A0XXXXXXX_Act5.5.cpp y todo lo necesario para que corra tu programa.
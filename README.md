## Instrucciones
Escribe un programa en C++ que implemente los algoritmos de Dijkstra y Floyd para encontrar la distancia más corta entre parejas de nodos en un grafo dirigido. 

El programa debe leer un archivo texto con el siguiente formato:

En la primera fila hay dos números n (número de nodos) y m (número de aristas dirigidas).
Los siguientes m renglones contienen todas las aristas, una en cada renglón, con 3 valores a b c, separados por espacios. a es el nodo inicial de la arista, b es el nodo final de la arista y c es el peso de dicha arista.
El programa debe tener una función que lee el archivo y lo coloca en una lista de adyacencia.

La salida del programa es, primero con el algoritmo de Dijkstra la distancia del nodo i al nodo j, donde j toma los valores de todos los nodos, y luego, la matriz resultado del algoritmo de Floyd

Ejemplo de entrada:

4 8
0 1 2
0 3 3
1 2 1
1 3 5
2 0 2
2 1 3
3 0 3
3 2 4

Lo cual es equivalente a la matriz de adyacencia:
0 2 -1 3
-1 0 1 5
2 3 0 -1
3 -1 4 0

Ejemplo de salida:

Dijkstra :
node 1 to node 2 : 2
node 1 to node 3 : 3
node 1 to node 4 : 3
node 2 to node 1 : 3
...

node 4 to node 2 : 5
node 4 to node 3 : 4

Floyd :
0 2 3 3
3 0 1 5
2 3 0 5
3 5 4 0

Tu programa debe ser llamado <TuMatrícula>_3.2.cpp.
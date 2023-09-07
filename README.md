# Actividad 1.1 Implementación de la técnica de programación "divide y vencerás"

## Instrucciones

Utilizando la técnica de programación de "divide y vencerás", escribe en C++ un programa que implemente los algoritmos de Merge Sort y Quick Sort. Cada algoritmo debe estar implementado en una función que se llamen exactamente mergeSort y quickSort, respectivamente. Estas funciones reciben un vector de enteros que contiene los datos y regresa (return) un vector de enteros con los datos ordenados de menor a mayor.
Los datos se reciben de un archivo el cual tiene la siguiente estructura:

Un numero entero N en la primera línea, indicando el número de datos a ser leídos.
Seguido de N valores enteros (int, uno en cada línea).
La lectura de los datos se hará por medio de una función leeDatos, que recibe como parámetro un string correspondiente al nombre del archivo (con extensión) que contiene los datos a ser ordenados y regresa un vector de enteros con los datos leídos.

Deberás agregar una función llamada imprimeDatos, que reciba como parámetro un vector de enteros y los imprime a la pantalla.

Tu programa debe ser llamado ordena.cpp y puede contener, además de las 4 funciones especificadas anteriormente, todas las funciones auxiliares y las variables que necesites. El programa fuente debe estar comentado.

Un posible main podría ser:

    int main(){

        vector<int> datos, datosOrdenados;

        datos = leeDatos("datos.txt");

        imprimeDatos(datos); // datos desordenados

        datosOrdenados = mergeSort(datos);

        imprimeDatos(datosOrdenados); // datos ordenados con Merge Sort

        datosOrdenados = quickSort(datos);

        imprimeDatos(datosOdenados); // datos ordenados con Quick Sort

        return 0;

    }

Sube tu programa junto con los datos que usaste para probarlo y todos los archivos que requieres para que corra, en un archivo ZIP que se llame <tumatricula_Act1.1>.zip, donde tumatricula lo sustituyes por A0 y lo que corresponda a tu matrícula.
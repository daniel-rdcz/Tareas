// José Daniel Rodríguez Cruz A01781933
// David Santiago Vieyra García A01656030 
// 06/09/2023
// Descripción: Programa que ordena los datos de un archivo de texto con Merge Sort y Quick Sort.

#include <iostream> // Biblioteca para imprimir y leer datos
#include <fstream> // Biblioteca para leer archivos
#include <vector> // Biblioteca para usar vectores
#include <string> // Biblioteca para usar cadenas de caracteres
using namespace std; // Espacio de nombres estándar

// Declaración de las funciones para evitar errores de orden.
void merge(int A[], int lo, int mid, int hi);
void sort(int A[], int lo, int hi);

void merge(int A[], int lo, int mid, int hi) { // Mezclar dos arreglos ordenados
    int i = lo, j = mid + 1; // Índices para recorrer los arreglos
    vector<int> aux(hi - lo + 1); // Arreglo auxiliar para almacenar los datos ordenados
    for (int k = lo; k <= hi; k++) { // Recorrer el arreglo
        aux[k - lo] = A[k]; // Copiar el arreglo en aux
    }
    for (int k = lo; k <= hi; k++) { // Recorrer el arreglo
        if (i > mid) A[k] = aux[j++ - lo]; // Si ya se terminó de recorrer la primera mitad, copiar los datos de la segunda mitad
        else if (j > hi) A[k] = aux[i++ - lo]; // Si ya se terminó de recorrer la segunda mitad, copiar los datos de la primera mitad
        else if (aux[j - lo] < aux[i - lo]) A[k] = aux[j++ - lo]; // Si el dato de la segunda mitad es menor, copiarlo
        else A[k] = aux[i++ - lo]; // Si el dato de la primera mitad es menor, copiarlo
    }
}

void sort(int A[], int lo, int hi) { // Ordenar el arreglo A
    if (hi <= lo) return; // Si el arreglo tiene un solo elemento, ya está ordenado
    int mid = lo + (hi - lo) / 2; // Calcula la mitad del arreglo
    sort(A, lo, mid); // Ordena la primera mitad
    sort(A, mid + 1, hi); // Ordena la segunda mitad
    merge(A, lo, mid, hi); // Mezcla las dos mitades
}

vector<int> mergeSort(vector<int> datos) { // Ordenar los datos con Merge Sort
    int n = datos.size(); // Cantidad de datos
    int A[n]; // Arreglo para almacenar los datos
    for (int i = 0; i < n; i++) { // Copiar los datos al arreglo A
        A[i] = datos[i]; // Copiar los datos al arreglo A
    }
    sort(A, 0, n - 1); // Ordenar el arreglo A
    vector<int> datosOrdenados;
    for (int i = 0; i < n; i++) {
        datosOrdenados.push_back(A[i]); // Copiar los datos ordenados al vector datosOrdenados
    }
    return datosOrdenados; // Devolver el vector datosOrdenados
}

int partition(int A[], int lo, int hi) { // Particionar el arreglo A
    int i = lo, j = hi + 1; // Índices para recorrer el arreglo
    int v = A[lo]; // Elemento pivote
    while (true) {
        while (A[++i] < v) if (i == hi) break; // Buscar un elemento mayor o igual que el pivote
        while (v < A[--j]) if (j == lo) break; // Buscar un elemento menor o igual que el pivote
        if (i >= j) break; // Si los índices se cruzan, terminar
        swap(A[i], A[j]); // Intercambiar los elementos
    }
    swap(A[lo], A[j]); // Intercambiar el pivote con el elemento en la posición j
    return j; // Devolver la posición del pivote
}

void sortQuick(int A[], int lo, int hi) { // Ordenar el arreglo A
    if (hi <= lo) return; // Si el arreglo tiene un solo elemento, ya está ordenado
    int j = partition(A, lo, hi); // Particionar el arreglo
    sortQuick(A, lo, j - 1); // Ordenar la primera mitad
    sortQuick(A, j + 1, hi); // Ordenar la segunda mitad
}

vector<int> quickSort(vector<int> datos) { // Ordenar los datos con Quick Sort
    int n = datos.size(); // Cantidad de datos
    int A[n]; // Arreglo para almacenar los datos
    for (int i = 0; i < n; i++) { // Copiar los datos al arreglo A
        A[i] = datos[i]; // Copiar los datos al arreglo A
    }
    sortQuick(A, 0, n - 1); // Ordenar el arreglo A
    vector<int> datosOrdenados;
    for (int i = 0; i < n; i++) {
        datosOrdenados.push_back(A[i]); // Copiar los datos ordenados al vector datosOrdenados
    }
    return datosOrdenados; // Devolver el vector datosOrdenados
}

vector<int> leeDatos(string nombreArchivo) {
    ifstream archivo; // Declarar el archivo
    archivo.open(nombreArchivo); // Abrir el archivo
    vector<int> datos; // Vector para almacenar los datos leídos desde el archivo
    if (archivo.is_open()) {
        int n; // Cantidad de datos
        archivo >> n; // Leer la cantidad de datos
        int A[n]; // Arreglo para almacenar los datos
        for (int i = 0; i < n; i++) { // Leer cada dato
            archivo >> A[i]; 
            datos.push_back(A[i]); // Agregar cada valor al vector datos
        }
        archivo.close(); // Cerrar el archivo
    } else {
        cout << "No se pudo abrir el archivo" << endl; // Mostrar mensaje de error
    }

    return datos; // Devolver el vector datos
}

void imprimeDatos(vector<int> datos) { // Imprimir los datos del vector
    for (int i = 0; i < datos.size(); i++) { // Recorrer el vector
        cout << datos[i] << " "; // Imprimir cada dato
    }
    cout << endl; // Imprimir un salto de línea
}

int main() { // Función principal
    vector<int> datos, datosOrdenados; // Declarar los vectores datos y datosOrdenados
    datos = leeDatos("datos.txt"); // Leer los datos desde el archivo
    imprimeDatos(datos); // datos desordenados
    // Merge Sort tiene una complejidad computacional de O(n log n)
    datosOrdenados = mergeSort(datos); // Ordenar los datos con Merge Sort
    imprimeDatos(datosOrdenados); // datos ordenados con Merge Sort
    // Quick Sort tiene una complejidad computacional de O(n^2), normalmente es O(n log n)
    datosOrdenados = quickSort(datos); // Ordenar los datos con Quick Sort
    imprimeDatos(datosOrdenados);  // datos ordenados con Quick Sort
    return 0; // Terminar el programa
}
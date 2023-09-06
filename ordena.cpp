#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Declaración de las funciones para evitar errores de orden.
void merge(int A[], int lo, int mid, int hi);
void sort(int A[], int lo, int hi);

void merge(int A[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    vector<int> aux(hi - lo + 1);

    for (int k = lo; k <= hi; k++) {
        aux[k - lo] = A[k]; // Copiar el arreglo en aux
    }

    for (int k = lo; k <= hi; k++) {
        if (i > mid) A[k] = aux[j++ - lo];
        else if (j > hi) A[k] = aux[i++ - lo];
        else if (aux[j - lo] < aux[i - lo]) A[k] = aux[j++ - lo];
        else A[k] = aux[i++ - lo];
    }
}

void sort(int A[], int lo, int hi) {
    if (hi <= lo) return; // Si el arreglo tiene un solo elemento, ya está ordenado
    int mid = lo + (hi - lo) / 2; // Calcula la mitad del arreglo
    sort(A, lo, mid); // Ordena la primera mitad
    sort(A, mid + 1, hi); // Ordena la segunda mitad
    merge(A, lo, mid, hi); // Mezcla las dos mitades
}

vector<int> mergeSort(vector<int> datos) {
    int n = datos.size();
    int A[n];
    for (int i = 0; i < n; i++) {
        A[i] = datos[i]; // Copiar los datos al arreglo A
    }
    sort(A, 0, n - 1); // Ordenar el arreglo A
    vector<int> datosOrdenados;
    for (int i = 0; i < n; i++) {
        datosOrdenados.push_back(A[i]); // Copiar los datos ordenados al vector datosOrdenados
    }
    return datosOrdenados; // Devolver el vector datosOrdenados
}

vector<int> leeDatos(string nombreArchivo) {
    ifstream archivo;
    archivo.open(nombreArchivo);

    vector<int> datos; // Vector para almacenar los datos leídos desde el archivo

    if (archivo.is_open()) {
        int n;
        archivo >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            archivo >> A[i];
            datos.push_back(A[i]); // Agregar cada valor al vector datos
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    return datos; // Devolver el vector datos
}

void imprimeDatos(vector<int> datos) {
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> datos, datosOrdenados;
    datos = leeDatos("datos.txt");
    imprimeDatos(datos); // datos desordenados
    datosOrdenados = mergeSort(datos);
    imprimeDatos(datosOrdenados); // datos ordenados con Merge Sort
    // datosOrdenados = quickSort(datos);
    // imprimeDatos(datosOdenados);  datos ordenados con Quick Sort
    return 0;
}
// David Santiago Vieyra García A01656030
// José Daniel Rodríguez Cruz A01781933

// Importamos las librerías necesarias
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Greedy
vector<int> minNumMonGR(int cambio, int numeros[], int numMonedas){ 
    vector<int> numMonedasUsadas; // Vector que guarda las monedas usadas
    for(int i = 0; i < numMonedas; i++){ // Recorremos el arreglo de monedas
        while(cambio >= numeros[i]){ // Mientras el cambio sea mayor o igual a la moneda
            cambio -= numeros[i]; // Restamos el cambio con la moneda
            numMonedasUsadas.push_back(numeros[i]); // Agregamos la moneda al vector
        }
    }
    return numMonedasUsadas; // Regresamos el vector con las monedas usadas
}

// Programación Dinámica
vector<int> minNumMonDP(int cantidad, int numeros[], int numMonedas) {
    vector<int> dp(cantidad + 1, INT_MAX); // Vector que guarda el número mínimo de monedas
    vector<int> cambio(cantidad + 1, -1); // Vector que guarda el índice de la moneda usada

    dp[0] = 0; // Caso base

    for (int i = 1; i <= cantidad; i++) { // Recorremos el arreglo de monedas
        for (int j = 0; j < numMonedas; j++) {
            if (numeros[j] <= i && dp[i - numeros[j]] + 1 < dp[i]) { // Si el número de monedas es menor al mínimo
                dp[i] = dp[i - numeros[j]] + 1; // Actualizamos el mínimo
                cambio[i] = j; // Actualizamos el índice de la moneda usada
            }
        }
    }

    vector<int> numMonedasUsadas; // Vector que guarda las monedas usadas
    int k = cantidad; // Variable auxiliar
    while (k > 0) { // Mientras k sea mayor a 0
        numMonedasUsadas.push_back(numeros[cambio[k]]); // Agregamos la moneda al vector
        k -= numeros[cambio[k]]; // Restamos el cambio con la moneda
    }

    return numMonedasUsadas; // Regresamos el vector con las monedas usadas
}

// Función que escribe la respuesta

void escribeRespuesta(vector<int>& numMonedasUsadas){
    int current = numMonedasUsadas[0]; // Variable auxiliar
    int count = 1; // Variable auxiliar
    for (unsigned int i = 1; i < numMonedasUsadas.size(); i++) { // Recorremos el vector de monedas usadas
        if (numMonedasUsadas[i] == current) { // Si la moneda es igual a la anterior
            count++; // Aumentamos el contador
        } else {
            cout << count << " moneda(s) de " << current << endl; // Imprimimos el número de monedas y su valor
            current = numMonedasUsadas[i]; // Actualizamos la moneda actual
            count = 1; // Reiniciamos el contador
        }
    }
    cout << count << " moneda(s) de " << current << endl; // Imprimimos el número de monedas y su valor
}

int main(){
    int numMonedas;
    cout << "Ingrese el numero de monedas: ";
    cin >> numMonedas;

    int numeros[numMonedas]; // Arreglo que guarda los valores de las monedas

    for(int i = 0; i < numMonedas; i++){ // Recorremos el arreglo de monedas
        cout << "Ingrese el valor de la moneda " << i+1 << ": ";
        cin >> numeros[i]; // Guardamos el valor de la moneda
    }

    // Pedimos el precio del producto y el billete o moneda con el que se va a pagar
    int P;
    cout << "Ingrese el precio del producto: ";
    cin >> P;

    int Q;
    cout << "Ingrese el billete o moneda con el que vas a pagar: ";
    cin >> Q;

    int cambio = Q-P; // Calculamos el cambio

    vector<int> Greedy = minNumMonGR(cambio, numeros, numMonedas); // Vector que guarda las monedas usadas con Greedy
    vector<int> Dynamic = minNumMonDP(cambio, numeros, numMonedas); // Vector que guarda las monedas usadas con Programación Dinámica

    // Imprimimos las respuestas
    cout << "Usando Greedy:" << endl;
    escribeRespuesta(Greedy);

    cout << "Usando Programacion Dinamica:" << endl;
    escribeRespuesta(Dynamic);

    return 0;
}
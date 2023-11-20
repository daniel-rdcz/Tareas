// José Daniel Rodríguez Cruz
// 19/11/2023

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

// Definición del tamaño del laberinto
#define N 4

// Definición de las direcciones posibles del movimiento
const int dx[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
const int dy[] = {0, 1, 0, -1};

// Clase para representar un estado en el laberinto
class State {
public:
    int x, y, cost, heuristic;
    string path;

    State(int x, int y, int cost, int heuristic, string path) : x(x), y(y), cost(cost), heuristic(heuristic), path(path) {}

    // Función para comparar estados basados en la suma de costo y heurística
    bool operator>(const State &other) const {
        return cost + heuristic > other.cost + other.heuristic;
    }
};

// Función de heurística (distancia Manhattan)
int calculateHeuristic(int x, int y) {
    return abs(x - (N - 1)) + abs(y - (N - 1));
}

// Función para verificar si una posición está dentro del laberinto y es accesible
bool isValid(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y];
}

// Función auxiliar para obtener la dirección correspondiente
string getDirection(int i) {
    if (i == 0) return "U";
    else if (i == 1) return "R";
    else if (i == 2) return "D";
    else return "L";
}

// Función principal para resolver el laberinto utilizando A*
vector<string> solveMaze(vector<vector<int>> &maze) {
    priority_queue<State, vector<State>, greater<State>> pq; // Min-heap para priorizar el menor costo total
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<string> solutions;

    // Inicialización del punto de inicio
    int startX = 0, startY = 0;
    pq.push(State(startX, startY, 0, calculateHeuristic(startX, startY), ""));

    while (!pq.empty()) {
        // Obtener el estado con menor costo total
        State current = pq.top();
        pq.pop();

        // Marcar la posición actual como visitada
        visited[current.x][current.y] = true;

        // Verificar si hemos alcanzado el destino
        if (current.x == N - 1 && current.y == N - 1) {
            solutions.push_back(current.path);
            // No detenemos la búsqueda al encontrar una solución, para encontrar todas las soluciones posibles.
        }

        // Generar sucesores y agregarlos a la cola de prioridad
        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, maze, visited)) {
                pq.push(State(newX, newY, current.cost + 1, calculateHeuristic(newX, newY), current.path + getDirection(i)));
            }
        }
    }

    return solutions;
}

int main() {
    // Definir el laberinto
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    // Resolver el laberinto y mostrar las soluciones
    vector<string> solutions = solveMaze(maze);
    reverse(solutions.begin(), solutions.end());

    // Imprimir todas las soluciones encontradas
    for (const string &solution : solutions) {
        cout << solution << endl;
    }

    return 0;
}

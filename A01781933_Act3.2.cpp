// José Daniel Rodríguez Cruz A01781933

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;   

// definir el valor infinito como el máximo valor de un int
#define INF numeric_limits<int>::max()

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    // inicializar los nodos en 0 e infinito
    int n = graph.size();  
    vector<int> distance(n, INF);
    distance[start] = 0;

    // inicializar todos los nodos como no visitados
    vector<bool> visited(n, false);

    // encontrar el camino más corto para todos los nodos
    for (int i = 0; i < n - 1; ++i) {
        int minDistance = INF;
        int u = -1;

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                u = j;
            }
        }

        // marcar el nodo como visitado
        visited[u] = true;

        // actualizar la distancia de los nodos adyacentes
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // imprimir el resultado
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            cout << "Node " << start + 1 << " to Node " << i + 1 << " : " << distance[i] << endl;
        }
    }
}

void floyd(const vector<vector<int>>& adjacencyMatrix) {
    // inicializar la matriz de distancias
    int n = adjacencyMatrix.size();
    vector<vector<int>> distance = adjacencyMatrix;

    // encontrar el camino más corto para todos los nodos
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // imprimir el resultado
    cout << "\nFloyd:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}

// leer el grafo desde un archivo
void readGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int n, m;
        file >> n >> m;

        vector<vector<pair<int, int>>> graph(n);
        vector<vector<int>> adjacencyMatrix(n, vector<int>(n, INF));

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            file >> a >> b >> c;
            graph[a].push_back({b, c});
            adjacencyMatrix[a][b] = c;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    adjacencyMatrix[i][j] = 0;
                }
            }
        }

        cout << "Dijkstra:" << endl;
        for (int i = 0; i < n; ++i) {
            dijkstra(graph, i);
        }

        floyd(adjacencyMatrix);

        file.close();
    } else {
        cerr << "Unable to open the file." << endl;
    }
}

int main() {
    string filename = "input.txt";
    readGraphFromFile(filename);

    return 0;
}

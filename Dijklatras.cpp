#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
public:
    unordered_map<int, vector<pii>> adjList;

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); 
    }
};

vector<int> dijkstra(Graph& graph, int initial) {
    vector<int> shortestDistance(graph.adjList.size(), INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;

    shortestDistance[initial] = 0;
    minHeap.push(make_pair(0, initial));

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        for (auto neighbor : graph.adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (shortestDistance[v] > shortestDistance[u] + weight) {
                shortestDistance[v] = shortestDistance[u] + weight;
                minHeap.push(make_pair(shortestDistance[v], v));
            }
        }
    }

    return shortestDistance;
}

int main() {
    Graph graph;
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    int initial, final;
    cin >> initial >> final;

    vector<int> distances = dijkstra(graph, initial);

    if (distances[final] == INT_MAX) {
        cout << "No path exists between " << initial << " and " << final << endl;
    } else {
        cout << "Shortest distance between " << initial << " and " << final << ": " << distances[final] << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj; 

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   
    bool isBipartite() {
        vector<int> color(V, -1); 

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { 
                queue<int> q;
                q.push(i);
                color[i] = 0; 
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; 
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; 
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {

    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    bool isBipartite = graph.isBipartite();

    if (isBipartite) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w);

    void dfs(int v);
    void bfs(int start);
};

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::dfs(int v) {
  visited[v] = true;
  cout << v << " ";
  
  for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i])
      dfs(*i);
  }
}

void Graph::bfs(int v) {
  queue<int> q;
  q.push(v);
  visited.clear();

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    if (!visited[current]) {
      cout << current << " ";
      visited[current] = true;
      for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
          q.push(neighbor);
        }
      }
    }
  }
}

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout << "Depth first traversal: \n";
    graph.dfs(2);

    cout << "\n\n";
    
    cout << "Breath first traversal: \n";
    graph.bfs(0);

    cout << "\n\n";
}

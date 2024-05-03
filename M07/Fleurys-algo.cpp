#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>
#include <string>

class Graph {
    int v;
    std::list<int> *adj;
public:
  Graph(int v) {
    this->v = v;
    adj = new std::list<int>[v];
  }
  
  ~Graph() { delete[] adj; }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void remove_edge(int u, int v);

  void print_euler_tour();
  void print_euler_util(int);

  int dfs_count(int v, bool visited[]);

  bool is_valid_next_edge(int u, int v);
};

void Graph::print_euler_tour() {
  int u = 0;
  for (int i = 0; i < v; i++) {
    if (adj[i].size() & 1) {
      u = i;
      break;
    }
  }

  std::cout << u << '\n';
  print_euler_util(u);
  std::cout << '\n';
}

void Graph::print_euler_util(int u) {
  std::list<int>::iterator it;
  for (it = adj[u].begin(); it != adj[u].end(); ++it) {
    int v = *it;

    if (v != -1 && is_valid_next_edge(u, v)) {
      std::cout << u << "-" << v << "  ";
      //remove_edge(u, v);
      //print_euler_util(v);
    }
  }
}

bool Graph::is_valid_next_edge(int u, int v) {
  int count = 0;
  std::list<int>::iterator it;
  for (it = adj[u].begin(); it != adj[u].end(); ++it) {
    if (*it != -1) {
      count++;
    }
  }
  if (count == 1) {
    return true;
  }

  bool visited[v];
  memset(visited, false, v);
  int count1 = dfs_count(u, visited);

  remove_edge(u, v);
  memset(visited, false, v);
  int count2 = dfs_count(u, visited);

  add_edge(u, v);

  return (count1 > count2) ? false : true;
}

void Graph::remove_edge(int u, int v) {
  std::list<int>::iterator it = find(adj[u].begin(), adj[u].end(), v);
  *it = -1;

  std::list<int>::iterator it1 = find(adj[v].begin(), adj[v].end(), u);
  *it1 = -1;
}

int Graph::dfs_count(int v, bool visited[]) {
  visited[v] = true;
  int count = 1;

  std::list<int>::iterator it;
  for (it = adj[v].begin(); it != adj[v].end(); ++it) {
    if (*it != -1 && !visited[*it]) {
      count += dfs_count(*it, visited);
    } 
  }
  return count;
}

int main() {
  Graph graph(4);
  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(1, 2);
  graph.add_edge(2, 3);
  graph.print_euler_tour();
}

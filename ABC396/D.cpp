/*
===========================================
  Problem: AtCoder Beginner Contest 396 D
  Name: Minimum XOR Path
  Link: https://atcoder.jp/contests/abc396/tasks/abc396_d
  Date: 2025/06/13
  Language: C++
  Description:
    Find the path from node 1 to N with the minimum XOR sum of edge weights.

  Note:
    - Brute-force DFS approach
    - Not efficient for large N due to time complexity
===========================================
*/
using namespace std;
#include <iostream>
#include <vector>
#define ull unsigned long long
#define INF 2e18
ull minXOR = INF;

class Node{
public:
  int vertice;
  ull edge;
};

ull print_path(const vector<Node> path,const int N){  
  ull XOR = 0;
  for(auto &x:path) XOR = XOR xor x.edge;
  if(path.empty()) cout << "No path!" << endl;
  return XOR;
}

void dfs(vector<vector<Node>> &graph,const int N, Node node,vector<Node> &path,vector<bool> &vis){

  if(node.vertice == N) {
    minXOR = min(print_path(path, N), minXOR); 
    return;
  }
  
  for(auto &n : graph[node.vertice]){
    if(!vis[n.vertice]) {
      vis[n.vertice] = true;
      path.push_back(n);
      dfs(graph, N, n, path,vis);
      vis[n.vertice] = false;
      path.pop_back();
    }    
  }  
}

int main(){
  vector<vector<Node>> graph;
  int N,M; cin >> N >> M;
  
  graph.resize(N + 1);

  for(int i=0;i<M;i++){
    int v,u; cin >> v >> u;
    ull edge; cin >> edge;
    Node node1,node2;
    node1.vertice = u; node1.edge = edge;
    node2.vertice = v; node2.edge = edge;
    graph[v].push_back(node1);
    graph[u].push_back(node2);

  }
  Node start;
  start.vertice = 1; start.edge = 0;
  graph[0].push_back(start);

  for(auto &n : graph[0]){
    vector<Node> path;
    vector<bool> vis(N+1,false);
    path.clear();
    vis[1] = true;
    dfs(graph, N, n, path, vis);       
  }
  
  cout << minXOR << endl;
}


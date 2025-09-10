vector<bool> vis;
void dfs(int start, vector<vector<int>> & adj, int v){
  // v = Vertices
  stack<int> s;
  s.push(start);
  vis[start] = true;
  int cont = 1;
  while (!(s.empty())){
    int prox = s.top();
    if(!(adj[prox].empty())){
      if(vis[adj[prox].back()] == false){
        vis[adj[prox].back()] = true;
        s.push(adj[prox].back());
      }
      else{
        adj[prox].pop_back();
      }
    }
    else{
      s.pop();
    }
  }
}
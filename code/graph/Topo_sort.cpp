// Para que exista un orden topologico
// el grafo tiene que ser DAG(grafo aciclico dirigido)
vi g[nax], ts;
bool seen[nax];
void dfs(int u){
  seen[u] = true;
  for(int v: g[u])
    if (!seen[v])
      dfs(v);
  ts.pb(u);
}
void topo(int n){
  forn(i,n) if (!seen[i]) dfs(i);
  reverse(all(ts));
}

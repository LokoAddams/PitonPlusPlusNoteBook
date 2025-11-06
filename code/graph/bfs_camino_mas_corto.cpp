 // inside int main()---no recursion
 vi dist(V, INF); dist[s] = 0; // initial distances
 queue<int> q; q.push(s);  // start from source
 while (!q.empty()) { // queue: layer by layer!
    int u = q.front(); q.pop(); // C++17 style, w ignored
    for (auto &[v, w] : AL[u]) {
    if (dist[v] != INF) continue;// ALREADY VISITED, skip
    dist[v] = dist[u]+1;// now set dist[v] != INF
    q.push(v);// for the next iteratio
    }
 }
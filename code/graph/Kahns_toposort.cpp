// enqueue vertices with zero incoming degree into a (priority) queue pq
priority_queue<int, vi, greater<int>> pq;    // min priority queue
for (int u = 0; u < N; ++u)
  if (in_degree[u] == 0)                     // next to be processed
    pq.push(u);                              // smaller index first

while (!pq.empty()) {                        // Kahn's algorithm
  int u = pq.top(); pq.pop();
  printf(" %s", u);   // process u here
  for (auto &v : AL[u]) {
    --in_degree[v];                          // virtually remove u->v
    if (in_degree[v] > 0) continue;          // not a candidate, skip
    pq.push(v);                              // enqueue v in pq
  }
}

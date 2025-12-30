#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>; // (peso_acumulado, nodo)

vector<ll> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& adj) 
{
    vector<ll> dist(n, 1e18); // Inicializar con "infinito"
    dist[start] = 0;

    // Min-Priority Queue
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
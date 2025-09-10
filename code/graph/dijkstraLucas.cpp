vector<long long> dist;
struct cmp {
    bool operator()(const pair<int, long long>& a, const pair<int, long long>& b) const {
        return a.second > b.second;
    }
};
priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> q;

void dijkstra(int n, vector<vector<pair<int,long long>>> &adj, int src)
{
    dist.resize(n+1, -1);
    dist[src] = 0;
    q.push({src,0});
    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        if (u.second > dist[u.first]) 
        {
            continue; // Ya encontramos un camino mas corto a 'u', ignoramos este.
        }
        for (auto v : adj[u.first])
        {
            if (dist[v.first] > dist[u.first] + v.second or dist[v.first] == -1)
            {
                dist[v.first] = dist[u.first] + v.second;
                q.push({v.first, dist[v.first]});
            }
            
        }
    }
    true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int u, v;
    long long p;
    vector<vector<pair<int,long long>>> adj(n+1);//nodo destino, peso
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> p;
        adj[u].push_back({v,p});
    }
    dijkstra(n, adj, 1);// desde nodo origen a todos los demas
    for (int i = 1; i <= n; ++i)
    {
        cout << dist[i] << " ";
    }
    return 0;
}

// Realiza una BFS desde el nodo `src` en un grafo dirigido o no dirigido
// representado como lista de adyacencia.
// Parametros:
//   n   : numero de nodos (0 .. n-1)
//   adj : vector de vectores, donde adj[u] contiene todos los v tales que u -> v
//   src : nodo de partida
// Devuelve:
//   true si es bipartito y false si no lo es
bool bfs(int n, vector<pair<vector<int>, char>> &adj, int src)
{
    queue<int> q;
    q.push(src);
    char decision = 'a';
    bool bipartito = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (adj[u].second == 'c')
        {
            adj[u].second = decision;
        }
        if (adj[u].second == 'a')
            decision = 'b';
        else
            decision = 'a';

        for (int v : adj[u].first)
        {
            if (adj[v].second == 'c')
            {
                q.push(v);
                adj[v].second = decision;
            }
            if (adj[u].second == adj[v].second)
            {
                bipartito = false;
                break;
            }
        }
    }

    return bipartito;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    // Leer numero de nodos y aristas
    cin >> n >> m;
    // Construir lista de adyacencia
    vector<pair<vector<int>, char>> adj(n);
    // a= 1er conjunto
    // b = 2do
    // c = sin conjunto
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].first.push_back(v);
        adj[v].first.push_back(u);
    }
    // inicializacion en c para saber si no esta explorado
    for (int i = 0; i < n; i++)
        adj[i].second = 'c';

    bool es_bipartito = true;
    // Iterar por todos los nodos para manejar grafos no conexos
    for (int i = 0; i < n; ++i)
    {
        // Si el nodo 'i' no ha sido coloreado, iniciar un BFS desde el
        if (adj[i].second == 'c')
        {
            // Si cualquier componente no es bipartita, el grafo entero no lo es
            if (!bfs(n, adj, i))
            {
                es_bipartito = false;
                break; // Podemos detenernos en cuanto encontramos un fallo
            }
        }
    }
    cout << "res: " << es_bipartito << endl;
    return 0;
}

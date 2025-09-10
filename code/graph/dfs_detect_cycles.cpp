vector<vector<int>> adj(5);
int n;
vector<char> state(5);
/*
a = no visitado
b = visitando
c = visitado
*/

bool dfs_detect_cycle(int node)
{
    if(state[node] == 'b')
        return true;
    state[node] = 'b';
    for(auto i: adj[node])
    {
        if(dfs_detect_cycle(i))
        {
            return true;
        }
    }
    state[node] = 'c';
    return false;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    n = 5;
    adj[1].push_back(2);
    // Componente 2 (con ciclo)
    adj[3].push_back(4);
    adj[4].push_back(0);
    // adj[0].push_back(3); // CON ESTO SI HAY CICLO

    form(i,0,5) state[i] = 'a';
    int i;
    for( i=0;i < 5; i++)
    {
        if(state[i] == 'a')
            if(dfs_detect_cycle(i))
            {
                cout << "Hay ciclo" << endl;
                return 0;
            }
    }
    if(i == 5) 
        cout << "NO hay ciclo" << endl;

    return 0;
}

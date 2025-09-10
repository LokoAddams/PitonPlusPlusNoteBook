struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return ((long long)p.first << 32) ^ p.second;
    }
};

int main() 
{
  unordered_map<pair<int,int>, int, pair_hash> edge_cost;
  edge_cost.reserve(1e6);
  //Muy usado para representar grafos dispersos.
  edge_cost[{1,2}] = 5;
  edge_cost[{2,3}] = 10;

  cout << edge_cost[{1,2}] << "\n"; // 5
}

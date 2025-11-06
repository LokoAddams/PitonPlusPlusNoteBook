vector<int> vals = {1000, 5000, 1000, 42};
unordered_map<int,int> comp;
comp.reserve(vals.size()*1.33);

int id = 0;
for (int v : vals)
    if (!comp.count(v)) 
      comp[v] = id++;
/*
  Antes -> Ahora
  1000 = 1
  5000 = 2
  42 = 3
*/

for (int v : vals)
    cout << v << " -> " << comp[v] << "\n";

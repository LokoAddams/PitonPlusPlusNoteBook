int n; 
cin >> n;
vector<int> arr(n);
for (int &x : arr) 
  cin >> x;

unordered_map<int,int> freq;//<clave, valor>
freq.reserve(n*1.33); // evita rehash

for (int x : arr) 
  freq[x]++;

for (auto &p : freq)
    cout << p.first << " aparece " << p.second << " veces\n";

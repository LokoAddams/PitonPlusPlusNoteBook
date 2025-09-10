int main() {
  int n = 3e5;
  vi a = {1,2,3,42,42,42};
  unordered_set<int> s;//<T>
  s.reserve(n * 1.3);// evita rehash

  //insert(T)
  for (int x : a) 
    s.insert(x);

  //VERIFICAR EXISTENCIA
  if (s.find(42) != s.end())
    cout << "42 existe" << endl;
    
  //Iterar para ver claves existentes
  for(auto x : s)
    cout << x << " ";
    
  return 0;
}
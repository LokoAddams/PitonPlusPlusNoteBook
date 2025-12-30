class Node{
public:
  int nodo = -1, f = 0;
  Node();
  bool operator<(const Node& other) const {
    if (f != other.f) return f < other.f;
    return nodo < other.nodo;
  }

};
sort(aux.begin(), aux.end());//menor a mayor
sort(aux.rbegin(), aux.rend());//mayor a menor


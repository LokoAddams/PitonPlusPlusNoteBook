struct Node {
  int id;
};
// si la funcion devuelve true, a tiene menor prioridad que b
struct cmp {
  bool operator()(const Node& a, const Node& b) const {
    return a.id < b.id;
  }
};

priority_queue<Node, vector<Node>, cmp> pq;// max-heap por id

int main(){
  priority_queue<int, vector<int>> pq_min;// por defecto es max-heap
  priority_queue<int, vector<int>, greater<int>> pq_min;// min-heap
  // Create O(n)
  vector<int> d = {12,3,4,3,3,5,34,343,5325,235,23452,3532};
  priority_queue<int> a (d.begin(), d.end());
  // Create O(n * log n)
  vector<int> d = {12,3,4,3,3,5,34,343,5325,235,23452,3532};
  priority_queue<int> a;
  for(auto i: d)
      a.push(i);
  return 0;
}
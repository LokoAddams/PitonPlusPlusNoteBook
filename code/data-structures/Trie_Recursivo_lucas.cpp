struct Node
{
  Node* sig_cero = NULL;Node* sig_uno = NULL;
  int cont_cero = 0, cont_uno = 0;
};

class Trie
{
private:
  Node* r;
  void Add(Node*& node, int i)
  {
    if(i > 63) return;
    if(node == NULL) node = new Node();
    if(last_num[i] == '0')
    {
      node->cont_cero++;
      Add(node->sig_cero, i+1);
    }
    else
    {
      node->cont_uno++;
      Add(node->sig_uno, i+1);
    }
  }
  
  void Delete(Node*& node, int i)
  {
    if(i > 63) return;
    if(node == NULL) node = new Node();
    if(last_num[i] == '0')
    {
      node->cont_cero--;
      Delete(node->sig_cero, i+1);
    }
    else
    {
      node->cont_uno--;
      Delete(node->sig_uno, i+1);
    }
  }
  
  void Max_xor(Node*& node, int i)
  {
    if(i > 63) 
    return;
    if(node == NULL) 
    return;
    if(last_num[i] == '0')
    {
      if(node->cont_uno > 0)
      {
        ans.pb('1');
        Max_xor(node->sig_uno, i+1);
      }
      else
      {
        ans.pb('0');
        Max_xor(node->sig_cero, i+1);
      }
    }
    else
    {
      if(node->cont_cero > 0)
      {
        ans.pb('0');
        Max_xor(node->sig_cero, i+1);
      }
      else
      {
        ans.pb('1');
        Max_xor(node->sig_uno, i+1);
      }
    }
  }
  public:
  string ans;
  string last_num;
  Trie()
  {
    r = new Node();
  }
  
  void add(int x)
  {
    this->last_num = numtobin(x);//128 bits
    Add(r, 0);
  }
  void deletee(int x)
  {
    this->last_num = numtobin(x);//128 bits
    Delete(r, 0);
  }
  void max_xor(int x)
  {
    this->last_num = numtobin(x);//128 bits
    ans.clear();
    Max_xor(r, 0);
  }
};


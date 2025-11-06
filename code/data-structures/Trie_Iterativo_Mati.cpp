

struct nodo {
  nodo* hijos[2];
  int cont;

  nodo() {
    hijos[0] = hijos[1] = nullptr;
    cont = 0;
  }
};

class ArbolBin {
private:

nodo* raiz;

void borrarNodo(nodo* n) {
  if(!n) return;

  borrarNodo(n->hijos[0]);
  borrarNodo(n->hijos[1]);
  delete n;
}

public:

ArbolBin() {
  raiz = new nodo();
}

~ArbolBin() {
  borrarNodo(raiz);
}


void insertar(int x) {
  nodo* nodoActual = raiz;
  int bitActual;
  for(int i = MB - 1; i >= 0; i--) {
    bitActual = (x>>i) & 1;

    if(nodoActual->hijos[bitActual] == nullptr) {
      nodoActual->hijos[bitActual] = new nodo();
    }

    nodoActual = nodoActual->hijos[bitActual];

    nodoActual->cont++;
  }
}

void borrar(int x) {
  nodo* nodoActual = raiz;
  int bitActual;
  for(int i = MB - 1; i >= 0; i--) {
    bitActual = (x>>i) & 1;

    nodoActual = nodoActual->hijos[bitActual];

    nodoActual->cont--;
  }
}

int consulta(int x) {
  nodo* nodoActual = raiz;
  int bitDeseado, res = 0;
  for(int i = MB - 1; i >= 0; i--) {
    bitDeseado = ((x>>i) & 1)^1;

    if(nodoActual->hijos[bitDeseado] != nullptr and nodoActual->hijos[bitDeseado]->cont > 0) {
      res = res|(1<<i);
    }
    else {
      bitDeseado = bitDeseado^1;
    }

    nodoActual = nodoActual->hijos[bitDeseado];
  }

  return res;
}

};



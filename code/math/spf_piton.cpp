const int MAX_A = 1000000;
vector<int> spf;//spf Smallest Prime Factor
/*
Construimos un vector hasta MAX_A que será el numero mas grande
que factorizemos.
Si queremos factorizar 20 haremos:
spf[20] = 2
spf[20/2] = spf[10] = 2
spf[10/2] = spf[5] = 5
spf[5/5] = spf[1] = 1

20 = 2*2*5*1
*/
void build_spf() {
    spf.resize(MAX_A + 1);
    for (int i = 1; i <= MAX_A; i++)
        spf[i] = i;
    for (int i = 2; i * i <= MAX_A; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX_A; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

/*
Este es un ejemplo que tiene el objetivo de crear 
set sin factores primos repetidos, por ejemplo, para 20
20 = 2*2*5*1 = el set que obtendremos será {2,5}

Este ejemplo es util para recorrer spf
*/
set<int> factorize(int x) {
    set<int> primes;
    while (x > 1) {
        int p = spf[x];
        primes.insert(p);
        while (x % p == 0)
            x /= p;
    }
    return primes;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    build_spf(); // NO OLVIDAAAR

    return 0;
}

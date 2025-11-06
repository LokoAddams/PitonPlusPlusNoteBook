multimap<int,string> mm;

// insertar pares (clave, valor)
mm.insert({1, "uva"});
mm.insert({2, "manzana"});
mm.insert({2, "pera"});
mm.insert({3, "melon"});

// Iterar (se imprime ordenado por clave)
for (auto &p : mm)
    cout << p.first << " -> " << p.second << "\n";
/*
1 -> uva
2 -> manzana
2 -> pera
3 -> melon
*/
multimap<int,string> mm;
// insertar pares (clave, valor)
mm.insert({1, "uva"});
mm.insert({2, "manzana"});
mm.insert({2, "pera"});
mm.insert({3, "melon"});

// Buscar la primera aparicion de clave 2
auto it = mm.find(2);
if (it != mm.end())
    cout << "Encontrado: " << it->second << "\n";

// Contar cuantos con clave=2
cout << "Claves con 2: " << mm.count(2) << "\n";

// Obtener todos los con clave=2
auto [ini, fin] = mm.equal_range(2);
for (auto it = ini; it != fin; ++it)
    cout << it->second << " ";
/*
SALIDA
Encontrado: manzana
Claves con 2: 2
manzana pera
*/
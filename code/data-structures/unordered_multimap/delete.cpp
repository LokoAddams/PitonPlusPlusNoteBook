mm.erase(2);  // borra *todas* las entradas con clave=2

// Si quieres borrar solo uno:
auto it = mm.find(2);
if (it != mm.end()) 
  mm.erase(it);

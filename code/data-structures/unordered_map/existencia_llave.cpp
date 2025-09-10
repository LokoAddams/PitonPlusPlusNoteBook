unordered_map<string,int> id;
id.reserve(1e5);

id["uva"] = 10;
id["manzana"] = 20;

// Con count
if (id.count("uva")) cout << "uva existe\n";


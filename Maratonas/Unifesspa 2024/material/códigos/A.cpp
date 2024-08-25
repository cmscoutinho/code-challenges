#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	map<int, string> prod;

	prod.insert(pair<int,string>(0, "Mouse"));
	prod.insert(pair<int,string>(1, "Teclado"));
	prod.insert(pair<int,string>(2, "Monitor"));
	prod.insert(pair<int,string>(3, "Caixa de som"));
	
	prod.
//	prod[0] = "Mouse";
//	prod[1] = "Teclado";
//	prod[2] = "Monitor";
//	prod[3] = "Caixa de som";
	
//	for (int i = 0; i < 4; i++)
//		cout << prod[i] << endl;

	
//	for (ite = prod.begin(); ite != prod.end(); ite++)
//		cout << ite->first << endl;
	
	for(auto ite:prod)
		cout << ite.second << endl;
	
	return 0;
}


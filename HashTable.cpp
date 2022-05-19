/** ******************************************************************
 Atividade - Tabela Hash
 Estrutura de Dados II

 GRUPO

 Nome: Gabriela Lopes Francisco
 TIA: 31744591

 Nome: Giulia Barbieri Quagliano
 TIA: 42013070

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Lucas Martins de Souza
 TIA: 31943187
****************************************************************** */

#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    list<int> *table;
    int total_elements;

    // Hash function to calculate hash for a value:
    int getHash(int key) {
        return key % total_elements;
    }

public:
 
   int colisoes;  //contador de colisões

  // Constructor to create a hash table with 'n' indices:
  HashTable(int n){
    total_elements = n;
    table = new list<int>[total_elements];
  }

  // Insert data in the hash table:
  void insertElement(int key){
    if(table[getHash(key)].size()>=1){
      colisoes+=1;
    }  //verifica se a posição já está ocupada. Se estiver, ocorreu uma colisão e somamos 1 às colisões
    
    table[getHash(key)].push_back(key); //Add element at the end
  }

    // Remove data from the hash table:
    void removeElement(int key) {
        int x = getHash(key);

        list<int>::iterator i;
        for (i = table[x].begin(); i != table[x].end(); i++) {
            // Check if the iterator points to the required item:
            if (*i == key)
                break;
        }

        // If the item was found in the list, then delete it:
        if (i != table[x].end())
            table[x].erase(i); //Erase elements
    }

    void printAll() {
        // Traverse each index:
        for (int i = 0; i < total_elements; i++) {
            cout << "Index " << i << ": ";
            // Traverse the list at current index:
            for (int j: table[i])
                cout << j << " => ";

            cout << endl;
        }
    }
};

int main() {
    // Create a hash table with x indices:
    HashTable ht(9);

    // Declare the data to be stored in the hash table:
    int array[] = {2, 4, 6, 8, 10, 1, 21, 13, 15, 9, 12, 30, 7, 17, 24, 45, 41, 32, 38, 39, 35, 26, 27, 50, 55, 52};

    // Insert the whole data into the hash table:
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        ht.insertElement(array[i]);

    cout << "\n..:: Hash Table ::.." << endl;
    ht.printAll();

    ht.removeElement(1);
    cout << endl << "..:: After deleting element 1 ::.." << endl;
    ht.printAll();

  cout << "\nTotal de colisões: " << ht.colisoes << endl;

    return 0;
}
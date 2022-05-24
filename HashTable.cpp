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

    /** Hash function to calculate hash for a value: */
    int getHash(int key) const {
        return key % total_elements;
    }

public:

    int collisionCount = 0;

    /** Constructor to create a hash table with 'n' indices: */
    explicit HashTable(int n) {
        total_elements = n;
        table = new list<int>[total_elements];
    }

    /** Insert data in the hash table: */
    void insertElement(int key) {
        if (!table[getHash(key)].empty()) {
            collisionCount += 1;
        } /** Checks if the position is already occupied. If a collision has occurred and we add 1 to the collisionCount */

        table[getHash(key)].push_back(key); /** Add element at the end */
    }

    /** Remove data from the hash table: */
    void removeElement(int key) {
        int x = getHash(key);

        list<int>::iterator i;
        for (i = table[x].begin(); i != table[x].end(); i++) {
            /** Check if the iterator points to the required item: */
            if (*i == key)
                break;
        }

        /** If the item was found in the list, then delete it: */
        if (i != table[x].end())
            table[x].erase(i);
    }

    void printAll() {
        /** Traverse each index: */
        for (int i = 0; i < total_elements; i++) {
            cout << "Index " << i << ": ";
            /** Traverse the list at current index: */
            for (int j: table[i])
                cout << j << " => ";

            cout << endl;
        }
    }

    float getAverageLengthOfLists() {
        float soma;
        int count;
        count = 0;

        for (int i = 0; i < total_elements; i++) {
            count = count + 1;
            soma = soma + table[i].size();
        }
        return soma / count;
    }

};

int main() {
    /** Create a hash table with x indices: */
    HashTable hashTable(9);

    /** Declare the data to be stored in the hash table: */
    int array[] = {2, 4, 6, 8, 10, 1, 21, 13, 15, 9, 12, 30, 7, 17, 24, 45, 41, 32, 38, 39, 35, 26, 27, 50, 55, 52};

    /** Insert the whole data into the hash table: */
    for (int i: array)
        hashTable.insertElement(i);

    cout << "\n..........:: Hash Table ::............\n" << endl;
    hashTable.printAll();

    hashTable.removeElement(1);
    cout << endl << "\n....:: After deleting element 1 ::....\n" << endl;
    hashTable.printAll();

    cout << "\n.........:: Collisions ::............" << endl;
    cout << "\nTotal collisions: " << hashTable.collisionCount << endl;

    cout << "\n..........:: Average ::............." << endl;
    cout << "\nAverage size of lists: " << hashTable.getAverageLengthOfLists() << endl;

    return 0;
}
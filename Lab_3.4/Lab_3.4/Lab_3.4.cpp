#include <iostream>
#include <vector>
#include "Factory.h"

using namespace std;

int main() {
    vector<SymString*> objects;
    int choice;

    do {
        cout << "\n1. Create SymString";
        cout << "\n2. Create BinString";
        cout << "\n3. Show all";
        cout << "\n4. ShowHex all";
        cout << "\n5. Add two objects";
        cout << "\n6. Delete last";
        cout << "\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            string id, val;
            cout << "Enter id: " << endl;
            cin >> id;
            cout << "Enter value: " << endl;
            cin >> val;
            objects.push_back(Factory::createSym(id, val));
        }

        else if (choice == 2) {
            string id, val;
            cout << "Enter id: " << endl;
            cin >> id;
            cout << "Enter binary: " << endl;
            cin >> val;
            objects.push_back(Factory::createBin(id, val));
        }

        else if (choice == 3) {
            for (auto obj : objects)
                obj->Show();
        }

        else if (choice == 4) {
            for (auto obj : objects)
                obj->ShowHex();
        }

        else if (choice == 5 && objects.size() >= 2) {
            SymString* a = objects[objects.size() - 1];
            SymString* b = objects[objects.size() - 2];

            SymString result = (*a + *b);
            result.Show();
        }

        else if (choice == 6 && !objects.empty()) {
            Factory::destroy(objects.back());
            objects.pop_back();
        }

    } while (choice != 0);

    for (auto obj : objects)
        delete obj;

    return 0;
}
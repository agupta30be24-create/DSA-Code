#include <iostream>
#include <list>
using namespace std;

void display(list<int> &l) {
    for (int x : l) cout << x << " ";
    cout << endl;
}

void insertNode(list<int> &l, int pos, int val) {
    if (pos <= 1) l.push_front(val);
    else if (pos > l.size()) l.push_back(val);
    else {
        auto it = l.begin();
        advance(it, pos - 1);
        l.insert(it, val);
    }
}

void deleteNode(list<int> &l, int val) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (*it == val) {
            l.erase(it);
            break;
        }
    }
}

void searchNode(list<int> &l, int val) {
    int i = 1, found = 0;
    for (int x : l) {
        if (x == val) {
            cout << "Found at position " << i << endl;
            found = 1;
            break;
        }
        i++;
    }
    if (!found) cout << "Not found" << endl;
}

int main() {
    list<int> l;
    int ch, val, pos;
    while (1) {
        cout << "1.Insert 2.Delete 3.Search 4.Display 5.Exit\n";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter position and value: ";
            cin >> pos >> val;
            insertNode(l, pos, val);
        } else if (ch == 2) {
            cout << "Enter value to delete: ";
            cin >> val;
            deleteNode(l, val);
        } else if (ch == 3) {
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(l, val);
        } else if (ch == 4) display(l);
        else break;
    }
}

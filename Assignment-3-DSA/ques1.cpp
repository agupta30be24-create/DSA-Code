#include <iostream>
using namespace std;

int main() {
    const int MAX = 5;
    int stack[MAX], top = -1, choice, val;

    do {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // push
            if (top == MAX - 1) cout << "Stack Overflow!\n";
            else {
                cout << "Enter value: ";
                cin >> val;
                stack[++top] = val;
            }
            break;

        case 2: // pop
            if (top == -1) cout << "Stack Underflow!\n";
            else cout << "Popped: " << stack[top--] << endl;
            break;

        case 3: // peek
            if (top == -1) cout << "Stack Underflow!\n";
            else cout << "Top: " << stack[top] << endl;
            break;

        case 4: // display
            if (top == -1) cout << "Stack Underflow!\n";
            else {
                cout << "Stack: ";
                for (int i = top; i >= 0; i--)
                    cout << stack[i] << " ";
                cout << endl;
            }
            break;
        }
    } while (choice != 5);

    return 0;
}

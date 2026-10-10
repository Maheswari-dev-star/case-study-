#include <iostream>
#include <string>
using namespace std;

struct Node {
    string item;
    Node* next;
};

Node* head = NULL;

void addItem(string item) {
    Node* n = new Node{item, NULL};
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    cout << item << " added.\n";
}

void removeItem(string item) {
    Node *t = head, *prev = NULL;
    while (t && t->item != item) { prev = t; t = t->next; }
    if (!t) { cout << "Item not found.\n"; return; }
    if (!prev) head = t->next;
    else prev->next = t->next;
    delete t;
    cout << item << " removed.\n";
}

void searchItem(string item) {
    Node* t = head;
    int pos = 1;
    while (t) {
        if (t->item == item) {
            cout << item << " found at position " << pos << ".\n";
            return;
        }
        t = t->next; pos++;
    }
    cout << item << " not found.\n";
}

void displayItems() {
    if (!head) { cout << "List is empty.\n"; return; }
    Node* t = head;
    int i = 1;
    cout << "Shopping List:\n";
    while (t) {
        cout << i++ << ". " << t->item << endl;
        t = t->next;
    }
}

int main() {
    int choice;
    string item;
    do {
        cout << "\n1.Add 2.Remove 3.Search 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Item: "; cin >> item; addItem(item); break;
            case 2: cout << "Item: "; cin >> item; removeItem(item); break;
            case 3: cout << "Item: "; cin >> item; searchItem(item); break;
            case 4: displayItems(); break;
            case 5: cout << "Bye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}
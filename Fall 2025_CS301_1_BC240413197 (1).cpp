#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

class Node {
private:
    string book;
    Node* next;
public:
    Node() : book(""), next(NULL) {}
    void setBook(string b) { book = b; }
    void setNext(Node* ptr) { next = ptr; }
    string getBook() const { return book; }
    Node* getNext() const { return next; }
};

// Stack Class implemented using Linked List
class Stack {
private:
    Node* top;  // points to top of stack
public:
    Stack() { top = NULL; }

    // TODO 1: Implement the pushBook function
    void pushBook(string b) {
        Node* newNode = new Node();
        newNode->setBook(b);
        newNode->setNext(top);
        top = newNode;
    }

    // TODO 2: Implement the popBook function
    string popBook() {
        if (top == NULL) {
            cout << "Stack is empty. No book to pop.\n";
            return "";
        }
        Node* temp = top;
        string poppedBook = temp->getBook();
        top = top->getNext();
        delete temp;
        return poppedBook;
    }

    // TODO 3: Implement the reverseBookStack function
    void reverseBookStack() {
        if (top == NULL) {
            cout << "Stack is empty. Cannot reverse.\n";
            return;
        }

        Node* prev = NULL;
        Node* curr = top;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->getNext();
            curr->setNext(prev);
            prev = curr;
            curr = next;
        }
        top = prev;
        
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->getBook() << endl;
            temp = temp->getNext();
        }

        cout << "Stack reversed successfully.\n\n" << endl; 
    }

    // TODO 4: Implement the displayBookStack function
    void displayBookStack() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->getBook() << endl;
            temp = temp->getNext();
        }
    }
};

int main() {
    // TODO 5: Write your VUID
    string studentID = "BC240413197";  // ? Replace with YOUR VU ID
    char lastDigitChar = studentID[studentID.length() - 1];
    int lastDigit = lastDigitChar - '0';

    Stack s;
    int booksToReshelve;

    cout << "--------------------------------\n";
    cout << "Library System - (" << studentID << ")\n";
    cout << "--------------------------------\n";
    cout << "Five Books added to Stack: (A-E Sequence)\n";

    // Push 5 books into stack
    s.pushBook("Book-A");
    s.pushBook("Book-B");
    s.pushBook("Book-C");
    s.pushBook("Book-D");
    s.pushBook("Book-E");
    s.displayBookStack();
    cout << endl;

    // Determine how many books to pop
    if (lastDigit <= 5)
        booksToReshelve = 2;
    else
        booksToReshelve = 3;

    cout << "VUID last digit is: " << lastDigit << ". Therefore, "
         << booksToReshelve << " Books popped/reshelved." << endl;
    cout << "Updated Stack is:" << endl;

    for (int i = 0; i < booksToReshelve; i++) {
        s.popBook();
    }

    s.displayBookStack();
    cout << endl;

    // Reverse the remaining stack
    cout << "Reversing the stack:" << endl;
    s.reverseBookStack(); // prints reversed stack + message

    // Displaying final stack
    cout << "Final stack after popping & reversing elements:" << endl;
    s.displayBookStack();

    return 0;
}
#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;
    Node<T> *tail;

public:
    //Constructor
    LinkedList(T *value) {
        Node<T> *newNode = new Node<T>(value);
        this->head = newNode;
        this->tail = newNode;
        this->length = 1;
    }

    //Destructor
    ~LinkedList() {
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void delfirst() {
        if (length == 0) {
            return;
        }
        Node<T> *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void dellast() {
        if (length == 0) {
            return;
        }
        Node<T> *temp = head;
        if (length ==1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T> *pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void deleteNode(int index) {
        //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index >= length) { //index out of range
            return;
        }
        else if (index == 0) { //index requested is the head
            return delfirst();
        }
        else if (index == length - 1) { //index requested is the tail
            return dellast();
        }
        else { //index is within range and is not head or tail
            Node<T> *prev = head;
            Node<T> *temp = head;
            if (temp == NULL) { //can't do anything if head is null
                return;
            }
            else {
                for (int i = 0; i != index; i++) {//loops until reach desired index
                    prev = temp;
                    temp = temp->next;
                }
                if (temp != NULL) { //make sure we can call temp->next
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a given index. Reuse the pre-written functions for edge cases. Account for missing index
        if (index < 0 || index >= length) {
            return;
        }
        else if (index == 0) {
            addfirst(value);
            return;
        }
        else if (index == length) {
            add(value);
            return;
        }
        else {
            Node<T> *newNode = new Node<T>(value);
            Node<T> *temp = head;
            for (int i = 0; i != index - 1; i++) {//loops until reach desired index
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return;
        }
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev, curr, next;
        prev = NULL;
        curr = head;
        while(curr!=NULL) //from reversing a link list slide on canvas
        {
            next = curr->nextNode;
            curr->nextNode = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    ll->dellast();
    ll->print();
//start here
}
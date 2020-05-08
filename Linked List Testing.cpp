#include <iostream>


class Node {
public:
    Node *next;
    int data;
};

using namespace std;

class LinkedList {
public:
    int length;
    Node *head;

    LinkedList();

    ~LinkedList();

    void add(int data);

    void print();

    void reverse();

    void clear();
};

LinkedList::LinkedList() {
    this->length = 0;
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(int data) {
    Node *node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print() {
    Node *head = this->head;
    int i = 1;
    while (head) {
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

void LinkedList::reverse() {
    Node *headOther = head;
    Node *temp = head;
    while (head != nullptr){
        if (head == headOther) {
            head = head->next;
            headOther->next = nullptr;
            temp = head;
        } else {
            temp = head->next;
            head->next = headOther;
            headOther = head;
            head = temp;
        }
    }
    head = headOther;
    temp = nullptr;
    headOther = nullptr;
}

void LinkedList::clear() {
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node *tmpPtr = head->next; //sets a temp variable to the node after it.
        delete head; //deletes the head node
        head = tmpPtr; //The node that head was pointing to is head.
        clear();
    }
}

int main() {
    LinkedList *list = new LinkedList();
    for (int i = 0; i < 5; ++i) {
        list->add(i + 1);
    }
    list->print();
    cout << endl;
    list->reverse();
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    delete list;
    return 0;
}
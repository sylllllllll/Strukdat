#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void prepend(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    void remove(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return; 
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList myLinkedList;
    myLinkedList.append(1); 
    myLinkedList.append(2);
    myLinkedList.append(3);
    myLinkedList.prepend(0);
    myLinkedList.display(); 
    myLinkedList.remove(2); 
    myLinkedList.display(); 

    return 0;
}

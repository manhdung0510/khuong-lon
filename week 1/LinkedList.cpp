#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    //Truy cap : O(N)
    int get(int index) {
        Node* current = head;
        for(int i = 0; i < index; i++) {
            if (current == nullptr) {
            return -1;
            }
            current = current->next;
        }
        return current->data;
    }

    //Chen phan tu vao dau : O(1)
    void addHead(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    //Chen phsn tu vao cuoi : O(N)
    void addLast(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

    //Chen vao vi tri i : 0(N)
    void addIndex(int index, int value){
        if(index <= 0){
            cout << "ERROR" << endl;
            return;
        }
        if(index == 1){
            addHead(value);
            return;
        }
        if(head == nullptr){
            addHead(value);
            return;
        } else {
            Node *h = head;
            for(int i = 2; h != nullptr && i < index; i++){
                h = h -> next;
            }
            if(h == nullptr){
                cout << "ERROR" << endl;
                return;
            } else {
                Node *newNode = new Node{value, h -> next};
                h -> next = newNode;
            }
        }
    }

    //Xoa phan tu dau : O(1)
    void deleteHead() {
        if (head == nullptr) {
            cout << "ERROR" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //Xoa phan tu cuoi : O(N)
     void deleteLast() {
        if (head == nullptr) {
            cout << "ERROR" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    //Xoa vi tri i : O(N)
    void removePos(int index) {
		if (index == 0) {
			deleteHead();
			return;
		}
		Node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

    //Duyet xuoi : O(N)
    void traverseForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    //Duyet nguoc : O(N)
    void traverseBackward() {}

};

int main() {
    LinkedList list;

cout << "   Chen phan tu vao dau" << endl;
    list.addHead(2006);
    list.addHead(10);
    list.addHead(5);
    list.traverseForward();
	// Output : 5 10 2006
cout << "   Chen phan tu vao cuoi" << endl;
    list.addLast(25);
    list.addLast(9);
    list.addLast(2025);
    list.traverseForward();
    // Output : 5 10 2006 25 9 2025
cout << "   Chen vao vi tri i" << endl;
    list.addIndex(4, 19);
    list.traverseForward();
    // Output : 5 10 2006 19 25 9 2025
cout << "   Xoa phan tu dau" << endl;
    list.deleteHead(); 
    list.traverseForward();
    // Output : 10 2006 19 25 9 2025
cout << "   Xoa phan tu cuoi" << endl;
    list.deleteLast();
    list.traverseForward();
    // Output : 10 2006 19 25 9
cout << "   Truy cap phan tu" << endl;
    cout << list.get(1) << endl; 
    // Output : 2006
    cout << list.get(4) << endl; 
    // Output : 9

    return 0;
}

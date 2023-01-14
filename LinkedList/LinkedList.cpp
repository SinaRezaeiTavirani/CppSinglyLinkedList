// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;

class Node {
public:
	int key;
	int data;
	Node* next;
	Node() {
		key = 0;
		data = 0;
		next = nullptr;
	}
	Node(int k, int d) {
		key = k;
		data = d;
	}
};

class SinglyLinkedList {
public:
	Node* head;
	SinglyLinkedList() {
		head = nullptr;
	}
	SinglyLinkedList(Node* n) {
		head = n;
	}
	Node* nodeExists(int k) {
		Node* temp = nullptr;
		Node* ptr = head;

		while (ptr!=nullptr) {
			if (ptr->key == k) {
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	void appendNode(Node* n) {
		if (nodeExists(n->key) != nullptr) {
			cout << "Node Already exists with key value : " << n->key << endl;
		}
		else {
			if (head == nullptr) {
				head = n;
				cout << "Node Appended" << endl;
			}
			else {
				Node* ptr = head;
				while (ptr->next != nullptr) {
					ptr = ptr->next;
				}
				ptr->next = n;
				cout << "Node Appended" << endl;
			}
		}
	}
	void prependNode(Node* n) {
		if (nodeExists(n->key) != nullptr) {
			cout << "Node Already exists with key value : " << n->key << endl;
		}
		else {
			n->next = head;
			head = n;
			cout << "Node Prepended" << endl;
		}
	}
	void insertNodeAfter(int k, Node* n) {
		Node* ptr = nodeExists(k);
		if (ptr == nullptr) {
			cout<<  "No node exists with key value: " << k << endl;
		}
		else {
			if (nodeExists(n->key) != nullptr) {
				cout << "Node Already exists with key value : " << n->key << endl;
			}
			else {
				n->next = ptr->next;
				ptr->next = n;
				cout << "Node Inserted" << endl;
			}
		}

	}
	void deleteNodeByKey(int k) {
		if (head == nullptr) {
			cout << "Singly Linked List already Empty. Cant delete" << endl;
		}
		else if (head != nullptr) {
			if (head->key == k) {
				head = head->next;
				cout << "Node UNLINKED with keys value : " << k << endl;
			}
			else {
				Node* temp = nullptr;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while (currentptr != nullptr) {
					if (currentptr->key == k) {
						temp = currentptr;
						currentptr = nullptr;
					}
					else {
						prevptr = prevptr -> next;
						currentptr = currentptr->next;
					}
				}
				if (temp != nullptr) {
					prevptr->next = temp->next;
					cout << "Node UNLINKED with keys value : " << k << endl;
				}
				else {
					cout << "Node Doesn't exist with key value : " << k << endl;
				}
			}
		}
	}
	void updateNodeByKey(int k, int d) {
		Node* ptr = nodeExists(k);
		if (ptr != nullptr) {
			ptr->data = d;
			cout << "Node Data Updated Successfully" << endl;

		}
		else {
			cout << "Node Doesn't exist with key value : " << k << endl;
		}
	}
	void printList() {
		if (head == nullptr) {
			cout << "No Nodes in Singly Linked List" << endl;
		}
		else {
			cout << endl << "singly LInked List Values : ";
			Node* temp = head;
			while (temp != nullptr) {
				cout << "(" << temp->key << "," << temp->data << ")" << "-->";
				temp = temp->next;
			}
		}
	}
};

int main() {
	
	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl << endl;

		cin >> option;
		Node* n1 = new Node();
		

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.appendNode(n1);
			//cout<<n1.key<<" = "<<n1.data<<endl;
			break;

		case 2:
			cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.prependNode(n1);
			break;

		case 3:
			cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k1;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;

			s.insertNodeAfter(k1, n1);
			break;

		case 4:

			cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
			cin >> k1;
			s.deleteNodeByKey(k1);

			break;
		case 5:
			cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
			cin >> key1;
			cin >> data1;
			s.updateNodeByKey(key1, data1);

			break;
		case 6:
			s.printList();

			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}
#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>class Node {
public:
	Node* next;
	Node *previous;
	T data;
	// Constructor
	Node(const T newData, Node* nextNode = nullptr) : data(newData), next(nextNode) {
	}
};



template <typename T> class LinkedList {
private:
	Node<T> *head;
	Node<T> *tail;
public:
	LinkedList() {
	}

	void append(const T &value) {}
	void remove_last() {}
	void remove_first() {}
	void Print() {}
};


template <typename T> class Stack {
private:
	Node<T> *topNode;
	int n_elems = 0;

public:
	Stack() : topNode(nullptr) {
	}
	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(const T &newData) {
		Node<T>*  newNode = new Node(newData, topNode);
		topNode = newNode;
		++n_elems;
	}

	// Pop element from the stack
	void pop() {
		--n_elems;
		if (!isEmpty()) {
			Node<T>*  temp = topNode;
			topNode = topNode->next;;
		}
		else {
			cout << "Error: Stack is empty. Cannot pop.\n";
		}
	}

	// Return the top element of the stack
	T* top() {
		if (!isEmpty()) {
			return &(topNode->data);
		}
		else {
			cout << "Error: Stack is empty. Cannot access top element.\n";
			throw out_of_range("Stack is empty.");
		}
	}


	bool isEmpty() const {
		return topNode == nullptr;
	}

	void Print() {
		Node<T>* temp = topNode;
		cout << "Numer of elements: " << n_elems << endl;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};


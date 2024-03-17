#include<iostream>
#include<cstdlib>
using namespace std;



template <typename T>class Node {
public:
	Node* next;
	Node* previous;
	T data;
	// Constructor
	Node(const T newData, Node* nextNode = nullptr) : data(newData), next(nextNode) {
	}
};

class LinkedList {
private:
	Node* NewNode;
public:
	LinkedList() {
		NewNode = nullptr;
	}

	void append(int value) {
		
	}

	void remove(int value) {
		Node* temp = NewNode;
		Node* prev = nullptr;

		while (temp != nullptr && temp->data != value) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr) {
			cout << "Element not found in the list." << endl;
			return;
		}

		if (prev == nullptr) {
			NewNode = temp->next;
		}
		else {
			prev->next = temp->next;
		}
		delete temp;
	}

	void Print() {
		Node* temp = NewNode;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};



template <typename T> class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() {
	}

	void append(const T& value) {
		Node<T>* newNode = new Node(value);
		if (NewNode == nullptr)
		{
			NewNode = newNode;
			return;
		}

		Node* temp = NewNode;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void remove_last() {}
	void remove_first() {}
	void Print() {}
};


template <typename T> class Stack {
private:
	Node<T>* topNode;
	int n_elems = 0;

public:
	Stack() : topNode(nullptr) {
	}
	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(const T& newData) {
		Node<T>* newNode = new Node(newData, topNode);
		topNode = newNode;
		++n_elems;
	}

	// Pop element from the stack
	void pop() {
		--n_elems;
		if (!isEmpty()) {
			Node<T>* temp = topNode;
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





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




bool NumberOrOperator(char token)
{
	if (token <= '9' && token >= '0')
		return true;
	else
		return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void jakies_sprawdzenie() {}

int main() {
	LinkedList<T> list;
	Stack<T> stack;
	int number_of_formulas;
	int i = 0;
	char token[12];
	int token_in_int;
	cin >> number_of_formulas;
	while (i < number_of_formulas)
	{
	}

	return 0;
}
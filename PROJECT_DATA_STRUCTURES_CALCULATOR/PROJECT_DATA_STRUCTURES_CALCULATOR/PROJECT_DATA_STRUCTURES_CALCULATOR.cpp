#include<iostream>
#include<cstdlib>

#define MAX_INT_LENGTH 11

using namespace std;

enum operatorType {MAX, MIN, IF, N, ADD, SUB, DIV, MUL};

class MyOperator{
public:
	operatorType operator_type;
	int n_numbers;
	MyOperator(char txt[3]): n_numbers(0){
		if(txt == "MAX"){
			operator_type = MAX;
		}else if (txt == "MIN")
		{
			operator_type = MIN;
		}else if (txt == "*")
		{
			operator_type = MUL;
			n_numbers = 2;
		}
		//////////////////////////////////////////////////////////////////////////////////////
	}
};


class Token{
public:
	int number = 0;
	MyOperator *_operator = nullptr;
	Token(char txt[MAX_INT_LENGTH]){
		if (isNumber(txt[0])){
			number = atoi(txt);
		}
		else
		{
			_operator = new MyOperator(txt);
		}
	}

	bool isNumber(char token)
	{
		if (token <= '9' && token >= '0')
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& os, const Token& t);
};

ostream& operator<<(ostream& os, const Token& t)
{
	if(t._operator == nullptr){
		os << t.number;
	}else{
		os << t._operator->operator_type;
	}
	
    return os;
}	

//dostępne operatory -> MIN, MAX, N, IF, *, /, +, -


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

	void append(const T &newData) {
		Node<T>*  newNode = new Node(newData, topNode);
		topNode = newNode;
		++n_elems;
		delete newNode;
	}
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


bool testStack() {

}

bool testList()
{}

int main() {
	LinkedList<Token> list;
	Stack<Token> stack;

	testStack();
	testList();

	return 0;
}
#include<iostream>
#include<cstdlib>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	bool isNumber;
	// Constructor
	Node(const int newData, Node* nextNode = nullptr, bool isNumber = false) : data(newData), next(nextNode), isNumber(isNumber) {
	}
};



class LinkedList {
private:
	Node* NewNode;
public:
	LinkedList() {
		NewNode = nullptr;
		cout << "eloelo";
	}

	void append(int value) {
		Node* newNode = new Node(value);
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Stack {
private:
	Node* topNode;

public:
	Stack() : topNode(nullptr) {
	}
	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(const int newData, bool isNumber) {
		Node* newNode = new Node(newData, topNode,isNumber);
		topNode = newNode;
	}

	// Pop element from the stack
	void pop() {
		if (!isEmpty()) {
			Node* temp = topNode;
			topNode = topNode->next;;
		}
		else {
			cout << "Error: Stack is empty. Cannot pop.\n";
		}
	}

	// Return the top element of the stack
	int top() {
		if (!isEmpty()) {
			return topNode->data;
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
		Node* temp = topNode;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

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
	LinkedList list;
	Stack stack;
	int number_of_formulas;
	int i = 0;
	char token[12];
	int token_in_int;
	cin >> number_of_formulas;
	while (i < number_of_formulas)
	{
		cin >> token;
		if (NumberOrOperator(token[0]) == true)	{
			token_in_int = atoi(token);
			list.append(token_in_int);
			
		}
		else
		{
			switch (token[0]) {
			case '.':
				i++;
			case '+':
				stack.push(token[0], false);
			case '-':
				stack.push(token[0], false);
			case '*':
				stack.push(token[0], false);
			case '/':
				stack.push(token[0], false);
			}	
		}
	}

	//TOD
	jakies_sprawdzenie();
	list.Print();
	cout << endl;
	stack.Print();

	return 0;
}
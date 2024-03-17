#include<iostream>
#include<cstdlib>
#include<cstring>

#define MAX_INT_LENGTH 10

using namespace std;




enum operatorType {ADD, SUB, DIV, MUL, N, IF, MAX, MIN};

class MyOperator{
public:
	operatorType operator_type;
	int n_numbers;
	MyOperator(char txt[3]): n_numbers(0){
		if(compare_char(txt, "MAX",3) == 1){
			operator_type = MAX;
		}else if (compare_char(txt, "MIN",3) == 1)
		{
			operator_type = MIN;
		}else if (compare_char(txt, "*",1) == 1)
		{
			operator_type = MUL;
			n_numbers = 2;
		}else if (compare_char(txt, "+",1) == 1)
		{
			operator_type = ADD;
			n_numbers = 2;
		}else if (compare_char(txt, "-",1) == 1)
		{
			operator_type = SUB;
			n_numbers = 2;
		}else if (compare_char(txt, "/",1) == 1)
		{
			operator_type = DIV;
			n_numbers = 2;
		}
		else if (compare_char(txt, "IF",2) == 1)
		{
			operator_type = IF;
			n_numbers = 3;
		}
		else if (compare_char(txt, "N", 1) == 1)
		{
			operator_type = N;
			n_numbers = 1;
		}else{
			cout << "nie wykryto zadnego operatora\n";
		}
		//cout << operator_type << endl;
	}
	bool compare_char(char* a, char* b, int length)
		{
			for(int i=0;i<length;i++)
			{
				if(a[i]!=b[i])
					return false;
			}
			return true;
		}
	friend ostream& operator<<(ostream& os, const MyOperator& t);
};

ostream& operator<<(ostream& os, const MyOperator& t)
{
switch (t.operator_type)
{
case MAX:
	os << "MAX" << t.n_numbers;
	break;
case MIN:
	os << "MIN" << t.n_numbers;
	break;
case IF:
	os << "IF";
	break;
case ADD:
	os << "+";
	break;
case SUB:
	os << "-";
	break;
case DIV:
	os << "/";
	break;
case MUL:
	os << "*";
	break;
}
    return os;
}	


class Token{
public:
	int number = 0;
	MyOperator *_operator = nullptr;
	bool isNumber(char token)
	{
		if (token <= '9' && token >= '0')
			return true;
		else
			return false;
	}

	Token(char txt[MAX_INT_LENGTH]){
		if (isNumber(txt[0])){
			number = atoi(txt);
		}
		else
		{
			number = 0;
			_operator = new MyOperator(txt);
		}
	}

	friend ostream& operator<<(ostream& os, const Token& t);
};

ostream& operator<<(ostream& os, const Token& t)
{
	if(t._operator == nullptr){
		os << t.number;
	}else{
		os << *(t._operator);
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
	Node(const T newData, Node* nextNode = nullptr, Node* prevNode = nullptr) : data(newData), next(nextNode),previous(prevNode) {
	}
};

template <typename T> class LinkedList {
private:
	Node<T> *head;
	Node<T> *tail;
	int number_elements = 0;
public:
	LinkedList() : head(nullptr), tail(nullptr){
	}


	void append(const T &newData) {
		++number_elements;
		Node<T>*  newNode = new Node(newData, head);
		head = newNode;
	}
	void remove_last() {
		--number_elements;
		if (!head) // Empty list
			return;
		else if (head == tail) { // Only one element
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<T>* temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete temp;

		}
	}
	void remove_first() {
		--number_elements;

		if (!head) // Empty list
			return;
		else if (head == tail) { // Only one element
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<T>* temp = head;
            head = head->next;
            head->previous = nullptr;
            delete temp;
		}
	}
	void Print() {
		Node<T>* temp = head;
		cout << "Numer of elements list : " << number_elements << endl;
		while (temp != nullptr)
		{
			cout << temp->data << "\n";
			temp = temp->next;
		}
		cout << endl;
	}
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
			topNode = topNode->next;
			delete temp;
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
		cout << "Number of elements: " << n_elems << endl;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};



int main() {
	LinkedList<Token> list;
	Stack<Token> stack;

	int how_many ;
	cin>>how_many;
	char input[9];

	for (int i = 0; i < how_many; i++)
	{
		cin >> input;
		Token *t = new Token(input);
		list.append(*t);
	}

	list.Print();
	list.remove_first();
	list.remove_first();
	list.Print();
	return 0;
}
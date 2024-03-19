#include<iostream>
#include<cstdlib>
#define MAX_INT_LENGTH 11

using namespace std;




enum operatorType {ADD, SUB, DIV, MUL, N, IF, MAX, MIN,OPEN,CLOSE};

bool compare_char( char a[],const char b[], int length)
		{
			for(int i=0;i<length;i++)
			{
				if(a[i]!=b[i])
					return false;
			}
			return true;
		}

class MyOperator{
public:
	operatorType operator_type;
	int n_numbers;
	int index;
	MyOperator(char txt[3]): n_numbers(0),index(1){
		if(compare_char(txt, "MAX",3) == 1)
		{
			operator_type = MAX;
			index = 3;

		}else if (compare_char(txt, "MIN",3) == 1)
		{
			operator_type = MIN;
			index = 3;
		}else if (compare_char(txt, "*",1) == 1)
		{
			operator_type = MUL;
			n_numbers = 2;
			index = 2;
		}else if (compare_char(txt, "+",1) == 1)
		{
			operator_type = ADD;
			n_numbers = 2;
			index = 1;
		}else if (compare_char(txt, "-",1) == 1)
		{
			operator_type = SUB;
			n_numbers = 2;
			index = 1;
		}else if (compare_char(txt, "/",1) == 1)
		{
			operator_type = DIV;
			n_numbers = 2;
			index = 2;
		}
		else if (compare_char(txt, "IF",2) == 1)
		{
			operator_type = IF;
			n_numbers = 3;
			index = 3;
		}
		else if (compare_char(txt, "N", 1) == 1)
		{
			operator_type = N;
			n_numbers = 1;
			index = 3;
		}
		else if (compare_char(txt, "(", 1) == 1)
		{
			operator_type = OPEN;
			index = 4;
		}
		else if (compare_char(txt, ")", 1) == 1)
		{
			operator_type = CLOSE;
			index=4;
		}

		//cout << operator_type << endl;
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
case OPEN:
	os << "(";
	break;
case CLOSE:
	os << ")";
	break;
}
    return os;
}	


bool isNumber(char token)
	{
		if (token <= '9' && token >= '0')
			return true;
		else
			return false;
	}


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

	bool operator==(const Token& other) const {
        return (number == other.number) && (_operator == other._operator);
    }

    // Inequality operator !=
    bool operator!=(const Token& other) const {
        return !(*this == other); 
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
public:
	int number_elements = 0;
	LinkedList() : head(nullptr), tail(nullptr){
	}
	void append(const T &newData) {

		++number_elements;
    	Node<T>* newNode = new Node<T>(newData, nullptr);
   		if (head == nullptr) {
        	head = newNode;
     		tail = newNode;
    	} else {
     	  	tail->next = newNode;
    	    newNode->previous = tail;
    	    tail = newNode;
    	}
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
	void Print_last_to_first() {
		Node<T>* temp = tail;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->previous;
		}
		cout << endl;
	}
	void Print_first_to_last() {
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}


	T& get_first() {
        if (head == nullptr) {
            throw out_of_range("List is empty");
        }
        return head->data;
    }

T& get_last() {
    if (tail == nullptr && head != nullptr) {
        return head->data;
    }
    else if (tail == nullptr && head == nullptr) {
        throw out_of_range("List is empty");
    }
    return tail->data;
	}

	bool isEmpty() const {
        return (head == nullptr);
    }

};




int main() {

	LinkedList<Token> list;
	LinkedList<Token> stack;
	int how_many ;
	cin>>how_many;
	char input[MAX_INT_LENGTH];
	
	int i=0;
	while(i < how_many)
	{
	cin >> input;
	if(input[0]=='.')
		{
			while(!stack.isEmpty())
			{
				list.append(stack.get_last());
				stack.remove_last();
			}
			i++;
			break;
		}	
	else if(isNumber(input[0]))
		{
			Token *t = new Token(input);
			list.append(*t);
		}
	else{
		Token *t = new Token(input);
		switch (input[0]) {
    	case '(':
    	    stack.append(*t);
    	    break;
  	  	case ')':
        	while (stack.get_last()._operator->operator_type != OPEN)
			{
            	list.append(stack.get_last());
            	stack.remove_last();
    	    }
    	    stack.remove_last();
        	break;
    	default:
        	if (stack.isEmpty() || (stack.get_last()._operator->n_numbers <= list.number_elements && t->_operator->index > stack.get_last()._operator->index)) 
			{
    			stack.append(*t);
			} 
			else if (stack.get_last()._operator->n_numbers <= list.number_elements && t->_operator->index <= stack.get_last()._operator->index) 
			{
   				while (!stack.isEmpty() && t->_operator->index <= stack.get_last()._operator->index && stack.get_last()._operator->index != 4)
				{
        			list.append(stack.get_last());
        			stack.remove_last();                    
   				}
    			stack.append(*t);
			}
        	break;
		}
		}
	}
	list.Print_first_to_last();

	return 0;
}
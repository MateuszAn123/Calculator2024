#include<iostream>
#include<cstdlib>
#define MAX_INT_LENGTH 11

using namespace std;




enum operatorType { ADD, SUB, DIV, MUL, N, IF, MAX, MIN, OPEN, CLOSE , PRZECINEK};

bool compare_char(char a[], const char b[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

class MyOperator {
public:
	operatorType operator_type;
	int n_numbers;
	int index;
	MyOperator(char txt[3]) : n_numbers(0), index(1) {
		if (compare_char(txt, "MAX", 3) == 1)
		{
			operator_type = MAX;
			index = 3;

		}
		else if (compare_char(txt, "MIN", 3) == 1)
		{
			operator_type = MIN;
			index = 3;
		}
		else if (compare_char(txt, "*", 1) == 1)
		{
			operator_type = MUL;
			n_numbers = 2;
			index = 2;
		}
		else if (compare_char(txt, "+", 1) == 1)
		{
			operator_type = ADD;
			n_numbers = 2;
			index = 1;
		}
		else if (compare_char(txt, "-", 1) == 1)
		{
			operator_type = SUB;
			n_numbers = 2;
			index = 1;
		}
		else if (compare_char(txt, "/", 1) == 1)
		{
			operator_type = DIV;
			n_numbers = 2;
			index = 2;
		}
		else if (compare_char(txt, "IF", 2) == 1)
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
			index = 4;
		}
		else if (compare_char(txt, ",", 1) == 1)
		{
			operator_type = PRZECINEK;
			index = 0;
			n_numbers = 1;

		}
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
	case N:
		os << "N";
		break;
	case OPEN:
		os << "(";
		break;
	case CLOSE:
		os << ")";
		break;
	case PRZECINEK:
		os << ",";
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


class Token {
public:
	int number = 0;
	MyOperator* _operator = nullptr;

	Token(int num) : number(num), _operator(nullptr) {}

	Token(char txt[MAX_INT_LENGTH]) {
		if (isNumber(txt[0])) {
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

	bool operator!=(const Token& other) const {
		return !(*this == other);
	}

	Token operator+(int num) const {
		Token result(number + num);
		return result;
	}

	Token operator-(int num) const {
		Token result(number - num);
		return result;
	}

	Token& operator=(const Token& other) {
		if (this != &other) {
			number = other.number;
			if (_operator)
				delete _operator;
			if (other._operator)
				_operator = new MyOperator(*other._operator);
			else
				_operator = nullptr;
		}

		return *this;
	}

	friend ostream& operator<<(ostream& os, const Token& t);
};

ostream& operator<<(ostream& os, const Token& t)
{
	if (t._operator == nullptr) {
		os << t.number;
	}
	else {
		os << *(t._operator);
	}
	return os;
}

//dostępne operatory -> MIN, MAX, N, IF, *, /, +, -


template <typename T>class Node {
public:
	Node* next;
	Node* previous;
	T data;
	// Constructor
	Node(const T newData, Node* nextNode, Node* prevNode) : data(newData), next(nextNode), previous(prevNode) {
	}
};



template <typename T> class LinkedList {
public:
	Node<T>* head;
	Node<T>* tail;
	int number_elements = 0;
	LinkedList() : head(nullptr), tail(nullptr) {
	}
	void append_last(const T& newData) {

		++number_elements;
		Node<T>* newNode = new Node<T>(newData, nullptr, nullptr);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
	}

	void append_first(const T& newData) {
		++number_elements;
		Node<T>* newNode = new Node<T>(newData, nullptr, nullptr);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
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
	void Print_last_to_first() const {
		Node<T>* temp = tail;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->previous;
		}
		cout << endl;
	}
	void Print_first_to_last() const {
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		
		cout << endl;
	}

	T& get_first() {
		if (head == nullptr && tail != nullptr)
			return tail->data;
		else if (head == nullptr && tail == nullptr)
			throw out_of_range("List is empty");
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

int function_IF(int n1, int n2, int n3)
{
	if (n1 >= 0)
		return n2;
	else
		return n3;
}




int main() {
	bool max_min = false;
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int commas = 1;
	int how_many;
	int max_or_min = 0;
	cin >> how_many;
	char input[MAX_INT_LENGTH];
	int result;
	for (int i = 0; i < how_many; i++)
	{
		LinkedList<Token> list;
		LinkedList<Token> stack;

		while (true)
		{
			cin >> input;
			if (input[0] == '.')
			{
				while (!stack.isEmpty())
				{
					if (stack.get_last()._operator->operator_type == MAX || stack.get_last()._operator->operator_type == MIN)
					{
						//stack.get_last()._operator->n_numbers = commas;
						commas = 1;
					}
					list.append_last(stack.get_last());
					stack.remove_last();
				}
				break;
			}
			else if (isNumber(input[0]))
			{
				Token* t = new Token(input);
				list.append_last(*t);
			}
			else
			{
				Token* t = new Token(input);
				switch (input[0]) {
				case '(':
					stack.get_last()._operator->n_numbers = 1;
					stack.append_last(*t);
					break;
				case ')':
					
					while (stack.get_last()._operator->operator_type != OPEN)
					{
						if (stack.get_last()._operator->operator_type == PRZECINEK)
						{
							stack.remove_last();
							commas++;
						}
						else
						{	
							//stack.get_last()._operator->n_numbers = commas;
							list.append_last(stack.get_last());
							stack.remove_last();
						}
					}
					stack.remove_last();
					stack.get_last()._operator->n_numbers = commas;
					commas = 1;
					break;
				case ',':
					while (stack.get_last()._operator->operator_type != OPEN && stack.get_last()._operator->operator_type != PRZECINEK)
					{
						list.append_last(stack.get_last());
						stack.remove_last();
					}
					//commas++;
					stack.append_last(*t);
					break;
				default:
					if ((stack.isEmpty()) || (t->_operator->index > stack.get_last()._operator->index))
					{
						stack.append_last(*t);
					}
					else if (t->_operator->index <= stack.get_last()._operator->index)
					{
						while (!stack.isEmpty() && t->_operator->index <= stack.get_last()._operator->index && stack.get_last()._operator->index != 4)
						{
							list.append_last(stack.get_last());
							stack.remove_last();
						}
						stack.append_last(*t);
					}
					break;
				}
			}
		}
		list.Print_first_to_last();
		while (true)
		{
			int result;
			if (list.get_first().number)
			{
				stack.append_last(list.get_first());
				list.remove_first();
			}
			else if (list.get_first() == PRZECINEK)
			{
				list.remove_first();
			}
			else
			{
				stack.append_last(list.get_first());
				list.remove_first();
				stack.Print_last_to_first();
				switch (stack.get_last()._operator->operator_type) {
				case ADD:
					stack.remove_last();
					number1 = stack.get_last().number;
					stack.remove_last();
					number2 = stack.get_last().number;
					stack.remove_last();
					result = number1 + number2;
					list.append_first(result);
					break;
				case MUL:
					stack.remove_last();
					number1 = stack.get_last().number;
					stack.remove_last();
					number2 = stack.get_last().number;
					stack.remove_last();
					result = number1 * number2;
					list.append_first(result);
					break;
				case SUB:
					stack.remove_last();
					number1 = stack.get_last().number;
					stack.remove_last();
					number2 = stack.get_last().number;
					stack.remove_last();
					result = number2 - number1;
					list.append_first(result);
					break;
				case DIV:
					stack.remove_last();
					number1 = stack.get_last().number;
					if (number1 == 0)
					{
						cout << "ERROR";
					}
					else {
						stack.remove_last();
						number2 = stack.get_last().number;
						stack.remove_last();
						result = number2 / number1;
						list.append_first(result);
					}
					break;
				case N:
					stack.remove_last();
					number1 = stack.get_last().number;
					stack.remove_last();
					result = number1 * -1;
					list.append_first(result);
					break;
				case IF:
					stack.remove_last();
					number1 = stack.get_last().number;
					stack.remove_last();
					number2 = stack.get_last().number;
					stack.remove_last();
					number3 = stack.get_last().number;
					stack.remove_last();
					result = (number3>0 ? number2 : number1);
					list.append_first(result);
					break;
				case MAX:
					max_or_min = stack.get_last()._operator->n_numbers;
					stack.remove_last();
					result = stack.get_last().number;
					stack.remove_last();
					for (int i = 0; i < max_or_min-1; i++)
					{
						if (stack.get_last().number > result)
							result = stack.get_last().number;
						stack.remove_last();
					}
					list.append_first(result);
					break;
				case MIN:
					max_or_min = stack.get_last()._operator->n_numbers;
					stack.remove_last();
					result = stack.get_last().number;
					stack.remove_last();
					for (int i = 0 ; i < max_or_min-1; i++)
					{
						if (stack.get_last().number < result)
							result = stack.get_last().number;
						stack.remove_last();
					}
					list.append_first(result);
					break;
				}
			}
			if (list.number_elements == 1 && list.get_first().number)
			{
				cout << list.get_first() << endl << endl;
				list.remove_first();
				break;
			}
		}
	}
	return 0;
}
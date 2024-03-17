#include<iostream>
#include"DataStructures.hpp"
#include<limits>

#define MAX_INT_LENGTH 11

enum operatorType {MAX, MIN, IF, N, ADD, SUB, DIV, MUL};

class MyOperator{
public:
	operatorType operator_type;
	int n_numbers;
	MyOperator(char txt[3]): n_numbers(0){
		//TODO
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

bool testStack(){

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



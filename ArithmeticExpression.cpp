/*
* Name: Tianqi Qi, Polly Yao, Shiyu Luo
* MacID: qit3, yaos5, luos
* Student Number: 1405930, 1215549, 1317135
* Description: The ArithmeticExpression class is where all the recursion occurs. a derived ArithmeticExpression object e pointed
* to by the base class pointer to Expression calls the breakE, evaluate and print functions in the ArithmeticExpression.
* The left and right pointers are initilized in breakE. The expression is further divided into left and right expressions through recursion.
* Then the smaller expressions are evaluated and printed through recursion. 
*/

#include<iomanip>//import fix
#include "ArithmeticExpression.h"//Import the ArithmeticExpression header
#include "Addition.h"//Import the Addtion header
#include "Subtraction.h"//Import the Subtraction Header
#include "Division.h"//Import the Division header
#include "Multiplication.h"//Import the multiplication header
#include <stdlib.h>//Import the stdlic header
#include <iostream>//Import iostream
using namespace std;//Using namespace std for cout and cin

void ArithmeticExpression::breakE(){//break up the expression
	int len = input.length();//initialize len as length of input
		bool extraBrackets = true;//initialize extraBrackets as true
		//deletes outter most brackets until there are no extra outmost brackets overlaid 
		while (extraBrackets && input[0] == '(') {//if condition is true and the first character in the input is a left bracket
			int counter = 1;//initialize counter for the brackets as 1
			len = input.length();//set len as the string length
			for (int i = 1; i < len; i++) {//for index between 1 and length
				if (input[i] == '(') {//if character is a left bracket
					counter++;//increament counter for brackets by 1
				}
				if (input[i] == ')') {//if character is a right bracket
					counter--;//decrease counter for brackets by 1
				}
				if (i != len - 1 && counter == 0){//if counter reaches 0 before reaching the end index of the input, then all brackets are balanced and there are not extra brackets
					extraBrackets = false;//change extraBrackets to false
					break;//break out of the while loop
				}
				else if (i == len - 1 && counter == 0) {//if counter reaches 0 when at the last index of the input, then trim outer brackets
					input = input.substr(1, len - 2);//input is the substring without the brackets
				}
			}
	}
	len = input.length();//length of the string
	index = getIndex();//get the index  
	if (index == -1 || index == 100) {//if index is equal to -1 or 100 then the character is a number or a negative number, set key to "%"
		key = '%';//set key to '%' to represent a number
		return;//return null
	} else{//if index is any other number, then there are arithmetic operators in the input

		key = input[index];//retrieve the operator at the returned index
		//split the expression into 2 parts
		string subL = input.substr(0, index);//left part of the expression
		string subR = input.substr(index + 1, len);//right part of the expression
	    left = new ArithmeticExpression(subL); //initialize left as an ArithmeticExpression object
		left->breakE();//call recursion to break left part into the left and right part
		right = new ArithmeticExpression(subR);//initialize right as an ArithmeticExpression object
		right->breakE();//call retursion to break right part into th left and right part
	}
	return;//return null
}

int ArithmeticExpression::getIndex() {//get the index 
	int presi = 4;//initialize precedence to 4
	int index = -1;//initialize index to -1
	int len = input.length();//set len to length of the input
	if (input[0] == '-') {//if starting character is -, then return 100 because the first number is negative
		return 100;//return index as 100 
	}
	for (int i = 0; i < len; i++) {//for loop to loop through input
		if (input[i] == '(') {//if character is equal to '('
			i++;//increment i by 1
			int leftB = 1;//initialize leftB as 1 to count the number of left brackets
			int rightB = 0;//initialize rightB as 0 to count the number of right brackets
			while (i < len && leftB != rightB) {//if index is in range and left brackets does not equal right brackets
				if (input[i] == '(') { leftB++; }//for every left bracket increment leftB by 1
				if (input[i] == ')') { rightB++; }//for every right brcket increment rightB by 1
				i++;//increment i by 1
			}
		}
		if (input[i] > '9' || input[i] < '0') {//if character is not equal to a number between 1 and 9, it is a arithmetic operator
			int temp = checkPresi(input[i]);//check the presedence of the operator and store the precedence in temp
			if (temp <= presi) {//if the temperary precedence is lower the presedence
				index = i;//set index to i
				presi = temp;}//set new precedence to temp precedence
		}

		
		
	}


	return index;//return index
}

int ArithmeticExpression::checkPresi(char temp) {//check the precedence of arithmetic operator
	if (temp == '+' || temp == '-') {//if arithmetic symbol is equal to '+' or '-'
		return 1;//return 1
	} else if (temp == '*' || temp == '/') {//if arithmetic symbol is equal to '*' and '/'
		return 2;//return 2
	} else{//for all other cases
		return 3;//return 3
	}
}


ArithmeticExpression::ArithmeticExpression(string &str) :Expression(){//constructor for the ArithmeticExpression class
	input = str;//store string in input
}

ArithmeticExpression::~ArithmeticExpression() {//destrctor for the ArithmeticExpression class
	delete right;//destruct right pointer
	delete left;//destruct left pointer
}

<<<<<<< HEAD
void ArithmeticExpression::increment() {//increment all the numebers in the expression
	if (index == -1 || index == 100) {//if the current charater is a number or a negative numbr
		float temp = stof(input);//convert input to float and stores the value in temp
		input = to_string(temp + 1);//increment the number
	}
	else {//if current character is an arithmetic operator
		left->increment();//call recursion to increment the left side of the expression
		right->increment();//call recursion to increment the right side of the expression
=======
void ArithmeticExpression::increment() {
	if (index == -1 || index == 100) {//base case
		int temp = stoi(input);//convert string to int
		input = to_string(temp + 1);//increment by one
	}
	else {//recursion
		left->increment();//left recursion
		right->increment();//right recursion
>>>>>>> origin/master
	}
}

void ArithmeticExpression::print(){//print out the expression recursively
	if (key == '%') {//if key is equal to '%', this means the character is either a number or a negative number
		cout << input;//print out 
	}
	else {//if key is equal to an operator 
		cout << '(';//print a bracket
		left->print();//call recursion to print out the left side of the expression
		cout << ')';//print a bracket
		cout << key;//print out the operator
		cout << '(';//print a bracket
		right->print();//call recursion to print out the right side of the expression
		cout << ')';//print a bracket
	}
}

float ArithmeticExpression::convert(string &str){//convert string into float

	return stof(str); // return the float
}

string ArithmeticExpression::evaluate(){//evaluate the expression recursively
	if (key == '%') {//if key is a number or a negative number
		return input;//return the number
	}
	else {//if key is a operator
		if (key == '+') {//if the operatior is '+'
			Addition *a = new Addition();//create a pointer to addition
			string str = a->evaluate(left, right);//initialize string to store the result of using recursion to evaluate the left and right side of the expression
			delete a;//destruct a
			return str;//return the evaluated result
		}
		if (key == '-') {//if the operator is '-'
			Subtraction *s = new Subtraction();//create a pointer to subtraction
			string str = s->evaluate(left, right);//initialize string to store the result of using recursion to evaluate the left and right side of the expression
			delete s;//destruct s
			return str;//return the evaluated result
		}
		if (key == '*') {//if the operator is '*'
			Multiplication *m = new Multiplication();//create a pointer to multiplication
			string str = m->evaluate(left, right);//initialize string to store the result of using recursion to evaluate the left and right side of the expression
			delete m;//destruct m
			return str;//return the evaluated result
		}
		if (key == '/') {//if the operator is '/'
			Division *d = new Division();//create a pointer to division
			string str = d->evaluate(left, right);//initialize string to store the result of using recursion to evaluate the left and right side of the expression
			delete d;//destruct d
			return str;//return the evaluated result
		}
	}
	return "";//return empty string
}

ArithmeticExpression::ArithmeticExpression(){}//default contructor

ArithmeticExpression::ArithmeticExpression(Expression* old){
	index = static_cast<ArithmeticExpression*>(old)->index; //type cast Expression pointer to ArithmeticExpression pointer can store result in index
	key = static_cast<ArithmeticExpression*>(old)->key; //type cast Expression pointer to ArithmeticExpression pointer can store result in key
	input = static_cast<ArithmeticExpression*>(old)->input; //type cast Expression pointer to ArithmeticExpression pointer can store result in input
	if (index == -1 || index == 100) {//if index is equal to -1 or 100 then the character is a number or a negative number, set key to "%"
		return;//return null
	}
	else {
		left = new ArithmeticExpression(static_cast<ArithmeticExpression*>(old)->left); //initialize left as an ArithmeticExpression object
		right = new ArithmeticExpression(static_cast<ArithmeticExpression*>(old)->right); //initialize left as an ArithmeticExpression object
	}
	return;
}
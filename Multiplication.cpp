/*
* Name: Tianqi Qi, Polly Yao, Shiyu Luo
* MacID: qit3, yaos5, luos
* Student Number: 1405930, 1215549, 1317135
* Description: The Multiplication class evaluates the two pointer expression multiplications and returns the result as a string
*/

#include "Multiplication.h"//import Division header
#include <iostream>//Include iostream for inputs and outputs
using namespace std;//Using namespace std for cout and cin

Multiplication:: Multiplication () {//Default constructor for Multiplication

}

Multiplication::~Multiplication() {//Default destructor for Division
}

string Multiplication::evaluate(Expression* left, Expression* right){//evaluate multiplication for the left and right pointers
	//int output = left * right;
	float output = static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) * static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());	//evaluate multiplication of the expression pointed to by the left and right pointers and convert evaluated result pointer of the base class Expression to a pointer of a ArithmeticExpression
	return 	std::to_string(output);//convert the result to string and return result
}

void Multiplication:: print(){//print out multiplication
	cout <<")"<< left << "*" << right << ")" << "= ";//print out multiplication to screen

}



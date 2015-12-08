/*
* Name: ?Tianqi Qi, Polly Yao, Shiyu Luo
* MacID: ?qit3, yaos5, luos
* Student Number: 1405930, 1215549, 1317135
* Description: The Subtraction class evaluates the two pointer expression subtractions and returns the result as a string
*/

#include "Subtraction.h"//import Division header
#include <iostream>//import iostream for inputs and outputs
using namespace std;//Using namespace std for cout and cin

Subtraction:: Subtraction() {//default constructor for subtraction

}

Subtraction:: ~Subtraction(){//default destructor for subtraction

}

string Subtraction::evaluate(Expression* left, Expression* right){//evaluate subtraction for the left and right pointers
	//float output = left - right;
	float output = static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) - static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());	//evaluate division of the expression pointed to by the left and right pointers and convert evaluated result pointer of the base class Expression to a pointer of a ArithmeticExpression
	return 	std::to_string(output);//convert the result to string and return result
}

void  Subtraction:: print(){
	cout << ")" << left << "-" << right << ")"  ;
}








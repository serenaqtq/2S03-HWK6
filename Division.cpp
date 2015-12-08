/*
* Name: Tianqi Qi, Polly Yao, Shiyu Luo
* MacID: qit3, yaos5, luos
* Student Number: 1405930, 1215549, 1317135
* Description: The Division class evaluates the two pointer expression divisions and returns the result as a string
*/

#include "Division.h"//import Division header
#include <iostream>//import iostream for inputs and outputs
using namespace std;//Using namespace std for cout and cin

Division::Division() {//default constructor for Division

}

Division::~Division() {//default destructor for Division

}

string Division::evaluate(Expression* left, Expression* right)//evaluate division for the left and right pointers
{
	//float output = left / right;
	float output =static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) / static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());//evaluate division of the expression pointed to by the left and right pointers and convert evaluated result pointer of the base class Expression to a pointer of a ArithmeticExpression
	return 	std::to_string(output);//convert the result to string and return result
}

void Division:: print(){//print out division
	cout << "(" << left << "/" << right << ")" << "= ";//print division to screen

}

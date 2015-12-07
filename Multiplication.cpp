/*
 * Multiplication.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#include "Multiplication.h"
#include <iostream>//Include iostream for inputs and outputs
using namespace std;

Multiplication:: Multiplication () {
	// TODO Auto-generated constructor stub

}

Multiplication::~Multiplication() {
	// TODO Auto-generated destructor stub
}

string Multiplication::evaluate(Expression* left, Expression* right){
	//int output = left * right;
	float output = static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) * static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());	
	return 	std::to_string(output);
}

string Multiplication::evaluate() {
	return "";
}

void Multiplication:: print(){
	cout <<")"<< left << "*" << right << ")" << "= ";

}



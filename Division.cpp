/*
 * Division.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#include "Division.h"
#include <iostream>//Include iostream for inputs and outputs
using namespace std;

Division::Division() {
	// TODO Auto-generated constructor stub

}

Division::~Division() {
	// TODO Auto-generated destructor stub
}

string Division::evaluate(Expression* left, Expression* right)
{
	//int output = left / right;
	float output =static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) / static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());
	return 	std::to_string(output);
}

void Division:: print(){
	cout << "(" << left << "/" << right << ")" << "= ";

}

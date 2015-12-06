/*
 * Subtraction.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#include "Subtraction.h"
#include <iostream>
using namespace std;

Subtraction:: Subtraction() {

}

Subtraction:: ~Subtraction(){

}

string Subtraction::evalute(Expression* left, Expression* right)){
	//int output = left - right;
	float output = static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) - static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());	return 	std::to_string(output);
}

void  Subtraction:: print(){
	cout << ")" << left << "-" << right << ")"  ;
}








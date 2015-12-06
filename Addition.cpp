/*
 * Addition.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#include "Addition.h"
#include <iostream>
using namespace std;

Addition:: Addition() {

}

Addition:: ~Addition(){

}

string Addition::evalute(Expression* left, Expression* right){
	//int output = left + right;
	float output = static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) + static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());	return 	std::to_string(output);
}

void Addition:: print(){
	cout << ")" << left << "+" << right << ")";
}





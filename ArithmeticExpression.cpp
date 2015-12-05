/*
 * ArithmeticExpression.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#include "ArithmeticExpression.h"
#include <stdlib.h>

ArithmeticExpression::ArithmeticExpression(string &tempInput, string &tempType) {
	input = tempInput;
	type = tempType;
	left = 0;
	right = 0;
}

ArithmeticExpression::~ArithmeticExpression() {
	delete left;
	delete right;
}

void ArithmeticExpression::print(){

}

float ArithmeticExpression::convert(string &str){
	return atof(str.c_str());
}

string ArithmeticExpression::evaluate(){

}


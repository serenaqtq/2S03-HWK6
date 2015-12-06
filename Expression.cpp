/*
 * Expression.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#include "Expression.h"
#include <iostream>

int Expression::counter = 0;
Expression::Expression() {
	counter++;
	cout << "counter: " << counter;
	// TODO Auto-generated constructor stub

}

Expression::~Expression() {
	counter--;
	// TODO Auto-generated destructor stub
}

void Expression::breakE(){}

string Expression::evaluate(){
	return "";
}
void Expression::print(){}


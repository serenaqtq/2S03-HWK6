/*
 * Division.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#ifndef DIVISION_H
#define DIVISION_H
#include<string>
#include "ArithmeticExpression.h"
using std::string;

class Division: public ArithmeticExpression {
public:
	Division();
	~Division();
	string evaluate();
	void print();
};

#endif /* DIVISION_H_ */

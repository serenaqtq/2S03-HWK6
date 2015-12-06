/*
 * Division.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#ifndef DIVISION_H_
#define DIVISION_H_
#include<string>
#include "ArithmeticExpression.h"
using std::string;

class Division: public ArithmeticExpression {
public:
	Division();
	virtual ~Division();
	string evaluate();
	void print();
};

#endif /* DIVISION_H_ */

/*
 * Multiplication.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Multiplication : public ArithmeticExpression {
public:
	Multiplication();
	virtual ~Multiplication();
	string evaluate();
	void print();
};

#endif /* MULTIPLICATION_H_ */

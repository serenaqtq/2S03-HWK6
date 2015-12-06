/*
 * Multiplication.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Multiplication : public ArithmeticExpression {
public:
	Multiplication();
	~Multiplication();
	string evalute();
	string evalute(Expression*, Expression*);
	void print();
};

#endif /* MULTIPLICATION_H_ */

/*
 * Subtraction.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#ifndef SUBTRACTION_H
#define SUBTRACTION_H
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Subtraction: public ArithmeticExpression {
public:
	Subtraction();
	~Subtraction();
	string evaluate();
	string evaluate(Expression*, Expression*);
	void print();
};










#endif /* SUBTRACTION_H_ */

/*
 * ArithmeticExpression.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"

class ArithmeticExpression: public Expression {
public:
	ArithmeticExpression();
	virtual ~ArithmeticExpression();
	string evaluate();
	void print();
	float convert(string s);
protected:
	Expression *left;
	Expression *right;
};

#endif /* ARITHMETICEXPRESSION_H_ */

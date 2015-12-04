/*
 * Expression.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include<string>
using std::string;

class Expression {
public:
	Expression();
	virtual ~Expression();
	virtual string evaluate();
	virtual void print();
};

#endif /* EXPRESSION_H_ */

/*
 * Expression.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H
#include<string>
using namespace std;
//using std::string;

class Expression {
public:
	static int counter;
	Expression();
    virtual ~Expression();
	virtual string evaluate();
	virtual void print();
	virtual void breakE();
};

#endif /* EXPRESSION_H_ */

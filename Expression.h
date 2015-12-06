/*
 * Expression.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include<string>
using namespace std;
//using std::string;
using namespace std;

class Expression {
public:
	Expression();
	virtual ~Expression();
	virtual string evaluate();
	virtual void print();
	virtual void breakE();
};

#endif /* EXPRESSION_H_ */

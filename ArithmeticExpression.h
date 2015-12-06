/*
 * ArithmeticExpression.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

#include "Expression.h"
using namespace std;
class ArithmeticExpression: public Expression {
protected:
	int indexAtKey;
	char key;
	string input;
	Expression* left;
	Expression* right;
public:
	ArithmeticExpression(string &str);
	virtual ~ArithmeticExpression();
	string evaluate();
	void print();
	float convert(string &str);
	//Expression* createLeaf(string &str);
	//void addLeaf(char key, Expression* Ptr);
	void breakE();
	int checkPresi(char temp);
	int getIndex();
};

#endif /* ARITHMETICEXPRESSION_H_ */

/*
 * ArithmeticExpression.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "Expression.h"
using namespace std;
class ArithmeticExpression: public Expression {
public:
	int indexAtKey;
	char key;
	string input;
	Expression* left;
	Expression* right;

	ArithmeticExpression(string &str);
	ArithmeticExpression();
	~ArithmeticExpression();
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

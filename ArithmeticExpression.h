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
private:
	struct node
	{
		string key;
		node* left;
		node* right;
	};
	node* root;
	void printPrivate(node* Ptr);
public:
	ArithmeticExpression();
	virtual ~ArithmeticExpression();
	string evaluate();
	void print();
	float convert(string &str);
	node* createLeaf(string &str);
	void addLeaf(string key, node*Ptr);
};

#endif /* ARITHMETICEXPRESSION_H_ */

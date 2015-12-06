/*
 * Division.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#ifndef DIVISION_H
#define DIVISION_H
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Division: public ArithmeticExpression {
public:
	Division();
	~Division();
	string evalute();
	string evalute(Expression* left, Expression* right);
	void print();
};

#endif /* DIVISION_H_ */

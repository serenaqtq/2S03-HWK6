/*
 * Subtraction.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Subtraction: public ArithmeticExpression {
public:
	Subtraction();
	virtual ~Subtraction();
	string evalute();
	void print();
};










#endif /* SUBTRACTION_H_ */

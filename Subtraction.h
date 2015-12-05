/*
 * Subtraction.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_
#include<string>
using std::string;

class Subtraction: public ArithmeticExpression {
public:
	Subtraction();
	virtual ~Subtraction();
	string evalute();
	void print();
};










#endif /* SUBTRACTION_H_ */

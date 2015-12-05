/*
 * Addition.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#ifndef ADDITION_H_
#define ADDITION_H_
#include<string>
using std::string;

class Addition: public ArithmeticExpression {
public:
	Addition();
	virtual ~Addition();
	string evalute();
	void print();
};





#endif /* ADDITION_H_ */

/*
 * Addition.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#ifndef ADDITION_H_
#define ADDITION_H_
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Addition: public ArithmeticExpression {
public:
	Addition();
	virtual ~Addition();
	string evalute();
	void print();
};





#endif /* ADDITION_H_ */

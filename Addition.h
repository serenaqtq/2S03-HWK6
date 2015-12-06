/*
 * Addition.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#ifndef ADDITION_H
#define ADDITION_H
#include<string>
#include "ArithmeticExpression.h"
using std::string;
using namespace std;

class Addition: public ArithmeticExpression {
public:
	Addition();
	~Addition();
	string evalute();
	string evalute(Expression*, Expression*);
	void print();
};





#endif /* ADDITION_H_ */

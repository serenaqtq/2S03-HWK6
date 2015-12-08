

#ifndef ADDITION_H // checks whether ADDITION_H has been defined earlier in the file or in an included file
#define ADDITION_H // if not defined, ADDITION_H is defined
#include<string>//import string
#include "ArithmeticExpression.h"//import ArithmeticExpression header
using std::string;//allows using strings without std::
using namespace std;//allows using cout and cin without std::

class Addition: public ArithmeticExpression {//Class Addition inherites ArithmeticExpression
public://define all public variables and functions
	Addition();//defines default constructor
	~Addition();//defines default destructor
	string evaluate(Expression* left, Expression* right);//define evaluate to take in two pointers and return a string
	void print();//define print to return null
};





#endif /* ADDITION_H_ */

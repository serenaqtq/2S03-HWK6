

#ifndef MULTIPLICATION_H// checks whether MULTIPLICATION_H  has been defined earlier in the file or in an included file
#define MULTIPLICATION_H// if not defined, define MULTIPLICATION_H
#include<string>//import string
#include "ArithmeticExpression.h"//import ArithmeticExpression header
using std::string;//allows using string without std::
using namespace std;//allows using cout and cin without std::

class Multiplication : public ArithmeticExpression {//define class multiplication that is inherited from class ArithmeticExpresion
public://define all public variables and functions
	Multiplication();//define default constructor
	~Multiplication();//define default detructoor
	string evaluate(Expression* left, Expression* right);//define evaluate to take in two pointers and return a string
	void print();//define print to return null
};

#endif /* MULTIPLICATION_H_ */

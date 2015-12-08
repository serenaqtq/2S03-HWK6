

#ifndef SUBTRACTION_H// checks whether SUBTRACTION_H  has been defined earlier in the file or in an included file
#define SUBTRACTION_H// if not defined, define SUBTRACTION_H
#include<string>//import string
#include "ArithmeticExpression.h"//import ArithmeticExpression header
using std::string;//allows using string without std::
using namespace std;//allows using cout and cin without std::

class Subtraction: public ArithmeticExpression {//define class subtraction which inherite from class ArithmeticExpression
public://define all public functions and variables
	Subtraction();//define default constructor
	~Subtraction();//define default destructor
	string evaluate(Expression* left, Expression* right);//define evaluat take in two pointers and return a string
	void print();//define print to return null
};










#endif /* SUBTRACTION_H_ */

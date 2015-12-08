

#ifndef DIVISION_H // checks whether DIVISION_H  has been defined earlier in the file or in an included file
#define DIVISION_H // if not defined, define DIVISION_H 
#include<string>//import string
#include "ArithmeticExpression.h"//import ArithmeticExpression header
using std::string;// allows using string wihtout std::
using namespace std;//allows using namespace without std::

class Division: public ArithmeticExpression {//class Division inherites ArithmeticExpression
public://define all public functions and variables
	Division();//define default constructor
	~Division();//define default destructor
	string evaluate(Expression* left, Expression* right);//define evaluate to take in two pointers and return a string
	void print();//define evaluate 
};

#endif /* DIVISION_H_ */

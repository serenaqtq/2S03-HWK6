

#ifndef EXPRESSION_H// checks whether EXPRESSION_H has been defined earlier in the file or in an included file
#define EXPRESSION_H// if not defined, ADDITION_H is defined
#include<string> //import string
using namespace std;//using cout without std::

class Expression {//define class Expression
public://define all public variables and functions
	
	//static int counter;//define counter as a static int
	Expression();//define default constructor
    virtual ~Expression();//define virtual default destructor
	virtual string evaluate();//define evaluate as a virtual function that returns string
	virtual void print();//define print as a virtual function that returns null
	virtual void breakE();//defien breakE as a virtual function that returns null
};

#endif /* EXPRESSION_H_ */

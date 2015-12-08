

#ifndef ARITHMETICEXPRESSION_H  // checks whether ARITHMETICEXPRESSION_H has been defined earlier in the file or in an included file
#define ARITHMETICEXPRESSION_H // if not, it defines ARITHMETICEXPRESSION_H and continues

#include "Expression.h"//import expression header
using namespace std;//Using namespace std for cout and cin
class ArithmeticExpression: public Expression { //class ArithmeticExpression inherites Expression
public://define public functions and variables
	int indexAtKey;
	char key;//define key as a char
	string input;//define input as a string
	Expression* left;//define left pointer as a base pointer to Expression
	Expression* right;//define right pointer as a base pointer to Expression

	ArithmeticExpression(string &str);//define constructor for ArithmeticExpression
	ArithmeticExpression();//define default constructor
	~ArithmeticExpression();//define default destrctor 
	string evaluate();//define evaluate to return a string
	void print();//define print to return null
	float convert(string &str);//define convert to return a float
	void breakE();//define breakE to return a null
	int checkPresi(char temp);//define checkPresi to return an int
	int getIndex();//define getIndex to return an int
};

#endif /* ARITHMETICEXPRESSION_H_ */

/*
* Name: ?Tianqi Qi, Polly Yao, Shiyu Luo
* MacID: ?qit3, yaos5, luos
* Student Number: 1405930, 1215549, 1317135
* Description: The Addition class evaluates the two pointer expression additions and returns the result as a string
*/

#include "Addition.h"//import Addition header
#include <iostream>//import iostream
using namespace std;////Using namespace std for cout and cin

Addition:: Addition() {//default constructor for Addition

}

Addition:: ~Addition(){//default destructor for Addition

}

string Addition::evaluate(Expression* left, Expression* right){//evaluate addition for the left and right pointers
	//float output = left + right;
	float output = static_cast<ArithmeticExpression*>(left)->convert(left->evaluate()) + static_cast<ArithmeticExpression*>(right)->convert(right->evaluate());	//evaluate addition of the expression pointed to by the left and right pointers and convert evaluated result pointer of the base class Expression to a pointer of a ArithmeticExpression
	return 	std::to_string(output);//convert the result to string and return result
}


void Addition:: print(){//print out addition
	cout << ")" << left << "+" << right << ")";//print addition to screen
}





/*
 Name: ?Tianqi Qi, Polly Yao, Shiyu Luo
 MacID: ?qit3, yaos5, luos
 Student Number: 1405930, 1215549, 1317135
 Description: This is a C++ program that will take in a simple integer expression
 entered by the user and evaluate the expression through recursion. The expression
 will first be error checked for syntax errors then evaluated. The resault of the
 evaluation will be printed on the the screen as well as the expression itself 
 */

#include <iostream>//import iostream
#include <string>//import string
#include<iomanip>//import fix
#include <algorithm>//import algorithm
#include <stdlib.h>//import atof()
#include "Expression.h"//import Expression header 
#include "ArithmeticExpression.h"//import ArithmeticExpression header
#include "Addition.h"//import Addition header
#include "Subtraction.h"//import Subtraction header
#include "Multiplication.h"//import Multiplication header
#include "Division.h"//import Division header
//using std::string;
using namespace std;//Using namespace std for cout and cin

bool checkBrackets(string &temp) {//handle all the error checking for brackets
	int sum = 0;//initialize total number of brackets as 0
	int sumL = 0;//initialize left brackets as 0
	int sumR = 0;//initialize right brackets as 0
	bool check = true;//initialize check as true
	int len = temp.length();//initialize len as the length of the input string
	for (int i = 0; i < len; i++) {//for index between 0 and length of the string
		if (temp[i] == '(') {//if character is a '('
			sum++;//increment total brackets by by 1
			sumL++;//increment left brackets by 1
			if (i != 0) {//if the '(' is not the first character
				if (temp[i - 1] <= '9' && temp[i - 1] >= '0') {//if the character on the left of '(' is not between 1 and 9
					check = false;//change check to false
				}
			}
			if (i != len - 1) {//if index does not equal the second last index
				if (temp[i + 1] == '+' || temp[i + 1] == '*' ||
						temp[i + 1] == '/' || temp[i + 1] == ')') {//if the operator on the right of the current index is an operator or a right bracket
					check = false;}//change check to false
			}
		}
		if (temp[i] == ')') {//if character is ')'
			sum++;//increment total brackets by by 1
			sumR++;//increment right brackets by 1
			if (i != (len - 1)) {//if not at the second last index
				if (temp[i + 1] <= '9' && temp[i + 1] >= '0') {//if the character on the right of ')' is not between 1 and 9
					check = false;//change check to false
				}
			}
			if (i != len) {//if not at the last index
				if (temp[i + 1] == '(') {//if the character on the right of ')' is '('
					check = false;//change check to false
				}
			}
		}
	}
	if (sum % 2 != 0) {//if the total number of brackets is not divisible by 2
		check = false;//change check to false
	} else if (sumL != sumR){//if the number of left and right brackets are not equal
		check = false;//change check to false
	}
	return check; //return check
}

string checkSpace(string &temp) {
	int iSpaces = 0;
	int index = -1;
	std::string op = "no error";

	int len = temp.length();
	for (int i = 0; i < len; i++) {
		if (temp.at(i) == ' '){
			if (temp.at(i + 1) == ' ') {
				iSpaces++;
				index = i;
			}
			else {
				iSpaces++;
				index = i;
				break;
			}

		}
	}
	for (int i = 0; i < len; i++) {
		if (temp.at(i) == ' ') {
			if ((temp.at(index - iSpaces) <= '9' && temp.at(index - iSpaces) >= '0') && temp.at(index + 1) <= '9' && temp.at(index + 1) >= '0') {
				op = "number";
			}
		}
	}
	return op;
}

bool checkExpr(string &temp){//handle the error checking for the expression
	bool check = true;//initialize check as true
	int len = temp.length();//initialize len as the length of expression
	for (int i = 0; i < len - 1; i++) {//for index from 0 to second last index
		if (temp[i] == '+' ||temp[i] == '-' || temp[i] == '*' || temp[i] == '/') {//if the character is an arithmetic operator
			if (temp[i + 1] == ')' || temp[i + 1] == '+' || temp[i + 1] == '-'
					|| temp[i + 1] == '*' || temp[i + 1] == '/') {//if the character to the right of arithmetic operator is another arithmetic operator or ')'
				check = false;//change check to false
			}
		}
	}
	if (temp[len - 1] == '+' || temp[len - 1] == '-' || temp[len - 1] == '*'
			|| temp[len - 1] == '/' || temp[len - 1] == '(') {//if the last character is an arithmetic operator
		check = false;//change check to false
	}
	if (temp[0] == '+' || temp[0] == '-' || temp[0] == '*'|| temp[0] == '/' || temp[0] == ')') {//if the first character is an arithmetic operator
			check = false;//change check to false
		}
	return check;//return check
}


bool errorChecking(string &temp) {//combines the error handling for expression and brackets
	return checkExpr(temp) && checkBrackets(temp);//return the result of error checking through boolean
}



int main() {//main function
	while (true) {//programs runs until user manually exits
		string input;//create string input
		cout << "Please enter an expression: ";//prints message asking for user to enter expression
		getline(cin, input);//take in input
        if (input == "#") {//if user enters '#'
			break;//break out of the while loop and the program exists
		}
		string check2 = checkSpace(input);

		input.erase(std::remove(input.begin(), input.end(), ' '), input.end());//remove the spaces in the expression
		bool check = errorChecking(input);//get result of error checking
        if (!check || check2 == "number") {//if check returns false
            cout << "Expression is not well formed" << endl;//print error message for not well formed expression
		}
		else {//if check returns true
			//calculator will run
			int len = input.length();//initializ lenth as the length of the input
			for (int i = 1; i < len - 2; i++) {//increment index from 1 to third last index
				if (input[i] == ')' && (input[i + 1] == '+' || input[i + 1] == '-' || input[i + 1] == '*' ||
					input[i + 1] == '/') && input[i + 2] == '(') {//if character at index is '(', the following character is 
					//an arithmetic operator and the third character after the index is ')'
					input = "(" + input + ")";//add brackets to the outter most of the expression
					i += 3;//increment index by three
					break;//break out of the for loop
				}

			}
            Expression* e = new ArithmeticExpression(input);//create a derived ArithmeticExpression object e pointed to by the base class pointer to Expression
            e->breakE();//call breakE on e
			e->print();//call print on e
			float output = stof(e->evaluate());//call evaluate on e and convert the result to a float
			std::cout << std::fixed <<std::setprecision(2);//set two decimal place
			cout << '=' << output << endl;//print the result of evaluating the equation
			cout << "Please enter an expression: ";//prints message asking for user to enter expression
			getline(cin, input);//take in input
			if (input == "@") {
				Expression* newE = new ArithmeticExpression(e);
				newE->increment();
				float output = stof(e->evaluate());//call evaluate on e and convert the result to a float
				std::cout << std::fixed << std::setprecision(2);//set two decimal place
				cout << '=' << output << endl;//print the result of evaluating the equation
				delete newE;
			}

			delete e;//destruct e
        }
		
	}
	//int a;//create integer a
	//cin >> a;//take in another user input
	return 0;
}


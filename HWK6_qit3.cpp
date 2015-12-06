//============================================================================
// Name        : HWK6_qit3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
//using std::string;
using namespace std;
bool checkBrackets(string &temp) {
	int sum = 0;
	int sumL = 0;
	int sumR = 0;
	bool check = true;
	int len = temp.length();
	for (int i = 0; i < len; i++) {
		if (temp[i] == '(') {
			sum++;
			sumL++;
			if (i != len - 1) {
				if (temp[i + 1] == '+' || temp[i + 1] == '*' ||
						temp[i + 1] == '/') {
					check = false;}
			}
		}
		if (temp[i] == ')') {
			sum++;
			sumR++;
			if (i != len) {
				if (temp[len - 1] == ')') {check = false;}
			}
		}
	}
	if (sum % 2 != 0) {
		check = false;
	} else if (sumL != sumR){
		check = false;
	}
	return check;
}
bool checkExpr(string &temp){
	bool check = true;
	int len = temp.length();
	for (int i = 0; i < len - 1; i++) {
		if (temp[i] == '+' ||temp[i] == '-' || temp[i] == '*' || temp[i] == '/') {
			if (temp[i + 1] == ')' || temp[i + 1] == '+' || temp[i + 1] == '-'
					|| temp[i + 1] == '*' || temp[i + 1] == '/') {
				check = false;
			}
		}
	}
	if (temp[len - 1] == '+' || temp[len - 1] == '-' || temp[len - 1] == '*'
			|| temp[len - 1] == '/' || temp[len - 1] == '(') {
		check = false;
	}
	if (temp[0] == '+' || temp[0] == '-' || temp[0] == '*'|| temp[0] == '/' || temp[0] == ')') {
			check = false;
		}


	return check;
}



void trimBrackets(string &str) {
	int len = str.length();
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == '(' && str[i + 1] == '(') {
			str.erase(str.begin()+ (i + 1));
		}
		if (str[i] == ')' && str[i + 1] == ')') {
			str.erase(str.begin()+ (i + 1));
		}
	}
}
bool errorChecking(string &temp) {
	return checkExpr(temp) && checkBrackets(temp);
}



int main() {
	while (true) {
		string input;
		cout << "Please enter an expression: ";
		getline(cin, input);
        if (input == "#") {
			break;
		}
		input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
		trimBrackets(input);
		cout << input << endl;
		bool check = errorChecking(input);
        if (!check) {
            cout << "Expression is not well formed" << endl;
        } else {
			//calculator will run
            Expression e = new ArithmeticExpression(input);
            e.breakE();
        }

	}
	return 0;
}


//============================================================================
// Name        : HWK6_qit3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<iomanip>//import fix
#include <algorithm>
#include <stdlib.h>//import atof()
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
						temp[i + 1] == '/' || temp[i + 1] == ')') {
					check = false;}
				cout << "check1: " << check << endl;
			}
		}
		if (temp[i] == ')') {
			sum++;
			sumR++;
			if (i != len) {
				if (temp[i + 1] == '(') {
					check = false;
					cout << "check2: " << check << endl;
				}
			}
		}
	}
	cout << "sumL: " << sumL;
	cout << "sumR: " << sumR;
	cout << "sum: " << sum;
	if (sum % 2 != 0) {
		check = false;
		cout << "check3: " << check << endl;
	} else if (sumL != sumR){
		check = false;
		cout << "check4: " << check << endl;
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
				cout << "check5: " << check << endl;

			}
		}
	}
	if (temp[len - 1] == '+' || temp[len - 1] == '-' || temp[len - 1] == '*'
			|| temp[len - 1] == '/' || temp[len - 1] == '(') {
		check = false;
		cout << "check6: " << check << endl;

	}
	if (temp[0] == '+' || temp[0] == '-' || temp[0] == '*'|| temp[0] == '/' || temp[0] == ')') {
			check = false;
			cout << "check7: " << check << endl;

		}



	return check;
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
		cout << input << endl;
		bool check = errorChecking(input);
        if (!check) {
            cout << "Expression is not well formed" << endl;
        } else {
			//calculator will run
			int len = input.length();
			for (int i = 1; i < len - 2; i++) {
				if (input[i] == ')' && (input[i + 1] == '+' || input[i + 1] == '-' || input[i + 1] == '*' ||
					input[i + 1] == '/') && input[i + 2] == '(') {
					input = "(" + input + ")";
					i += 3;
					break;
				}

			}
            Expression* e = new ArithmeticExpression(input);
            e->breakE();
			e->print();
			float output = stof(e->evaluate());
			std::cout << std::fixed <<std::setprecision(2);//set two decimal place
			cout << '=' << output << endl;
			delete e;
        }
		
	}
	cout << "counter= " << Expression::counter;
	int a;
	cin >> a;
	return 0;
}


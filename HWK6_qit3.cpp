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
using std::string;
using namespace std;

int main() {
	while (true) {
		string input;
		cout << "Please enter an expression: ";
		cin >> input;
		input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
		if (input == "#") {
			break;
		} else {
			cout << "Please enter an expression: ";
			cin >> input;
			bool check = errorChecking(input);
			if (!check) {
				cout << "Expression is not well formed" << endl;
			} else {
				//calculator will run
			}
		}
	}
	return 0;
}

bool errorChecking(string &temp) {
	return checkExpr(temp) && checkBrackets(temp);
}

bool checkExpr(string &temp){
	bool check = true;
	for (int i = 0; i < temp.length() - 1; i++) {
		if (temp.at(i) == "+" || temp.at(i) == "-" || temp.at(i) == "*" || temp.at(i) == "/") {
			if (temp.at(i + 1) == ")" || temp.at(i + 1) == "+" || temp.at(i + 1) == "-"
					|| temp.at(i + 1) == "*" || temp.at(i + 1) == "/") {
				check = false;
			}
		}
	}
	if (temp.at(temp.length() - 1) == "+" || temp.at(temp.length() - 1) == "-" || temp.at(temp.length() - 1) == "*"
			|| temp.at(temp.length() - 1) == "/" || temp.at(temp.length() - 1) == "(") {
		check = false;
	}
	if (temp.at(0) == "+" || temp.at(0) == "-" || temp.at(0) == "*"
				|| temp.at(0) == "/" || temp.at(0) == ")") {
			check = false;
		}


	return check;
}

bool checkBrackets(string &temp) {
	int sum = 0;
	int sumL = 0;
	int sumR = 0;
	bool check = true;
	for (int i = 0; i < temp.length(); i++) {
		if (temp.at(i) == "(") {
			sum++;
			sumL++;
			if (i != temp.length() - 1) {
				if (temp.at(i + 1) == "+" || temp.at(i + 1) == "*" ||
						temp.at(i + 1) == "/") {check = false;}
			}
		}
		if (temp.at(i) == ")") {
			sum++;
			sumR++;
			if (i != temp.length() - 1) {
				if (temp.at(i + 1) == "(") {check = false;}
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

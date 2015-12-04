//============================================================================
// Name        : HWK6_qit3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using std::string;
using namespace std;

int main() {
	while (true) {
		string input;
		cout << "Please enter an expression: ";
		cin >> input;
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

bool errorChecking(string temp) {
	return checkAdd(temp) && checkSub(temp) && checkMul(temp) && checkDiv(temp)
			&& checkBrackets(temp);
}

bool checkAdd(string temp) {
	bool check = true;
	for (int i = 0; i < temp.length() - 1; i++) {
		if (temp.at(i) == "+") {
			if (temp.at(i + 1) == "+" || temp.at(i + 1) == "-"
					|| temp.at(i + 1) == "*" || temp.at(i + 1) == "/") {
				check = false;
			}
		}
	}
	return check;
}

bool checkSub(string temp) {
	bool check = true;
	for (int i = 0; i < temp.length() - 1; i++) {
		if (temp.at(i) == "-") {
			if (temp.at(i + 1) == "+" || temp.at(i + 1) == "-"
					|| temp.at(i + 1) == "*" || temp.at(i + 1) == "/") {
				check = false;
			}
		}
	}
	return check;
}

bool checkMul(string temp) {
	bool check = true;
	for (int i = 0; i < temp.length() - 1; i++) {
		if (temp.at(i) == "*") {
			if (temp.at(i + 1) == "+" || temp.at(i + 1) == "-"
					|| temp.at(i + 1) == "*" || temp.at(i + 1) == "/") {
				check = false;
			}
		}
	}
	return check;
}

bool checkDiv(string temp) {
	bool check = true;
	for (int i = 0; i < temp.length() - 1; i++) {
		if (temp.at(i) == "*") {
			if (temp.at(i + 1) == "+" || temp.at(i + 1) == "-"
					|| temp.at(i + 1) == "*" || temp.at(i + 1) == "/") {
				check = false;
			}
		}
	}
	return check;
}

bool checkBrackets(string temp) {
	int sum = 0;
	int sumL = 0;
	int sumR = 0;
	for (int i = 0; i < temp.length(); i++) {
		if (temp.at(i) == "(") {
			sum++;
			sumL++;
		}
		if (temp.at(i) == ")") {
			sum++;
			sumR++;
		}
	}
	if (sum % 2 != 0) {
		return false;
	} else if (sumL != sumR){
		return false;
	} else {
		return true;
	}
}

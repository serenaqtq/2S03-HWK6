/*
 * ArithmeticExpression.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Division.h"
#include "Multiplication.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void ArithmeticExpression::breakE(){
	int len = input.length();
	//may need to add brackets to prevent (3+5)/(2+3)
	
	cout << "new length: " << len << endl;
	cout << "input: " << input << endl;
	if (input[0] == '(' && input[len - 1] == ')') {
		input = input.substr(1, len - 2);
		
	}
	len = input.length();
	cout << "new length: " << len << endl;
	cout << "input: " << input << endl;
	int index = getIndex();
	cout << index << endl;
	if (index == -1 || index == 100) {
		key = '%';
		cout << "key: " << key;
		return;
	} else{

		key = input[index];
		cout << "key: " << key;
		string subL = input.substr(0, index);
		string subR = input.substr(index + 1, len);
	    left = new ArithmeticExpression(subL);
		left->breakE();
		right = new ArithmeticExpression(subR);
		right->breakE();
	}
	return;
}

int ArithmeticExpression::getIndex() {
	int presi = 4;
	int index = -1;
	int len = input.length();
	if (input[0] == '-') {
		return 100;
	}
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') {
			i++;
			int leftB = 1;
			int rightB = 0;
			while (i < len && leftB != rightB) {
				if (input[i] == '(') { leftB++; }
				if (input[i] == ')') { rightB++; }
				i++;
			}
		}
		if (input[i] > '9' || input[i] < '0') {
			int temp = checkPresi(input[i]);
			if (temp <= presi) {
				index = i;
				presi = temp;}
		}

		
		
	}


	return index;
}

int ArithmeticExpression::checkPresi(char temp) {
	if (temp == '+' || temp == '-') {
		return 1;
	} else if (temp == '*' || temp == '/') {
		return 2;
	} else{
		return 3;
	}
}

ArithmeticExpression::ArithmeticExpression(string &str) :Expression(){
	input = str;
}

ArithmeticExpression::~ArithmeticExpression() {
	delete right;
	delete left;
}

void ArithmeticExpression::print(){
	if (key == '%') {
		cout << '(' << input << ')';
	}
	else {
		left->print();
		cout << key;
		right->print();
	}
}

float ArithmeticExpression::convert(string &str){

	return stof(str);
}

string ArithmeticExpression::evaluate(){
	if (key == '%') {
		return input;
	}
	else {
		if (key == '+') {
			Addition *a = new Addition();
			string str = a->evaluate(left, right);
			delete a;
			return str;
		}
		if (key == '-') {
			Subtraction *s = new Subtraction();
			string str = s->evaluate(left, right);
			delete s;
			return str;
		}
		if (key == '*') {
			Multiplication *m = new Multiplication();
			string str = m->evaluate(left, right);
			delete m;
			return str;
		}
		if (key == '/') {
			Division *d = new Division();
			string str = d->evaluate(left, right);
			delete d;
			return str;
		}
	}
	return "";
}

ArithmeticExpression::ArithmeticExpression(){}





/*
 * ArithmeticExpression.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#include "ArithmeticExpression.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
//void printPrivate(node* Ptr){
//	printPrivate(root);
//}

//void ArithmeticExpression::addLeaf(char key, Expression* Ptr){

//}
//Expression* ArithmeticExpression::createLeaf(string &str){
	//input = str;
	//left = NULL;
	//right = NULL;
//}

void ArithmeticExpression::breakE(){
	int len = input.length();
	//may need to add brackets to prevent (3+5)/(2+3)
	if (input[0] == '(' && input[len - 1] == ')') {
		input.erase(0);
		input.erase(len - 1);
	}
	int index = getIndex();
	cout << index << endl;
	if (index == -1) {
		key = '%';
		cout << "key: " << key;
		return;
	} else {

		char key = input[index];
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
	for (int i = 0; i < len; i++) {
		if (input[i] > '9' || input[i] < '0') {
			int temp = checkPresi(input[i]);
			if (temp <= presi) {
				index = i;
				presi = temp;}
		}

		if (input[i] == '(') {
			i++;
			int leftB = 1;
			int rightB = 0;
			while (i < len && leftB != rightB) {
				if (input[i] == '(') {leftB++;}
				if (input[i] == ')') {rightB++;}
				i++;
			}
		}
	}
	cout << input << endl;
	cout << index << endl;

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

}

float ArithmeticExpression::convert(string &str){
//	if (str[0] == '-') {
//		str.erase(0);
//	}
	return atof(str.c_str());
}

string ArithmeticExpression::evaluate(){
	return "";
}

ArithmeticExpression::ArithmeticExpression(){}





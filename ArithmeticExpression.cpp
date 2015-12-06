/*
 * ArithmeticExpression.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Serena
 */

#include "ArithmeticExpression.h"
#include <stdlib.h>
void printPrivate(node* Ptr){
	printPrivate(root);
}

void ArithmeticExpression::addLeaf(string key, node*Ptr){

}
node* ArithmeticExpression::createLeaf(string &str){
	node* a = new node;
	a->key = str;
	a->left = NULL;
	a->right = NULL;
	return a;
}


ArithmeticExpression::ArithmeticExpression() {}

ArithmeticExpression::~ArithmeticExpression() {
	if(root != NULL){
		if (root->left != NULL) {
			~ArithmeticExpression();
		}
		if (root->right != NULL) {
			~ArithmeticExpression();
		}
		delete root;
	}
}

void ArithmeticExpression::print(){

}

float ArithmeticExpression::convert(string &str){
	if (str[0] == '-') {
		str.erase(0);
	}
	return atof(str.c_str());
}

string ArithmeticExpression::evaluate(){
	int len = input.length();
	bool checkBase = true;
	for (int i = 0; i < len; i++) {
		if (input[i] == '+' || input[i] == '*' || input[i] == '/') {
			checkBase = false;
		}
	}
	if (checkBase) {
		return input;
	} else {
		//recursion
		if (input[0] != '(') {
			int count = 1;
			while (input[count] <= '9' && input[count] >= '0' && count < len) {
				count++;
			}
			if () {}
		} else {}
	}
}



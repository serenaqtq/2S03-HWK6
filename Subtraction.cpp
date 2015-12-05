/*
 * Subtraction.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Polly
 */

#include "Subtraction.h"
#include <iostream>
using namespace std;
int output=0;

Subtraction:: Subtraction() {

}

Subtraction:: ~Subtraction(){

}

string Subtraction::evalute(){
	int output = left - right;
	return output;
}

void Addition:: print(){
	cout << "(" << left << "-" << right << ")" << "=" <<output;
}








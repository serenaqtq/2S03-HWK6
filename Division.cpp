/*
 * Division.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Sanamone
 */

#include "Division.h"
#include <iostream>//Include iostream for inputs and outputs
using namespace std;
int output=0;

Division::Division() {
	// TODO Auto-generated constructor stub

}

Division::~Division() {
	// TODO Auto-generated destructor stub
}

string Division::evaluate(){
	int output = left / right;
	return output;
}

void Division:: print(){
	cout << "(" << left << "/" << right << ")" << "= " << output;

}

/*
 * main.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#include<iostream>
#include "perceptron.h"
#include "back_propagation.h"
#include "hebb.h"
using namespace std;
int main()
{
	Hebb h;
	Perceptron p;
	BackPropagation b;
	h.check_hebb();
	p.check_perceptron();
	b.check_propagation();
return 0;
}




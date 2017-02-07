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
#include "genetic_algorithm.h"
using namespace std;
int main()
{
	GeneticAlgorithm g;
	Hebb h;
	Perceptron p;
	BackPropagation b;

	b.check_propagation();

	g.check_genetic_algorithm();
	h.check_hebb();
	p.check_perceptron();

return 0;
}




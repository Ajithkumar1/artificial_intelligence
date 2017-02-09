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
#include "fset.h"
#include "fmember.h"
using namespace std;
int main()
{
	GeneticAlgorithm g;
	Hebb h;
	Perceptron p;
	BackPropagation b;


	CFuzzyFunction *FuzzySet[3];
	FuzzySet[0] = new CTriangle;
	FuzzySet[1] = new CTriangle;
	FuzzySet[2] = new CTriangle;

	//t = triangle r=trapezoid
	FuzzySet[0]->setInterval(50,100);
	FuzzySet[0]->setMiddle(75,75);
	FuzzySet[0]->setType('t');
	FuzzySet[0]->setName("large");

	FuzzySet[1]->setInterval(25,75);
	FuzzySet[1]->setMiddle(50,50);
	FuzzySet[1]->setType('t');
	FuzzySet[1]->setName("small");

	FuzzySet[2]->setInterval(0,50);
	FuzzySet[2]->setMiddle(25,25);
	FuzzySet[2]->setType('t');
	FuzzySet[2]->setName("Near zero");


	CFuzzyFunction *FuzzySet2[3];

	FuzzySet2[0] = new CTriangle;
	FuzzySet2[1] = new CTriangle;
	FuzzySet2[2] = new CTriangle;

	FuzzySet2[0]->setInterval(1,5);
	FuzzySet2[0]->setMiddle(2.5,2.5);
	FuzzySet2[0]->setType('t');
	FuzzySet2[0]->setName("slow");

	FuzzySet2[1]->setInterval(3,8);
	FuzzySet2[1]->setMiddle(5.5,5.5);
	FuzzySet2[1]->setType('t');
	FuzzySet2[1]->setName("medium");

	FuzzySet2[2]->setInterval(6,10);
	FuzzySet2[2]->setMiddle(8,8);
	FuzzySet2[2]->setType('t');
	FuzzySet2[2]->setName("fast");

	double temperature;
	cout<<"Enter the temperature";
	cin>>temperature;
	double speed;
	cout<<"Enter speed";
	cin>>speed;

	Fset temptest;
	for(int i=0;i<2;i++)
	{
		temptest.insert( FuzzySet[i]->getName(),FuzzySet[i]->getValue(temperature));
	}

	Fset speedtest;
	for(int i=0;i<2;i++)
	{
		speedtest.insert( FuzzySet2[i]->getName(),FuzzySet2[i]->getValue(temperature));
	}

	Fset output = temptest&&speedtest;

	for(int i=0;i<3;i++)
	{
		cout<<FuzzySet[i]->getName()<<FuzzySet[i]->getValue(temperature)<<"\n";
	}


//	Fset mytestset;
//	cout<<"mytestset.empty = "<<mytestset.empty()<<"\n";
//	cout<<"mytestset.count = "<<mytestset.size()<<"\n";
//	mytestset.insert("false",false);
//	mytestset.insert("true",true);
//	mytestset.insert("third",0.33);
//	mytestset.insert("half",0.5);
//	cout<<"mytestset.empty = "<<mytestset.empty()<<"\n";
//	cout<<"mytestset.count = "<<mytestset.size()<<"\n";
//
//	Fset mytest2;
//	mytest2.insert("false",true);
//	mytest2.insert("true",false);
//	mytest2.insert("quarter",0.25);
//	mytest2.insert("half",0.5);
//	cout<<"mytest2.empty = "<<mytest2.empty()<<"\n";
//	cout<<"mytest2.count = "<<mytest2.size()<<"\n";
//
//	Fset andset = mytest2&&mytestset;
//	Fset orset = mytest2||mytestset;
//	Fset notset = !mytestset;
//
//	cout<<"andset[\"false\"] = "<<andset["false"].getval()<<"\n";
//	cout<<"andset[\"quarter\"] = "<<orset["quarter"].getval()<<"\n";
//	cout<<"orset[\"false\"] = "<<orset["false"].getval()<<"\n";
//	cout<<"notset[\"false\"] = "<<notset["false"].getval()<<"\n";

	b.check_propagation();

	g.check_genetic_algorithm();
	h.check_hebb();
	p.check_perceptron();

return 0;
}




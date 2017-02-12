/*
 * main.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#include<iostream>
#include<stdlib.h>
#include "perceptron.h"
#include "back_propagation.h"
#include "hebb.h"
#include "genetic_algorithm.h"
#include "fset.h"
//#include "fmember.h"
#include "fuzzy.h"
#include<string>
#include <boost/program_options.hpp>

using namespace std;


//class MemberShip{
//public :
//	double dLeft, dRight;
//	char   cType;
//	char*  sName;
//	double dMiddle;
//
//public:
//	MemberShip(){};
//
//	~MemberShip(){
//		delete [] sName; sName=NULL;
//	}
//
//	void setInterval(double l,
//			double r)
//	{
//		dLeft=l;
//		dRight=r;
//	}
//
//	void setMiddle(double dL, double dR)
//	{
//		dMiddle=dL;
//	}
//	void setType(char c)
//	{
//		cType=c;
//	}
//
//	void setName(const char* s)
//	{
//		sName = new char[strlen(s)+1];
//		strcpy(sName,s);
//	}
//
//	double getValue(double t)
//	{
//		if(t<=dLeft)
//			return 0;
//		else if(t<dMiddle)
//			return (t-dLeft)/(dMiddle-dLeft);
//		else if(t==dMiddle)
//			return 1.0;
//		else if(t<dRight)
//			return (dRight-t)/(dRight-dMiddle);
//		else
//			return 0;
//	}
//	double max_mebership(double value)
//	{
//		return ((value*(dMiddle - dLeft))+dLeft);
//
//	}
//	char* getName() const
//	{
//		//cout<<sName<<endl;
//		return sName;
//	}
//	char getType(void)const{ return cType;}
//	bool isDotInInterval(double t)
//	{
//		if((t>=dLeft)&&(t<=dRight)) return true; else return false;
//	}
//};

//static MemberShip** member;
//static int in_num;
//Fset out;
//static string *temp_str;
//static double *final_value;
//int num_possibilities;
//int iterate = 0;
//double *process_value;
//static double great;
//static double temp_great;

//struct member_values{
//	double dLeft, dRight, dmiddle_left, dmiddle_right;
//	char   cType;
//	char  sName[10];
//};
//
//
//struct rules{
//	char*  in1;
//	char*  in2;
//	char*  out;
//};


//static void all_possibilities(int d, string str, int *sets) {
//  if (d == in_num) {
//	cout<<str.substr(0, str.length()-1)<<" = ";
//	cin>>temp_str[iterate];
//	final_value[iterate]=temp_great;
//	iterate++;
//	return;
//  }
//
//
//  great = 0;
//  for (int k = 0; k < sets[d]; k++) {
//  	// string temp =str + to_string(vec_double[d][k]) + ",";
//  	// ostringstream strs;
//  	// strs << vec_double[d][k];
//  	// string str_temp = strs.str();
//	  string str_temp = boost::lexical_cast<std::string>(member[d][k].getName());
//	  great = (great > member[d][k].getValue(process_value[d]))?great:member[d][k].getValue(process_value[d]);
//
//	  temp_great = great;
////  	string str_temp = to_string(vec_double[d][k]);
//
//  	all_possibilities(d + 1, str + str_temp + ",",sets);
//  }
//  return;
//}
//
//static void get_value(int d, string str, int *sets) {
//  if (d == in_num) {
//	final_value[iterate]=temp_great;
//	iterate++;
//	return;
//  }
//
//
//  great = 0;
//  for (int k = 0; k < sets[d]; k++) {
//  	// string temp =str + to_string(vec_double[d][k]) + ",";
//  	// ostringstream strs;
//  	// strs << vec_double[d][k];
//  	// string str_temp = strs.str();
//	  string str_temp = boost::lexical_cast<std::string>(member[d][k].getName());
//	  great = (great > member[d][k].getValue(process_value[d]))?member[d][k].getValue(process_value[d]):great;
//
//	  temp_great = great;
////  	string str_temp = to_string(vec_double[d][k]);
//
//  	all_possibilities(d + 1, str + str_temp + ",",sets);
//  }
//  return;
//}

int main()
{
//	GeneticAlgorithm g;
//	Hebb h;
//	Perceptron p;
//	BackPropagation b;
	Fuzzy f;

	f.check_fuzzy();

//	g.check_genetic_algorithm();


//	cout<<"Enter number of inputs";
//	cin>>in_num;
//
//	int sets[in_num];
//	for(int i=0;i<in_num;i++)
//	{
//	    cout<<"Enter number of sets for input "<<i;
//	    cin>>sets[i];
//	}
////	CFuzzyFunction *f_member[in_num][10];
////
////	CFuzzyFunction **f_member;
////	f_member  = (CFuzzyFunction **)malloc(sizeof(CFuzzyFunction *) * in_num);
////	f_member[0] = (CFuzzyFunction *)malloc(sizeof(CFuzzyFunction) * 10 * in_num);
////
////    for(int i = 0; i < in_num; i++)
////    	f_member[i] = (*f_member + 10 * i);
//	//static MemberShip** member;
//	num_possibilities = 1;
//	for(int i=0;i<in_num;i++)
//	{
//		num_possibilities *= sets[i];
//	}
//	cout << "num_possibilities" <<num_possibilities<<endl;
//	temp_str= new string[num_possibilities];
//	final_value= new double[num_possibilities];
//
//
//	member = new MemberShip*[in_num];
//	for(int i = 0; i < in_num; ++i)
//		member[i] = new MemberShip[sets[i]];
//
//	//MemberShip member[in_num][10];
//
//	for(int i=0;i<in_num;i++)
//	{
//    	//f_member[i] = (*f_member + sets[i] * i);
//		for(int j=0;j<sets[i];j++)
//		{
//			//CFuzzyFunction *f_member[in_num][sets[i]];
////			cout<<"sets"<<i<<"="<<sets[i];
//			//f_member[i][j] = new CTriangle;
////			member_values m[i][j];
//			double temp_dLeft;
//			double temp_dRight;
//			double temp_dmiddle_left;
//			double temp_dmiddle_right;
//			char temp_cType;
//			char temp_sName[10];
//			cout<<"dLeft, dRight, dmiddle_left, dmiddle_right, cType, sName for input"<<i;
//			cout <<"i j "<<i<<"and" <<j<<endl;
//			cin>>temp_dLeft;
//			cin>>temp_dRight;
//			cin>>temp_dmiddle_left;
//			cin>>temp_dmiddle_right;
//			cin>>temp_cType;
//			cin>>temp_sName;
//
////			cout<<m[i][j].dLeft;
////			cout<<m[i][j].dRight;
////			cout<<m[i][j].dmiddle_left;
////			cout<<m[i][j].dmiddle_right;
////			cout<<m[i][j].cType;
////			cout<<m[i][j].sName;
//			//cout<<sizeof(member[i][j])<<endl;
//			member[i][j].setInterval(temp_dLeft,temp_dRight);
//			member[i][j].setMiddle(temp_dmiddle_left,temp_dmiddle_left);
//			member[i][j].setType(temp_cType);
//			member[i][j].setName(temp_sName);
////			cout<<"Loop ends"<<endl;
////			double value;
////			cout<<"Enter the input value";
////			Fset input_test[i];
////			input_test[i].insert( f_member[i][j]->getName(),f_member[i][j]->getValue(value));
//		}
//	}
//
//	int output_sets;
//	cout<<"Enter number of sets";
//	cin>>output_sets;
//	MemberShip output_member[output_sets];
//	for(int i=0;i<output_sets;i++)
//	{
//		double temp_dLeft;
//		double temp_dRight;
//		double temp_dmiddle_left;
//		double temp_dmiddle_right;
//		char temp_cType;
//		char temp_sName[10];
//		cout<<"dLeft, dRight, dmiddle_left, dmiddle_right, cType, sName for output"<<endl;
//
//		cin>>temp_dLeft;
//		cin>>temp_dRight;
//		cin>>temp_dmiddle_left;
//		cin>>temp_dmiddle_right;
//		cin>>temp_cType;
//		cin>>temp_sName;
//
//		//			cout<<m[i][j].dLeft;
//		//			cout<<m[i][j].dRight;
//		//			cout<<m[i][j].dmiddle_left;
//		//			cout<<m[i][j].dmiddle_right;
//		//			cout<<m[i][j].cType;
//		//			cout<<m[i][j].sName;
//		//cout<<sizeof(member[i][j])<<endl;
//		output_member[i].setInterval(temp_dLeft,temp_dRight);
//		output_member[i].setMiddle(temp_dmiddle_left,temp_dmiddle_left);
//		output_member[i].setType(temp_cType);
//		output_member[i].setName(temp_sName);
//	}
//
//	process_value = new double[in_num];
//	for(int i=0;i<in_num;i++)
//	{
//		cout<<"Enter the Process Value for "<<i<<endl;
//		cin>>process_value[i];
//	}
//
////
////	rules rule;
////	Fset output;
////	char temp[10];
////	string comb = "00";
////	cout<<"Enter the rules"<<endl;
////	cout<<member[0][0].getName()<<"and"<<member[1][0].getName()<<endl;
////	//cin>>temp;
////	double value;
////	cout<<"Enter the input value"<<endl;
////	cin>>value;
////	cout<<member[0][0].dLeft<<member[1][0].dLeft<<endl;
////	cout<<member[0][0].dRight<<member[1][0].dRight<<endl;
////	cout<<member[0][0].dMiddle<<member[1][0].dMiddle<<endl;
////	cout<<member[0][0].cType<<member[1][0].cType<<endl;
////	cout<<member[0][0].sName<<member[1][0].sName<<endl;
////	cout<<member[0][0].getValue(value)<<"and"<<member[1][0].getValue(value)<<endl;
////	double set_value = (member[0][0].getValue(value)>member[1][0].getValue(value))?member[0][0].getValue(value):member[1][0].getValue(value);
////	output.insert("Hi",set_value);
////
////	cout<<"output[\"false\"] = "<<output["Hi"].getval()<<"\n";
////
////	for(int i=0; i<in_num-1;i++)
////	{
////		for(int j=0;j<sets[i];j++)
////		{
//////			comb = comb +member[i][j].getName();
//////			cout<<member[i][j].getName();
////			for(int k=0;k<sets[i+1];k++)
////			{
//////				cout<<i<<" "<<j<<" "<<k<<endl;
//////				cout<<member[i][j].dLeft<<member[i+1][k].dLeft<<endl;
//////				cout<<member[i][j].dRight<<member[i+1][k].dRight<<endl;
//////				cout<<member[i][j].dMiddle<<member[i+1][k].dMiddle<<endl;
//////				cout<<member[i][j].cType<<member[i+1][k].cType<<endl;
////				comb= comb +" and "+ member[i+1][k].getName();
////				//cout<<"and"<<member[i+1][k].getName()<<endl;
//////				cin>>temp;
//////				double value;
//////				cout<<"Enter the input value";
//////				cin>>value;
//////				cout<<member[i][j].getName()<<"="<<member[i][j].getValue(value)<<" and "<<member[i+1][k].getName()<<"="<<member[i+1][k].getValue(value)<<endl;
//////				double set_value = ((member[i][j].getValue(value))>(member[i+1][k].getValue(value)))?member[i][j].getValue(value):member[i+1][k].getValue(value);
//////				output.insert(temp,set_value);
////				cout<<"comb "<<comb<<endl;
////			}
////		}
////
////	}
////
////
////
////	cout<<"ends top"<<endl;
//	all_possibilities(0,"",sets);
//
//
//	for(int i=0; i<iterate; i++)
//	{
//		cout<<temp_str[i]<<"="<<final_value[i]<<endl;
//		out.insert( temp_str[i],final_value[i]);
//	}
//
//	double max_member = 0;
//	int great_index = 0;
//	for(int i=0; i<iterate; i++)
//	{
//		if(max_member>final_value[i])
//		{
//			max_member = max_member*1;
//			great_index = i;
//		}
//		else{
//			max_member = final_value[i];
//		}
//	}
//
//
//	cout<<"output fuzzy value "<<temp_str[great_index]<<" = "<<max_member<<endl;
//
//	int set_indicator;
//	for(int i=0;i<output_sets;i++)
//	{
//		if(temp_str[great_index]==output_member[i].getName())
//		{
//			set_indicator = i;
//		}
//	}
//	cout<<"Output value"<<output_member[set_indicator].max_mebership(max_member)<<endl;
//
////	cout<<"output["<<temp<<"] = "<<output[temp].getval()<<"\n";
//
////	for(int j=0;j<sets[0];j++)
////	{
////		  cout<<"output[\"name\"] = "<<output[rule.out].getval()<<"\n";
////	}
//
////	for(int i=0; i<sets[0];i++)
////	{
////		for(int j=0;j<in_num;j++)
////		{
////			for(int k=0; k<sets[j];k++)
////			{
////				for(int l=0;l<in_num;l++)
////				{
////
////				}
////			}
////		}
////	}
//
//
//
//
//
////
////	CFuzzyFunction *FuzzySet[3];
////	FuzzySet[0] = new CTriangle;
////	FuzzySet[1] = new CTriangle;
////	FuzzySet[2] = new CTriangle;
////
////	//t = triangle r=trapezoid
////	FuzzySet[0]->setInterval(50,100);
////	FuzzySet[0]->setMiddle(75,75);
////	FuzzySet[0]->setType('t');
////	FuzzySet[0]->setName("large");
////
////	FuzzySet[1]->setInterval(25,75);
////	FuzzySet[1]->setMiddle(50,50);
////	FuzzySet[1]->setType('t');
////	FuzzySet[1]->setName("small");
////
////	FuzzySet[2]->setInterval(0,50);
////	FuzzySet[2]->setMiddle(25,25);
////	FuzzySet[2]->setType('t');
////	FuzzySet[2]->setName("Near zero");
////
////
////	CFuzzyFunction *FuzzySet2[3];
////
////	FuzzySet2[0] = new CTriangle;
////	FuzzySet2[1] = new CTriangle;
////	FuzzySet2[2] = new CTriangle;
////
////	FuzzySet2[0]->setInterval(1,5);
////	FuzzySet2[0]->setMiddle(2.5,2.5);
////	FuzzySet2[0]->setType('t');
////	FuzzySet2[0]->setName("slow");
////
////	FuzzySet2[1]->setInterval(3,8);
////	FuzzySet2[1]->setMiddle(5.5,5.5);
////	FuzzySet2[1]->setType('t');
////	FuzzySet2[1]->setName("medium");
////
////	FuzzySet2[2]->setInterval(6,10);
////	FuzzySet2[2]->setMiddle(8,8);
////	FuzzySet2[2]->setType('t');
////	FuzzySet2[2]->setName("fast");
////
////	double temperature;
////	cout<<"Enter the temperature";
////	cin>>temperature;
////	double speed;
////	cout<<"Enter speed";
////	cin>>speed;
////
////	Fset temptest;
////	for(int i=0;i<2;i++)
////	{
////		temptest.insert( FuzzySet[i]->getName(),FuzzySet[i]->getValue(temperature));
////	}
////
////	Fset speedtest;
////	for(int i=0;i<2;i++)
////	{
////		speedtest.insert( FuzzySet2[i]->getName(),FuzzySet2[i]->getValue(temperature));
////	}
////
////	Fset output1 = temptest&&speedtest;
////
////	for(int i=0;i<3;i++)
////	{
////		cout<<FuzzySet[i]->getName()<<FuzzySet[i]->getValue(temperature)<<"\n";
////	}
////	for(int i=0;i<3;i++)
////	{
////		cout<<FuzzySet2[i]->getName()<<FuzzySet2[i]->getValue(speed)<<"\n";
////	}
//
//
//
//
////	Fset mytestset;
////	cout<<"mytestset.empty = "<<mytestset.empty()<<"\n";
////	cout<<"mytestset.count = "<<mytestset.size()<<"\n";
////	mytestset.insert("false",false);
////	mytestset.insert("true",true);
////	mytestset.insert("third",0.33);
////	mytestset.insert("half",0.5);
////	cout<<"mytestset.empty = "<<mytestset.empty()<<"\n";
////	cout<<"mytestset.count = "<<mytestset.size()<<"\n";
////
////	Fset mytest2;
////	mytest2.insert("false",true);
////	mytest2.insert("true",false);
////	mytest2.insert("quarter",0.25);
////	mytest2.insert("half",0.5);
////	cout<<"mytest2.empty = "<<mytest2.empty()<<"\n";
////	cout<<"mytest2.count = "<<mytest2.size()<<"\n";
////
////	Fset andset = mytest2&&mytestset;
////	Fset orset = mytest2||mytestset;
////	Fset notset = !mytestset;
////
////	cout<<"andset[\"false\"] = "<<andset["false"].getval()<<"\n";
////	cout<<"andset[\"quarter\"] = "<<orset["quarter"].getval()<<"\n";
////	cout<<"orset[\"false\"] = "<<orset["false"].getval()<<"\n";
////	cout<<"notset[\"false\"] = "<<notset["false"].getval()<<"\n";

	//b.check_propagation();


	//h.check_hebb();
	//p.check_perceptron();

	cout<<"ends";
return 0;
}




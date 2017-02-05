/*
 * perceptron.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#include "perceptron.h"


void Perceptron::check_perceptron(){

	int nir,nic,no;
	cout<<"input row";
	cin>>nir;
	cout<<"input column";
	cin>>nic;
	cout<<"Number of Target";
	cin>>no;
	ActivationFunction af;
	float theta = 0.2;
	float alpha = 1;
	float x[nir+1][nic+1];
	float t[no+1];
	int test[nic+1];
	int check=1;
	float w[nic+1];
	float w_new[nic+1];
	float b=0;
	float b_new=0;

	for(int i=1;i<=nir;i++)
	{
		x[i][0]=1;
		test[i]=0;
	}
	cout<<"Enter the inputs";

	for(int i=1;i<=nir;i++)
	{
		for(int j=1;j<=nic;j++)
		{
			cin>>x[i][j];
		}
	}

	cout<<"Enter the targets";

	for(int i=1;i<=nir;i++)
	{
		cin>>t[i];
	}

	for(int i=1;i<=nic;i++)
	{
		w[i]=0;
	}
	float y_in[no+1];
	float y[no+1];
	float summation =0;
	do{
		check = 1;
		for(int i=1;i<=nir;i++)
		{
			for(int j=1;j<=nic;j++)
			{
				summation +=x[i][j]*w[j];
			}
			y_in[i]=b+summation;
			y[i]=af.threshold_theta(y_in[i],theta);
			summation=0;
		}


		for(int i=1;i<=nir;i++)
		{
			cout<<y[i]<<":"<<t[i]<<"Result :";
			if(y[i]!=t[i])
			{
				for(int j=1;j<=nic;j++)
				{
					w_new[j]=w[j]+(alpha*t[i]*x[i][j]);
				}
				b_new=b+(alpha*t[i]);
				test[i]=0;
				cout<<"not equal"<<endl;
			}
			else
			{
				for(int j=1;j<=nic;j++)
				{
					w_new[j]=w[j];
				}
				b_new=b;
				test[i]=1;
				cout<<"equal"<<endl;

			}
		}
		for(int i=1;i<=nic;i++)
		{
			cout<<"weight_check :"<<i<<"="<<w[i]<<endl;
		}
		cout <<"bias :"<<b<<endl;
		for(int i=1;i<=nic;i++)
		{
			check *=test[i];
		}
		cout<<"check :"<<check<<endl;
		for(int i=1;i<=nic;i++)
		{
			w[i]=w_new[i];
		}
		b=b_new;

	}while(check==0);
	cout<<"Trained"<<endl;

//	for(int i=1;i<=nir;i++)
//	{
//		cout<<"weight :"<<i<<"="<<w[i]<<endl;
//	}
//	cout<<"bias :"<<b<<endl;



}


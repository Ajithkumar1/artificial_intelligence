/*
 * hebb.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#include"hebb.h"

void Hebb::check_hebb()
{
	int nir,nic,no;
	cout<<"input row";
	cin>>nir;
	cout<<"input column";
	cin>>nic;
	cout<<"Number of Target";
	cin>>no;
	float x[nir+1][nic+1];
	float t[no+1];
	float w[nic+1];
	float w_new[nic+1];
	float b=0;
	float b_new=0;
	float y[no+1];

	for(int i=1;i<=nir;i++)
	{
		x[i][0]=1;
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

	for(int i=1;i<=nir;i++)
	{
		y[i]=t[i];
	}

	for(int i=1;i<=nic;i++)
	{
		w[i]=0;
	}


	for(int i=1;i<=nir;i++)
	{
		for(int j=1;j<=nic;j++)
		{
			w_new[j]=w[j]+(x[i][j]*y[i]);
			cout<<"Weight_loop :"<<j<<"="<<w[j]<<endl;
			w[i]=w_new[i];
			b=b_new;
		}
		b_new =b+y[i];
	}

	for(int i=1;i<=nic;i++)
	{
		w[i]=w_new[i];
		b=b_new;
		cout<<"Weight :"<<i<<"="<<w[i]<<endl;
	}
	cout<<"bias :"<<b<<endl;
}



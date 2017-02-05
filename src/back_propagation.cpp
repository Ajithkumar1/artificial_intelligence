//============================================================================
// Name        : NeuralNet.cpp
// Author      : Ajith kumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "back_propagation.h"

using namespace std;


void BackPropagation::check_propagation() {
	int ni,no;
	int test = 0;
	ActivationFunction af;
	float x[ni+1];
	float t[no+1];
	float v[ni+1][ni];
	float w[ni+1][no];
	float z_in[ni+1];
	float z[ni+1];
	float summation = 0;
	float y_in[no];
	float y[no];
	float del_k[no+1];
	float del_w[ni][no];
	float alpha = 0.25;
	float del_inj[ni+1];
	float del_j[ni];
	float del_vij[ni][ni];
	float error_range;

	cout<<"No. of inputs";
	cin>>ni;

	x[0]=1;
	z[0]=1;
	for(int i=1;i<=ni;i++)
	{
		cin>>x[i];
	}
	cout<<"No. of targets";
	cin>>no;

	for(int i=1;i<=no;i++)
	{
		cin>>t[i];
	}

	for(int i=0;i<=ni;i++)
	{
		for(int j=1;j<=ni;j++)
		{
			v[i][j]=0;
			cout<<"weight_v"<<i<<j<<"="<<v[i][j]<<endl;
		}
	}

	for(int j=0;j<=ni;j++)
	{
		for(int k=1;k<=no;k++)
		{
			w[j][k]=0;
			cout<<"weight_w"<<j<<k<<"="<<w[j][k]<<endl;
		}
	}

	do{
		//cout<<"do entered"<<endl;

		z[0]=1;
		z_in[0]=0;//check here

		for(int j=1;j<=ni;j++)
		{
			for(int i=1;i<=ni;i++)
			{
				summation += (x[i]*v[i][j]);//summation to zero
			}
			z_in[j]=v[0][j]+summation;
			z[j]=af.sigmoid(z_in[j]);
		}

		//upper layer starts



		summation = 0;
		for(int k=1;k<=no;k++)
		{
			for(int j=1;j<=ni;j++)
			{
				summation += (z[j]*w[j][k]);
			}
			y_in[k]=w[0][k]+summation;
			y[k]=af.sigmoid(y_in[k]);
		}
		//upper layer ends
		//test starts
		for(int p=1;p<=no;p++)
		{
			cout<<"target:"<<p<<","<<t[p]<<endl;
		}
		for(int p=1;p<=no;p++)
		{
			cout<<"output:"<<p<<","<<y[p]<<endl;
		}

		for(int k=1;k<=no;k++)
		{
			if(t[k]!=y[k])
			{
				if(t[k]>y[k])error_range=t[k]-y[k];
				else error_range=y[k]-t[k];
				if(error_range>0.01)
				{
					test = 1;
					cout<<"Not equal"<<endl;
				}
				else
				{
					cout<<"Equal"<<endl;
					test = 0;
				}
			}
			else{
				cout<<"Equal"<<endl;
				test = 0;
			}
		}
		//test ends



		for(int k=1; k<=no;k++)
		{
			del_k[k]=(t[k]-y[k])*(af.sigmoid_derivative(y_in[k]));
		}


		for(int k=1;k<=no;k++)
		{
			for(int j=1;j<=ni;j++)
			{
				del_w[j][k]=alpha*del_k[k]*z[j];
			}
		}

		for(int k=1;k<=no;k++)
		{
			del_w[0][k]=alpha*del_k[k];
		}



		summation =0;
		for(int j=1;j<=ni;j++)
		{
			for(int k=1;k<=no;k++)
			{
				summation +=del_k[k]*w[j][k];
			}
			del_inj[j]=summation;
		}


		for(int j=1;j<=ni;j++)
		{
			del_j[j]=del_inj[j]*af.sigmoid_derivative(z_in[j]);
		}


		for(int i=1;i<=ni;i++)
		{
			for(int j=1;j<=ni;j++)
			{
				del_vij[i][j]=alpha*del_j[j]*x[i];
			}
		}

		for(int j=1;j<=ni;j++)
		{
			del_vij[0][j]=alpha*del_j[j];
		}

		for(int j=0;j<=ni;j++)
		{
			for(int k=1;k<=no;k++)
			{
				w[j][k]=w[j][k]+del_w[j][k];
		//		cout <<"w_weight "<<j<<k<<","<<w[j][k]<<endl;
			}
		}

		for(int i=0;i<=ni;i++)
		{
			for(int j=1;j<=ni;j++)
			{
				v[i][j]=v[i][j]+del_vij[i][j];
		//		cout <<"v_weight "<<i<<j<<","<<v[i][j]<<endl;

			}
		}
		//cout<<"Test:"<<test<<endl;
	}while(test == 1);
	cout<<"Trained";
	cout<<w[0][0];

}

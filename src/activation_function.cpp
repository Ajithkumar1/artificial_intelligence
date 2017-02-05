/*
 * activation_function.cpp
 *
 *  Created on: 04-Feb-2017
 *      Author: ajith
 */

#include"activation_function.h"

float ActivationFunction::identity(float x)
{
	float f = x;
	return f;
}

float ActivationFunction::identity_derivative(float x)
{
	float f = 1;
	return f;
}

float ActivationFunction::binary_step(float x)
{
	float f =(x>=0)?1:0;
	return f;
}

float ActivationFunction::binary_step_derivative(float x)
{
	float f =(x!=0)?0:0; //do_check : https://en.wikipedia.org/wiki/Activation_function
	return f;
}

float ActivationFunction::sigmoid(float x)
{
	float f;
	f=(1/(1+ exp(-x)));
	return f;
}
float ActivationFunction::sigmoid_derivative(float x)
{
	float f;
	f=sigmoid(x)*(1-sigmoid(x));
	return f;
}

float ActivationFunction::tan_h(float x)
{
	float f =tanh(x);
	return f;
}

float ActivationFunction::tan_h_derivative(float x)
{
	float f =1-(tan_h(x)*tan_h(x));
	return f;
}

float ActivationFunction::arctan(float x)
{
	float f= atan(x);
	return f;
}

float ActivationFunction::arctan_derivative(float x)
{
	float f= 1/((x*x)+1);
	return f;
}

float ActivationFunction::soft_sign(float x)
{
	float f= x/(1+ abs(x));
	return f;
}

float ActivationFunction::soft_sign_derivative(float x)
{
	float f= 1/((1+ (abs(x)))*(1+ (abs(x))));
	return f;
}

float ActivationFunction::rectified_linear_unit(float x)
{
	float f=(x>=0)?x:0;
	return f;
}

float ActivationFunction::rectified_linear_unit_derivative(float x)
{
	float f=(x>=0)?1:0;
	return f;
}

float ActivationFunction::leaky_rectified_linear_unit(float x)
{
	float f=(x>=0)?x:(0.01*x);
	return f;
}

float ActivationFunction::leaky_rectified_linear_unit_derivative(float x)
{
	float f=(x>=0)?1:0.01;
	return f;
}

float ActivationFunction::sinusoid(float x)
{
	float f= sin(x);
	return f;
}
float ActivationFunction::sinusoid_derivative(float x)
{
	float f= cos(x);
	return f;
}

float ActivationFunction::threshold_theta(float x, float theta)
{
	float f;
	if(x>theta)
	{
		f=1;
	}
	else if((x<=theta)&&(x>=-theta))
	{
		f=0;
	}
	else {
		f=-1;
	}
	return f;
}



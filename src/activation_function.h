/*
 * activation_function.h
 *
 *  Created on: 04-Feb-2017
 *      Author: ajith
 */

#ifndef ACTIVATION_FUNCTION_H_
#define ACTIVATION_FUNCTION_H_

#include<iostream>
#include<math.h>
#include <stdlib.h>


using namespace std;

class ActivationFunction
{
public:
	float identity(float x);
	float identity_derivative(float x);
	float binary_step(float x);
	float binary_step_derivative(float x);
	float sigmoid(float x);
	float sigmoid_derivative(float x);
	float tan_h(float x);
	float tan_h_derivative(float x);
	float arctan(float x);
	float arctan_derivative(float x);
	float soft_sign(float x);
	float soft_sign_derivative(float x);
	float rectified_linear_unit(float x);
	float rectified_linear_unit_derivative(float x);
	float leaky_rectified_linear_unit(float x);
	float leaky_rectified_linear_unit_derivative(float x);
	float sinusoid(float x);
	float sinusoid_derivative(float x);
	float threshold_theta(float x, float theta);

};




#endif /* ACTIVATION_FUNCTION_H_ */

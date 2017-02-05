/*
 * fbool.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#include <ctime>
#include <cstdlib>
#include "fbool.h"

bool Fbool::randomized=false;

void Fbool::setval(double val)
{
  if (val > 1.0) this->probability = 1.0;
  else if (val < 0.0) this-> probability = 0.0;
  else this->probability = val;
}

void Fbool::setval(bool val)
{
  if (val) this->probability = 1.0;
  else this-> probability = 0.0;
}

double Fbool::getval() const
{
  return this->probability;
}

bool Fbool::tobool() const
{
  return double(rand())/RAND_MAX <= this->probability;
}

Fbool::Fbool(double val)
{
  if (!randomized)
  {
    randomized = true;
    srand(time(0));
  }
  if (val > 1.0) this->probability = 1.0;
  else if (val < 0.0) this-> probability = 0.0;
  else this->probability = val;
}

Fbool::Fbool(bool val)
{
  if (!randomized)
  {
    randomized = true;
    srand(time(0));
  }
  if (val) this->probability = 1.0;
  else this-> probability = 0.0;
}

Fbool::Fbool()
{
  if (!randomized)
  {
    randomized = true;
    srand(time(0));
  }
  this-> probability = 0.0;
}

Fbool Fbool::operator&&(Fbool var)
{
  double temp;
  if (this->probability < var.probability)
    return Fbool(this->probability);
  else
    return Fbool(var.probability);
}

Fbool Fbool::operator&&(bool var)
{
  if (var)
    return Fbool(this->probability);
  else
    return Fbool(false);
}

Fbool Fbool::operator||(Fbool var)
{
  if (this->probability > var.probability)
    return Fbool(this->probability);
  else
    return Fbool(var.probability);
}

Fbool Fbool::operator||(bool var)
{
  if (var)
    return Fbool(true);
  else
    return Fbool(this->probability);
}

Fbool Fbool::operator!()
{
  return Fbool(1.0-this->probability);
}

Fbool operator&&(bool var1, Fbool var2)
{
  return var2&&var1;
}

Fbool operator||(bool var1, Fbool var2)
{
  return var2||var1;
}



/*
 * fset.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#include "fbool.h"
#include "fset.h"
#include <string>

void Fset::insert(const std::string key, double prob)
{
  Fset::setdata.insert(std::pair<std::string,Fbool>(key,prob));
}

void Fset::insert(const std::string key, bool prob)
{
  Fset::setdata.insert(std::pair<std::string,Fbool>(key,prob));
}

int Fset::size()
{
  return Fset::setdata.size();
}

bool Fset::empty()
{
  return Fset::setdata.empty();
}

void Fset::erase(std::string key)
{
  Fset::setdata.erase(key);
}

void Fset::clear()
{
  Fset::setdata.clear();
}

Fset Fset::operator&&(Fset operand)
{
  Fset temp;
  Fbool temp2;
  std::map<std::string,Fbool>::iterator pos1;
  std::map<std::string,Fbool>::iterator pos2;
  for (pos1 = this->setdata.begin(), pos2 = operand.setdata.begin(); pos1 != this->setdata.end() && pos2 != operand.setdata.end();)
  {
    if (pos1->first < pos2->first)
    {
      temp2.setval(false);
      temp.insert(pos1->first,temp2.getval());
      ++pos1;
    }
    else if (pos1->first > pos2->first)
    {
      temp2.setval(false);
      temp.insert(pos2->first,temp2.getval());
      ++pos2;
    }
    else
    {
      temp.insert(pos2->first,((pos1->second)&&(pos2->second)).getval());
      ++pos1;
      ++pos2;
    }
  }
  return temp;
}

Fset Fset::operator||(Fset operand)
{
  Fset temp;
  std::map<std::string,Fbool>::iterator pos1;
  std::map<std::string,Fbool>::iterator pos2;
  for (pos1 = this->setdata.begin(), pos2 = operand.setdata.begin(); pos1 != this->setdata.end() && pos2 != operand.setdata.end();)
  {
    if (pos1->first < pos2->first)
    {
      temp.insert(pos1->first,(pos1->second).getval());
      ++pos1;
    }
    else if (pos1->first > pos2->first)
    {
      temp.insert(pos2->first,(pos2->second).getval());
      ++pos2;
    }
    else
    {
      temp.insert(pos2->first,((pos1->second)||(pos2->second)).getval());
      ++pos1;
      ++pos2;
    }
  }
  return temp;
}

Fset Fset::operator!()
{
  Fset temp;
  std::map<std::string,Fbool>::iterator pos1;
  for (pos1 = this->setdata.begin(); pos1 != this->setdata.end();++pos1)
  {
    temp.insert(pos1->first,(!(pos1->second)).getval());
  }
  return temp;
}

Fbool& Fset::operator[](std::string key)
{
  return Fset::setdata[key];
}



/*
 * fset.h
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#ifndef FSET_H_
#define FSET_H_

#include "fbool.h"
#include <map>
#include <string>

class Fset
{
  std::map<std::string,Fbool> setdata;
public:
  void insert(const std::string,double);
  void insert(const std::string,bool);
  int size();
  bool empty();
  void erase(std::string);
  void clear();
  Fset operator&&(Fset);
  Fset operator||(Fset);
  Fset operator!();
  Fbool& operator[](std::string);
};



#endif /* FSET_H_ */

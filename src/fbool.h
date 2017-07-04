/*
 * fbool.h
 *
 *  Created on: 05-Feb-2017
 *      Author: ajith
 */

#ifndef FBOOL_H_
#define FBOOL_H_

class Fbool{
  static bool randomized;
  double probability;
public:
  void setval(double val);
  void setval(bool val);
  double getval() const;
  bool tobool() const;
  Fbool(double val);
  Fbool(bool val);
  Fbool();
  Fbool operator&&(Fbool);
  Fbool operator&&(bool);
  Fbool operator||(Fbool);
  Fbool operator||(bool);
  Fbool operator!();
};

Fbool operator&&(bool, Fbool);
Fbool operator||(bool, Fbool);



#endif /* FBOOL_H_ */

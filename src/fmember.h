/*
 * fmember.cpp
 *
 *  Created on: 09-Feb-2017
 *      Author: ajith
 */

#include <iostream>
#include <cmath>
#include <cstring>


using namespace std;

class CFuzzyFunction
{
protected :
	double dLeft, dRight;
	char   cType;
	char*  sName;

public:
	CFuzzyFunction(){};
	virtual ~CFuzzyFunction(){ delete [] sName; sName=NULL;}

	virtual void setInterval(double l,
			double r)
	{
		dLeft=l;
		dRight=r;
	}

	virtual void setMiddle( double dL=0,double dR=0)=0;

	virtual void setType(char c)
	{
		cType=c;
	}

	virtual void setName(const char* s)
	{
		sName = new char[strlen(s)+1];
		strcpy(sName,s);
	}

	bool isDotInInterval(double t)
	{
		if((t>=dLeft)&&(t<=dRight)) return true; else return false;
	}

	char getType(void)const{ return cType;}

	char* getName() const
	{
		//cout<<sName<<endl;
		return sName;
	}

	virtual double getValue(double t)=0;
};

class CTriangle : public CFuzzyFunction
{
private:
	double dMiddle;

public:
	void setMiddle(double dL, double dR)
	{
		dMiddle=dL;
	}

	double getValue(double t)
	{
		if(t<=dLeft)
			return 0;
		else if(t<dMiddle)
			return (t-dLeft)/(dMiddle-dLeft);
		else if(t==dMiddle)
			return 1.0;
		else if(t<dRight)
			return (dRight-t)/(dRight-dMiddle);
		else
			return 0;
	}
};

class CTrapezoid : public CFuzzyFunction
{
private:
	double dLeftMiddle, dRightMiddle;

public:
	void setMiddle(double dL, double dR)
	{
		dLeftMiddle=dL; dRightMiddle=dR;
	}

	double getValue(double t)
	{
		if(t<=dLeft)
			return 0;
		else if(t<dLeftMiddle)
			return (t-dLeft)/(dLeftMiddle-dLeft);
		else if(t<=dRightMiddle)
			return 1.0;
		else if(t<dRight)
			return (dRight-t)/(dRight-dRightMiddle);
		else
			return 0;
	}
};


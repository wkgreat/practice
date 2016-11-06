#include<iostream>
#include<cmath>
#include"vector.h"

namespace VECTOR
{
	const double Rad_to_deg = 45 / atan(1.0);

	void Vector::set_x()
	{
		x = mag*std::cos(ang);
	}
	void Vector::set_y()
	{
		y = mag*std::sin(ang);
	}
	void Vector::set_mag()
	{
		mag = std::sqrt(x*x+y*y);
	}
	void Vector::set_ang()
	{
		if(x==0.0 && y==0.0)
			ang=0.0;
		else
			ang=std::atan2(y,x);
	}

	Vector::Vector()
	{
		mode=RECT;
		x=y=mag=ang=0.0;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode=form;
		if(mode==RECT)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}else if(mode==POL)
		{
			mag=n1;
			ang=n2 / Rad_to_deg;
			set_x();
			set_y();
		}else
		{
			std::cout << "Incorrect 3rd Argument to Vector() --";
			std::cout << "Vector set to 0\n";
			mode=RECT;
			x=y=mag=ang=0.0;
		}

	}

	Vector::~Vector(){}

	void Vector::reset(double n1, double n2)
	{
		if(mode==RECT)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}else if(mode==POL)
		{
			mag=n1;
			ang=n2;
			set_x();
			set_y();
		}else
		{
			std::cout << "Incorrect 3rd Argument to Vector() --";
			std::cout << "Vector set to 0\n";
			mode=RECT;
			x=y=mag=ang=0.0;
		}
	}
	
	Vector Vector::operator+(const Vector & vector) const
	{
		return Vector(x+vector.x, y+vector.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x,-y);
	}
	Vector Vector::operator-(const Vector & vector) const
	{
		return Vector(x-vector.x, y-vector.y);
	}
	std::ostream & operator<<(std::ostream & os, const Vector & vector)
	{ 
		if(vector.mode == VECTOR::Vector::RECT)
		{
			os << "Vector RECT (" << vector.x << ", " << vector.y << ")";
			return os;
		}
		else
		{
			os << "Vector POL (" << vector.mag << ", " << vector.ang << ")";
			return os;
		}
	}

	VECTOR::Vector::Mode getMode(int n)
	{
		if(n==0) return VECTOR::Vector::RECT;
		if(n==1) return VECTOR::Vector::POL;
		return VECTOR::Vector::RECT;
	}



}

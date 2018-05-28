#include"circle.hpp"
#include<cmath>
#include <iostream>

Circle :: Circle() :

    r_{1}
    {};

 Circle :: Circle(float r ):
    r_{r}
    {};


double Circle :: get_r() const
{
    return r_;

}


bool Circle:: operator<(Circle const&  c) const//aufgabe 3.6
{
	return r_ < c.r_;
}
bool Circle:: operator>(Circle const&  c) const 
{
	return r_ > c.r_ ;
}
bool Circle:: operator==(Circle const&  c) const
{
	return r_ == c.r_ ;
}







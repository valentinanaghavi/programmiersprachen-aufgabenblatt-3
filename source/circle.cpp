#include"circle.hpp"
#include<cmath>
#include <iostream>
#include"color.hpp"
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>


using namespace std;

Circle :: Circle() :

    r_{1},
    color_{0.0f},
    name_{"-"}
    {};

 Circle :: Circle(float r ):
    r_{r},
    color_{0.0f},
    name_{"-"}
    {};

 Circle :: Circle(float r , Color const& color , std::string const& name) :
    r_{r},
    color_{color},
    name_{name}
    {};


double Circle :: get_r() const
{
    return r_;

}


Color Circle :: get_color() const
{
    return color_;
}

std::string Circle::get_name()const //Aufgabe 3.4
{
    return name_;
}


/*std::ostream& Circle:: print(std::ostream & os)const
{
    os << get_name()<<", " << ", " << get_r()<<", "<<"("<< r_<<","<< g_<<","<< b_<<")\n";
    return os;
}

std:: ostream& operator<<(std::ostream& os, Circle const& c)
{
    return c.print(os);
}*/


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







#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>
#include <string>
#include <iostream>


class Circle
{
    public:
        Circle();
        Circle(float r_ );

        double get_r() const; //radius
        
        bool operator<(Circle const& c) const; //aufgabe 3.6
        bool operator>(Circle const& c) const;
        bool operator==(Circle const& c) const;
        

    private:
        float r_; //Radius
};

#endif //CIRCLE_HPP
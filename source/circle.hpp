#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>
#include <string>
#include <iostream>
#include"color.hpp"

using namespace std;

class Circle
{
    public:
        Circle();
        Circle(float r_ );
        Circle(float r_ , Color const& color , std::string const& name);

        double get_r() const; //radius
        Color get_color() const;
        std::string get_name()const; //aufgabe 3.4

        /*std::ostream& print(std::ostream& os) const;
        std::ostream& operator<<(std::ostream& os,Circle const& c); */
        
        bool operator<(Circle const& c) const; //aufgabe 3.6
        bool operator>(Circle const& c) const;
        bool operator==(Circle const& c) const;
        

    private:
        float r_; //Radius
        Color color_;
        std::string name_;
};

#endif //CIRCLE_HPP
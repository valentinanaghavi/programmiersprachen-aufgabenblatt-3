#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include"color.hpp"
#include"window.hpp"

class Circle
{
    public:
        Circle();
        Circle(float r_ , Vec2 const& mp_, Color const& color);
        
        float get_r() const; //radius
        Vec2 get_mp() const; //mittelpunkt
        Color get_color() const;
        
        float circumference () const;
        void draw (Window const& w) const;
        void draw (Window const& w , Color const& c) const;       
        bool is_inside(Vec2 const& v) const;

    private:
        float r; //Radius
        Vec2 mp; //Mittelpunkt
        Color color_;
};
#endif //CIRCLE_HPP
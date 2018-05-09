#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include"color.hpp"
#include"window.hpp"
class Rectangle
{
    public:
    Rectangle();
    Rectangle(Vec2 const& min , Vec2 const& max, Color const& color);

    Vec2 get_min_() const;
    Vec2 get_max_() const;
    Color get_color() const;


    float circumference () const;
    void draw(Window const& w) const;
    void draw(Window const& w , Color const& c) const;
    bool is_inside(Vec2 const& v) const;

    private:
    Vec2 min_;
    Vec2 max_;
    Color color_;
};
#endif // RECTANGLE_HPP 
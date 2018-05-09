#include"rectangle.hpp"
#include"color.hpp"
#include"window.hpp"
#include "vec2.hpp"
#include<cmath>


Rectangle :: Rectangle() :
    min_{0.0f,0.0f},
    max_{0.0f,0.0f},
    color_{0.0f}
    {};

Rectangle :: Rectangle(Vec2 const& min, Vec2 const& max, Color const& color) :
    min_{min},
    max_{max},
    color_{color}
    {};


Vec2 Rectangle ::  get_min_() const
{
    return min_;
}
Vec2 Rectangle ::  get_max_() const
{
    return max_;
}

Color Rectangle :: get_color() const
{
    return color_;
}

float Rectangle :: circumference() const
{
    return 2 * ((max_.x_ - min_.x_) + (max_.y_ - min_.y_)); //2*(breite+hoehe)
}

void Rectangle :: draw(Window const& w) const
{
    Color col = get_color();
    w.draw_line(min_.x_, min_.y_,min_.x_,max_.y_, col.r_, col.g_ ,col.b_);
    w.draw_line(min_.x_,max_.y_,max_.x_,max_.y_, col.r_, col.g_ , col.b_);
    w.draw_line(max_.x_,max_.y_,max_.x_,min_.y_, col.r_, col.g_ , col.b_);
    w.draw_line(max_.x_,min_.y_,min_.x_,min_.y_, col.r_, col.g_ , col.b_);
}

void Rectangle :: draw(Window const& w , Color const& c) const
{
    w.draw_line(min_.x_, min_.y_,min_.x_,max_.y_, c.r_, c.g_ ,c.b_);
    w.draw_line(min_.x_,max_.y_,max_.x_,max_.y_, c.r_, c.g_ , c.b_);
    w.draw_line(max_.x_,max_.y_,max_.x_,min_.y_, c.r_, c.g_ , c.b_);
    w.draw_line(max_.x_,min_.y_,min_.x_,min_.y_, c.r_, c.g_ , c.b_);
}

bool Rectangle :: is_inside(Vec2 const& v) const
{
    if(v.x_ > min_.x_ && v.x_ < max_.x_ && v.y_ > min_.y_ && v.y_ < max_.y_)
    {
        return true;
    }
    else{
        return false;
    }
}


#include"circle.hpp"
#include"vec2.hpp"
#include"color.hpp"
#include "window.hpp"
#include<cmath>

Circle :: Circle() :

    r{0.0f},
    mp{0.0f,0.0f},
    color_{0.0f}
    {};

 Circle :: Circle(float r_ , Vec2 const& mp_, Color const& color) :
    r{r_},
    mp{mp_},
    color_{color}
    {};



float Circle :: get_r() const
{
    return r;

}

Vec2 Circle :: get_mp() const//mit oder ohne &???
{
    return mp;

}

Color Circle :: get_color() const
{
    return color_;
}

float Circle :: circumference () const
{
    return (2*M_PI*r);
}

void Circle :: draw(Window const& w) const
{
    Vec2 anfang;
    Vec2 ende;
    Color col = get_color();
    for (int i=0; i<=360 ; i++)
    {
        anfang = {(float)cos(i*(2*M_PI/360))*r, (float)sin(i*(2*M_PI/360))*r};
        ende = {(float)cos((i+1)*(2*M_PI/360))*r, (float)sin((i+1)*(2*M_PI/360))*r};

        w.draw_line(anfang.x_ + mp.x_,anfang.y_ + mp.y_,ende.x_ +mp.x_,ende.y_ +mp.y_,col.r_,col.g_,col.b_);
    }
}

void Circle :: draw(Window const& w , Color const& c) const
{
    Vec2 anfang;
    Vec2 ende;
    for (int i=0; i<=360 ; i++)
    {
        anfang = {(float)cos(i*(2*M_PI/360))*r, (float)sin(i*(2*M_PI/360))*r};
        ende = {(float)cos((i+1)*(2*M_PI/360))*r, (float)sin((i+1)*(2*M_PI/360))*r};

        w.draw_line(anfang.x_ + mp.x_,anfang.y_ + mp.y_,ende.x_ +mp.x_,ende.y_ +mp.y_,c.r_,c.g_,c.b_);
    }
}

bool Circle :: is_inside(Vec2 const& v) const 
{
    Vec2 a = v -mp;
    if(sqrt(pow(a.x_, 2)+pow(a.y_ ,2)) <= r)
    {
        return true;
    }
    else
    {
        return false;
    }

}


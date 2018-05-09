#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include"window.hpp"

struct Color
{
    
   // Color()
   // {
    //    r_ = 0.0f;
     //   g_ = 0.0f;
     //   b_ = 0.0f;
    //}
    Color(float r, float g, float b)
    {
        if((r >= 0.0f && r <= 1.0f) && (g >= 0.0f && g <= 1.0f) && (b >= 0.0f && b <= 1.0f))
        {
            r_ = r;
            g_ = g;
            b_ = b;
        }
        else
        {
            r_ = 0.0f;
            g_ = 0.0f;
            b_ = 0.0f;
            std::cout <<"ungueltige eingabe."<<std::endl;
        }
    };

    Color(float zahl)
    {
        if(zahl >= 0.0f && zahl <= 1.0f) 
        {
            r_ = zahl;
            g_ = zahl;
            b_ = zahl;
        }

        else
        {
            r_ = 0.0f;
            g_ = 0.0f;
            b_ = 0.0f;
            std::cout <<"ungueltige eingabe."<<std::endl;
        }
    };

    float r_;
    float g_;
    float b_;

};

#endif // COLOR_HPP
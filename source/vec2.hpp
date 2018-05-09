#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 class definition
struct Vec2 
{
    //TODO Constructors
    Vec2(); //default_constructor
    Vec2(float x , float y); //user_constructor

    float x_;
    float y_;
    float s;

//functions
Vec2& operator +=( Vec2 const& v );
Vec2& operator -=( Vec2 const& v );
Vec2& operator *=( float s );
Vec2& operator /=( float s );
};

//free functions
Vec2 operator +( Vec2 const& u , Vec2 const& v );
Vec2 operator -( Vec2 const& u , Vec2 const& v );
Vec2 operator *( Vec2 const& v , float s );
Vec2 operator /( Vec2 const& v , float s );
Vec2 operator *( float s , Vec2 const& v );

#endif // VEC2_HPP
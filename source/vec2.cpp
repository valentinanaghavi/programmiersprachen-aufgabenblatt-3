#include "vec2.hpp"
#include <iostream>

//default_constructor
Vec2 :: Vec2 ()
{
x_ = 0.0f;
y_ = 0.0f;
}

//user_constructor
Vec2 :: Vec2 (float x, float y)
{
x_ = x;
y_ = y;
}


//functions
Vec2& Vec2 :: operator +=( Vec2 const& v )
{
  x_ += v.x_;
  y_ += v.y_;
  return *this;
}

Vec2& Vec2 :: operator -=( Vec2 const& v )
{
  x_ -= v.x_;
  y_ -= v.y_;
  return *this;
}

Vec2& Vec2 :: operator *=( float s )
{
  x_ *= s;
  y_ *= s;
  return *this;
}

Vec2& Vec2 :: operator /=( float s )
{
  if(s == 0)
  {
  std::cout <<"Bei Division darf man nicht durch 0 teilen!"<<std::endl;
  x_ = 0.0f;
  y_ = 0.0f;
  return *this;
  }
  else{
  x_ /= s;
  y_ /= s;
  return *this;
  }
}


//free functions
Vec2 operator +( Vec2 const& u , Vec2 const& v )
{
  return Vec2(u.x_ + v.x_ , u.y_ + v.y_);
}

Vec2 operator -( Vec2 const& u , Vec2 const& v )
{
   return Vec2(u.x_ - v.x_ , u.y_ - v.y_);
}

Vec2 operator *( Vec2 const& v , float s )
{
   return Vec2(v.x_ * s, v.y_ * s);
}

Vec2 operator /( Vec2 const& v , float s )
{
  if(s == 0)
  {
    std::cout <<"Bei Division darf man nicht durch 0 teilen!"<<std::endl;
    return Vec2(0.0f,0.0f);
  }
  else{

    return Vec2(v.x_ / s, v.y_ / s);
  }
}

Vec2 operator *( float s , Vec2 const& v )
{
    return Vec2(s*v.x_, s* v.y_);
}
 
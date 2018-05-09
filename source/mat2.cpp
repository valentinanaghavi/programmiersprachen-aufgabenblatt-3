#include "mat2.hpp"
#include "vec2.hpp"
#include <math.h>

//default_constructor
Mat2 :: Mat2() :

    spalte1{1.0f,0.0f},
    spalte2{0.0f,1.0f}
{};

//user_constructor
Mat2 :: Mat2( Vec2 const& v , Vec2 const& u) :

     spalte1{v.x_ , v.y_},
     spalte2{u.x_ , u.y_}
{}; 

 Mat2& Mat2 :: operator *=( Mat2 const& m )
 {
     Mat2 multi;
     multi.spalte1.x_ = (spalte1.x_ * m.spalte1.x_)+(spalte2.x_ * m.spalte1.y_);
     multi.spalte1.y_ = (spalte1.y_ * m.spalte1.x_)+(spalte2.y_ * m.spalte1.y_);
     multi.spalte2.x_ = (spalte1.x_ * m.spalte2.x_)+(spalte2.x_ * m.spalte2.y_);
     multi.spalte2.y_ = (spalte1.y_ * m.spalte2.x_)+(spalte2.y_ * m.spalte2.y_);

     spalte1 = multi.spalte1;
     spalte2 = multi.spalte2;
     return *this; 
 }

 float Mat2 :: det() const  //Determinante
{
     return (spalte1.x_ *spalte2.y_) - (spalte1.y_ * spalte2.x_);
    
}






 Mat2 operator *( Mat2 const& m1 , Mat2 const& m2 )
 {
     Mat2 multi;

     multi.spalte1.x_ = (m1.spalte1.x_ *m2.spalte1.x_)+(m1.spalte2.x_ * m2.spalte1.y_);
     multi.spalte1.y_ = (m1.spalte1.y_ * m2.spalte1.x_) + (m1.spalte2.y_ * m2.spalte1.y_);
     multi.spalte2.x_ = (m1.spalte1.x_ * m2.spalte2.x_)+(m1.spalte2.x_ * m2.spalte2.y_);
     multi.spalte2.y_ = (m1.spalte1.y_ * m2.spalte2.x_)+(m1.spalte2.y_ * m2.spalte2.y_);

     return multi;
 }

Vec2 operator *( Mat2 const & m , Vec2 const & v ) //Multiplikation Matrix * Vektor
{
    Vec2 multi;

    multi.x_ = (m.spalte1.x_ * v.x_)+(m.spalte2.x_ * v.y_);
    multi.y_ = (m.spalte1.y_ * v.x_)+(m.spalte2.y_ * v.y_);

    return multi;
}

Vec2 operator *( Vec2 const & v , Mat2 const & m ) //Multiplikation Vektor * Matrix
{
     Vec2 multi;

     multi.x_ = (v.x_ * m.spalte1.x_)+(v.y_ * m.spalte2.x_);
     multi.y_ = (v.x_ * m.spalte1.y_)+(v.y_ * m.spalte2.y_);

    return multi;

}

Mat2 inverse ( Mat2 const & m ) //Inverses berechnen
{
    
    if (m.det() == 0)
    {
        return m;   //betraegt die det = 0 , gibt es kein inverses -> die eig matrix wird zurueckgegeben
    }
    else
    {   
        Mat2 multi;
        float i = 1 / (m.det()); //((m.spalte1.x_ * m.spalte2.y_) - (m.spalte2.x_ * m.spalte1.y_)
        multi.spalte1.x_ = (i * m.spalte2.y_);
        multi.spalte1.y_ = (-i * m.spalte1.y_);
        multi.spalte2.x_ =(-i * m.spalte2.x_);
        multi.spalte2.y_ = (i * m.spalte1.x_) ;
        return multi;
    }
}

Mat2 transpose ( Mat2 const & m ) //transponieren
{
    Mat2 multi;
    multi.spalte1.x_ = m.spalte1.x_ ;
    multi.spalte1.y_ = m.spalte2.x_ ;
    multi.spalte2.x_ = m.spalte1.y_ ;
    multi.spalte2.y_ = m.spalte2.y_ ;
    return multi;
}

Mat2 make_rotation_mat2 ( float phi ) // Rotationsmatrix mit Winkel in Bm
{
    Mat2 multi; //phi in Bogenmaß
    multi.spalte1.x_ = cos(phi) ;
    multi.spalte1.y_ = sin(phi) ;
    multi.spalte2.x_ = -(sin(phi)) ;
    multi.spalte2.y_ = cos(phi) ;
    return multi;

}

 
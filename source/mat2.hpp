#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

struct Mat2 
{

    public:
        //TODO Constructors
        Mat2(); //default_constructor
        Mat2( Vec2 const& v , Vec2 const& u); //user_constructor

        Vec2 spalte1;
        Vec2 spalte2;
        

        
        Mat2& operator *=( Mat2 const& m );

        float det () const ; //Determinante
};

Mat2 operator *( Mat2 const& m1 , Mat2 const& m2 ); //Multiplikation 2 Matrizen

Vec2 operator *( Mat2 const& m , Vec2 const& v ); //Multiplikation Matrix * Vektor
Vec2 operator *( Vec2 const& v , Mat2 const& m ); //Multiplikation Vektor * Matrix
Mat2 inverse ( Mat2 const& m ); //Inverses berechnen
Mat2 transpose ( Mat2 const& m ); //transponieren
Mat2 make_rotation_mat2 ( float phi );

#endif //MAT2_HPP 
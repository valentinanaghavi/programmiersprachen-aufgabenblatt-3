#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include"rectangle.hpp"
#include"circle.hpp"
#include"color.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


    TEST_CASE("Vec2_constructor", "[Vec2]")
    {
     
      SECTION("default_constructor")
      {
        Vec2 vec1;

        REQUIRE(vec1.x_ == Approx(0.0f));
        REQUIRE(vec1.y_ == Approx(0.0f));
      }

      SECTION("user_constructor")
      {
        Vec2 vec2{0.0f,0.0f};
        Vec2 vec3{-1.0f,500.0f};
        Vec2 vec4{2.9f,3.0f};

        REQUIRE(vec2.x_ == Approx(0.0f));
        REQUIRE(vec2.y_ == Approx(0.0f));
        REQUIRE(vec3.x_ == Approx(-1.0f));
        REQUIRE(vec3.y_ == Approx(500.0f));
        REQUIRE(vec4.x_ == Approx(2.9f));
        REQUIRE(vec4.y_ == Approx(3.0f));
      }
    }

    //Operator Funktionen Vektoren

    TEST_CASE("operator_function", "[Vec2]")
    {
      Vec2 vec1{3.0f,5.0f};
      Vec2 vec2{2.1f,3.1f};
      float k = 0.0f;
      float s = 2.0f;
      

      SECTION("+= operator")
      {
        vec1 +=vec2;
        REQUIRE( vec1.x_ == Approx(5.1f));
        REQUIRE( vec1.y_ == Approx(8.1f));
      }

      SECTION("-= operator")
      {
        vec1 -=vec2;
        REQUIRE( vec1.x_ == Approx(0.9f));
        REQUIRE( vec1.y_ == Approx(1.9f));
      }

      SECTION("*= operator")
      {
        vec1 *=s;
        REQUIRE( vec1.x_ == Approx(6.0f));
        REQUIRE( vec1.y_ == Approx(10.0f));
      }

      SECTION("/= operator")
      {
        vec1 /=s;  
        REQUIRE( vec1.x_ == Approx(1.5f));
        REQUIRE( vec1.y_ == Approx(2.5f));

        vec2 /=k;
        REQUIRE( vec2.x_ == Approx(0.0f)); //geteilt durch null
        REQUIRE( vec2.y_ == Approx(0.0f));
      }

    }

      //free functions Vektoren
     TEST_CASE("operator_free_function", "[Vec2]")
     {
        Vec2 vec1{3.0f,5.0f};
        Vec2 vec2{2.1f,3.1f};
        Vec2 vec3;
        Vec2 vec4;
        float k = 0.0f;
        float s = 2.0f;

        SECTION("+ operator")
        {
          vec3 = vec1 + vec2;
          REQUIRE( vec3.x_ == Approx(5.1f));
          REQUIRE( vec3.y_ == Approx(8.1f));
        }

         SECTION("- operator")
        {
          vec3 = vec1 - vec2;
          REQUIRE( vec3.x_ == Approx(0.9f));
          REQUIRE( vec3.y_ == Approx(1.9f));
        }

         SECTION("* operator")
        {
          vec3 = vec1 * s;
          REQUIRE( vec3.x_ == Approx(6.0f));
          REQUIRE( vec3.y_ == Approx(10.0f));
                    
          vec4 = s * vec1;
          REQUIRE( vec3.x_ == Approx(6.0f));
          REQUIRE( vec3.y_ == Approx(10.0f));

        }

        SECTION("/ operator")
        {
          vec3 = vec1 / s;
          REQUIRE( vec3.x_ == Approx(1.5f));
          REQUIRE( vec3.y_ == Approx(2.5f));
          vec4 = vec1 / k;
          REQUIRE( vec4.x_ == Approx(0.0f)); //geteilt durch null ooooder vec zurueckgeben?
          REQUIRE( vec4.y_ == Approx(0.0f));
        }
     }

      TEST_CASE("Mat2_constructor", "[Mat2]")
    {
     
      SECTION("default_constructor")
      {
        Mat2 mat1;

        REQUIRE(mat1.spalte1.x_ == Approx(1.0f) );
        REQUIRE(mat1.spalte1.y_ == Approx( 0.0f) );
        REQUIRE(mat1.spalte2.x_ == Approx( 0.0f) );
        REQUIRE(mat1.spalte2.y_ == Approx( 1.0f) );
      }

      SECTION("user_constructor")
      {
        Vec2 vec1{0.0f,0.0f};
        Vec2 vec2{-2.0f,-2.0f};
        Vec2 vec3{-1.0f,500.0f};
        Vec2 vec4{2.9f,3.0f};

        Mat2 mat1{vec1,vec2};
        Mat2 mat2{vec3,vec4};

        REQUIRE(mat1.spalte1.x_ == Approx(0.0f));
        REQUIRE(mat1.spalte1.y_ == Approx(0.0f));
        REQUIRE(mat1.spalte2.x_ == Approx(-2.0f));
        REQUIRE(mat1.spalte2.y_ == Approx(-2.0f));

        REQUIRE(mat2.spalte1.x_ == Approx(-1.0f));
        REQUIRE(mat2.spalte1.y_ == Approx(500.0f));
        REQUIRE(mat2.spalte2.x_ == Approx(2.9f));
        REQUIRE(mat2.spalte2.y_ == Approx(3.0f));
      }
    }

    TEST_CASE("operator_function_m", "[Mat2]")
    {
        Vec2 vec1{1.0f,3.0f};
        Vec2 vec2{-2.0f,-2.0f};
        Vec2 vec3{-1.0f,500.0f};
        Vec2 vec4{2.9f,3.0f};

        Mat2 mat1{vec1,vec2};
        Mat2 mat2{vec3,vec4};
        Mat2 mat3;

        SECTION(" *= operator _m")
        {
          mat1 *=mat2;
          REQUIRE(mat1.spalte1.x_ == Approx(-1001.0f));
          REQUIRE(mat1.spalte1.y_ == Approx(-1003.0f));
          REQUIRE(mat1.spalte2.x_ == Approx(-3.1f));
          REQUIRE(mat1.spalte2.y_ == Approx(2.7f));
        }

        SECTION("determinante")
        {
          REQUIRE(mat1.det() == Approx(4.0f));
          REQUIRE(mat2.det() == Approx(-1453.0f)); // det<0 ??
          REQUIRE(mat3.det() == Approx(1.0f)); //det der Einheitsmatrix
        }
    }

          //free functions Matrix
     TEST_CASE("operator_free_function_m", "[Mat2]")
     {
        Vec2 vec1{1.0f,3.0f};
        Vec2 vec2{-2.0f,-2.0f};
        Vec2 vec3{-1.0f,500.0f};
        Vec2 vec4{2.9f,3.0f};

        Mat2 mat1{vec1,vec2};
        Mat2 mat2{vec3,vec4};
        Mat2 mat3;
        Mat2 mat4{{0.0f,0.0f},{0.0f,0.0f}};

        SECTION(" * operator _m")
        {
          mat1 *=mat2;
          REQUIRE(mat1.spalte1.x_ == Approx(-1001.0f));
          REQUIRE(mat1.spalte1.y_ == Approx(-1003.0f));
          REQUIRE(mat1.spalte2.x_ == Approx(-3.1f));
          REQUIRE(mat1.spalte2.y_ == Approx(2.7f));

        }

         SECTION(" inverse_m")
        {
          Mat2 mat5 = inverse(mat2);
          REQUIRE(mat5.spalte1.x_ == Approx(-0.00206f));
          REQUIRE(mat5.spalte1.y_ == Approx(0.34412f));
          REQUIRE(mat5.spalte2.x_ == Approx(0.002f));
          REQUIRE(mat5.spalte2.y_ == Approx(0.00069f));
          Mat2 mat6 = inverse(mat4);
          REQUIRE(mat6.spalte1.x_ == Approx(0.0f)); //bei det() = 0 wird die eig Matrix zurueckgegeben
          REQUIRE(mat6.spalte1.y_ == Approx(0.0f));
          REQUIRE(mat6.spalte2.x_ == Approx(0.0f));
          REQUIRE(mat6.spalte2.y_ == Approx(0.0f));
        }
        SECTION(" transpose_m")
        {
          Mat2 mat7 = transpose(mat1);
          REQUIRE(mat7.spalte1.x_ == Approx(1.0f));
          REQUIRE(mat7.spalte1.y_ == Approx(-2.0f));
          REQUIRE(mat7.spalte2.x_ == Approx(3.0f));
          REQUIRE(mat7.spalte2.y_ == Approx(-2.0f));
          Mat2 mat8 = transpose(mat2);
          REQUIRE(mat8.spalte1.x_ == Approx(-1.0f));
          REQUIRE(mat8.spalte1.y_ == Approx(2.9f));
          REQUIRE(mat8.spalte2.x_ == Approx(500.0f));
          REQUIRE(mat8.spalte2.y_ == Approx(3.0f));
          Mat2 mat9 = transpose(mat3);
          REQUIRE(mat9.spalte1.x_ == Approx(1.0f));
          REQUIRE(mat9.spalte1.y_ == Approx(0.0f));
          REQUIRE(mat9.spalte2.x_ == Approx(0.0f));
          REQUIRE(mat9.spalte2.y_ == Approx(1.0f));
          
        }

        SECTION("make_rotation_mat2_m")
        {
          Mat2 mat10 = make_rotation_mat2(0.5235987756f); // pi/6
          REQUIRE(mat10.spalte1.x_ == Approx(0.8660254038f));
          REQUIRE(mat10.spalte1.y_ == Approx(0.5f));
          REQUIRE(mat10.spalte2.x_ == Approx(-0.5f));
          REQUIRE(mat10.spalte2.y_ == Approx(0.8660254038f));
          Mat2 mat11 = make_rotation_mat2(3.141592654f); //pi
          REQUIRE(mat11.spalte1.x_ == Approx(-1.0f));
          REQUIRE(mat11.spalte1.y_ == Approx(0.0f));
          REQUIRE(mat11.spalte2.x_ == Approx(0.0f));
          REQUIRE(mat11.spalte2.y_ == Approx(-1.0f));
          Mat2 mat12 = make_rotation_mat2(1.570796327f); //pi/2
          REQUIRE(mat12.spalte1.x_ == Approx(0.0f));
          REQUIRE(mat12.spalte1.y_ == Approx(1.0f));
          REQUIRE(mat12.spalte2.x_ == Approx(-1.0f));
          REQUIRE(mat12.spalte2.y_ == Approx(0.0f));
        } 

      }

      
TEST_CASE("Rectangle", "[Rectangle]")
      {
        Rectangle rec1;
        Color c = rec1.get_color();
        Rectangle rec2{{300.0f,300.0f},{500.0f,500.0f},{0.0f,0.0f,1.0f}};
        Color d = rec2.get_color();

        SECTION("default_constructor_R")
        {


          REQUIRE(rec1.get_min_().x_ == Approx(0.0f));
          REQUIRE(rec1.get_min_().y_ == Approx(0.0f));
          REQUIRE(rec1.get_max_().x_ == Approx(0.0f));
          REQUIRE(rec1.get_max_().y_ == Approx(0.0f));
          REQUIRE(c.r_ == Approx(0.0f));
          REQUIRE(c.g_ == Approx(0.0f));
          REQUIRE(c.b_ == Approx(0.0f));

        }

        SECTION("user_constructor_R")
        {

          REQUIRE(rec2.get_min_().x_ == Approx(300.0f));
          REQUIRE(rec2.get_min_().y_ == Approx(300.0f));
          REQUIRE(rec2.get_max_().x_ == Approx(500.0f));
          REQUIRE(rec2.get_max_().y_ == Approx(500.0f));
          REQUIRE(d.r_ == Approx(0.0f));
          REQUIRE(d.g_ == Approx(0.0f));
          REQUIRE(d.b_ == Approx(1.0f));

        }

        SECTION("circumference_R")
        {
          REQUIRE(rec1.circumference() == Approx(0.0f));
          REQUIRE(rec2.circumference() == Approx(800.0f));
        }

        SECTION("is_inside_R")
        {
          Vec2 vec1{400.0f,400.0f};
          Vec2 vec2{3000.0f,4000.0f};

          REQUIRE(rec2.is_inside(vec1) == true);
          REQUIRE(rec2.is_inside(vec2) == false);

        }


      }

      TEST_CASE("Circle", "[Circle]")
      {
        Circle cir1;
        Color c = cir1.get_color();
        Circle cir2{100.0f,{400.0f,400.0f},{1.0f,0.0f,0.0f}};
        Color d = cir2.get_color();

        SECTION("default_constructor_C")
        {
          REQUIRE(cir1.get_r() == Approx(0.0f));
          REQUIRE(cir1.get_mp().y_ == Approx(0.0f));
          REQUIRE(cir1.get_mp().x_ == Approx(0.0f));
          REQUIRE(c.r_ == Approx(0.0f));
          REQUIRE(c.g_ == Approx(0.0f));
          REQUIRE(c.b_ == Approx(0.0f));

        }

        SECTION("user_constructor_C")
        {

          REQUIRE(cir2.get_r() == Approx(100.0f));
          REQUIRE(cir2.get_mp().y_ == Approx(400.0f));
          REQUIRE(cir2.get_mp().x_ == Approx(400.0f));
          REQUIRE(d.r_ == Approx(1.0f));
          REQUIRE(d.g_ == Approx(0.0f));
          REQUIRE(d.b_ == Approx(0.0f));

        }

        SECTION("circumference_C")
        {
          REQUIRE(cir1.circumference() == Approx(0.0f));
          REQUIRE(cir2.circumference() == Approx(628.31853f));
        }

        SECTION("is_inside_C")
        {
          Vec2 vec1{400.0f,400.0f};
          Vec2 vec2{3000.0f,4000.0f};

          REQUIRE(cir2.is_inside(vec1) == true);
          REQUIRE(cir2.is_inside(vec2) == false);

        }


      }

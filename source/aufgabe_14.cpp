#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include"color.hpp"
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <iterator> 
using namespace std;


TEST_CASE ("circle_copy","[copy_if]")
{

    std::vector<Circle>circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
    std::vector<Circle>new_circles(3);
    std::copy_if(circles.begin(),circles.end(),new_circles.begin(), [](Circle c) {return c.get_r()>4.0f;});

    REQUIRE(std::all_of(new_circles.begin(), new_circles.end() , [](Circle c) {return c.get_r()>3.0f;}));
}

int main (int argc, char*argv[])
{
return Catch::Session().run(argc,argv);
}
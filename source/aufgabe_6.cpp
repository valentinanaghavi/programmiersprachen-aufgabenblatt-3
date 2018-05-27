#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<algorithm>
#include"circle.hpp"
#include<stdio.h>
#include<vector>
#include <cstdlib> 
#include <iterator> 


using namespace std;




int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

TEST_CASE("circle_sort", "[sort]") //Aufgabe 3.6
{
	std::vector<Circle> sorted_circles{ 1,9,2,5,4,3}; 

	std::sort(sorted_circles.begin(),sorted_circles.end());

	REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

TEST_CASE("circle_sort_lambda", "[sort]") //Aufgabe 3.7
{
	std::vector<Circle> sorted_circles{ 1,9,2,10,4,3}; 

	std::sort(sorted_circles.begin(),  sorted_circles.end(), [] (Circle const& c1,Circle const& c2) { return c1 < c2; });

	REQUIRE (std::is_sorted( sorted_circles.begin(),  sorted_circles.end ()));
}

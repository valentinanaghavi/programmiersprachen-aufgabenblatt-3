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
	std::vector<Circle> sorted_circles{ 1,3,2,5,4,6}; 

	std::sort(sorted_circles.begin(),sorted_circles.end());


	REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

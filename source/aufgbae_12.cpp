#define CATCH_CONFIG_RUNNER
#include<catch.hpp>
#include<algorithm> //std::transform
#include <vector>
#include <functional> //std::plus

TEST_CASE ("filter alle vielfache von drei","[erase]")
{
    std::vector<int>v_1{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
    std::vector<int>v_2{9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
    std::vector<int>v_3(9);

    std::transform (v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), std::plus<int>());

    REQUIRE(std::all_of(v_3.begin(),v_3.end(), [](int i){return i==10;}));
}

int main (int argc, char*argv[])
{
return Catch::Session().run(argc,argv);
}
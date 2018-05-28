#define CATCH_CONFIG_RUNNER
#include<catch.hpp>
#include<cmath>
#include<algorithm>
#include <time.h>
#include <vector>

bool is_multiple_of_3(unsigned int i)
    {
    return (i % 3) == 0;  
    }  

TEST_CASE ("filter alle vielfache von drei","[erase]")
{

    std ::vector<unsigned int> v(100);  //zufaellige Zahlenliste wird erstellt
    srand(time(NULL));
    for (auto& i : v)
    {
        unsigned int zufallz = std :: rand() %100+1;
        i = zufallz;
    }

    v.erase( std::remove_if(v.begin(), v.end(), [](unsigned int const& i){return (i%3)!=0;}), v.end() );

    
    
    REQUIRE (std::all_of(v.begin(), v.end() , is_multiple_of_3));
}

int main (int argc, char*argv[])
{
return Catch::Session().run(argc,argv);
}
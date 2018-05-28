#define CATCH_CONFIG_RUNNER
#include<catch.hpp>
#include<algorithm>
#include <vector>
using namespace std;

bool is_even (int n) 
    {
        return n % 2 == 0; 
    }

template<typename C,typename P>
C filter(C const& con, P const& pred)
{
    C new_con;
    for(auto& x : con)
    {
        if(pred(x))
        {
            new_con.push_back(x);
        }
    }
    return con;
}
TEST_CASE ("is_even","[template]")
{

    std::vector<int> v {1 ,2 ,3 ,4 ,5 ,6};
    std::vector<int>all_even;
    all_even.resize(v.size());                         // allocate space
    all_even = filter(all_even,is_even);
    
    REQUIRE (std::all_of(all_even.begin(), all_even.end() , is_even));
}

int main (int argc, char*argv[])
{
return Catch::Session().run(argc,argv);
}
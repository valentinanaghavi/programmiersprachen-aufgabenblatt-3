#include "aufgabe_2_und_3.hpp"
#include <iostream>
#include <utility>
#include <list>
#include <iterator>
#include <stdio.h>
#include <time.h>
#include <set>
using namespace std;


int main(int argc, char* argv[])
{
    std ::list<unsigned int> random(100);  //zufaellige Zahlenliste wird erstellt
    srand(time(NULL));
    for (auto& i : random)
    {
        unsigned int zufallz = std :: rand() %100+1;
        i = zufallz;
    }

    std::set<unsigned int> number(std::begin(random), std::end(random)); //Sammlung von einzigartigen Schluesseln, die durch Schluessel sortiert werden 
    std::cout << "Unterschiedliche Zahlen: " << number.size()<<std::endl;

    std::cout << "Soviele Zahlen sind in der Liste: " << random.size()<<std::endl; 
    
    std::cout << "Folgende Zahlen sind NICHT in der Liste: " << std::endl; 
    for(int i = 0 ; i < 100 ; i++)
    {
        if (number.count(i) != true) //Abfrage ob die Zahl (mit ihren Haufgikeiten in der Liste) existiert 
        {
            std::cout << "[" << i << "]" ;
        }
    }
    std::cout << std::endl; 


    
    
 
 
    return 0;
 
}
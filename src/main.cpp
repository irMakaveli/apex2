#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <random>
#include "user.hpp"
#include "Bank.hpp"
using namespace std;

void Bank::setuser(user d)
{
    s.push_back(d);
}
int main()
{
    vector<string>s;
    s = getcomand();
    for (size_t i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
    
    if(s[0]=="create")
    {
        user d;
       // d.setusername(s[1]);
 //       d.setip(s[2]);
        
    }
    
    return 0;
}
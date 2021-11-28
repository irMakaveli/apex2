#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <random>
#include "user.hpp"
#include "Bank.hpp"
#include "function.hpp"
using namespace std;

int main()
{
    Bank bank;
    while(true)
    {
    cout<<"Enter your command"<<endl;
    string s,str;
    cin>>s;
    if(s=="create")
    {
        create(bank);
    }
    if(s=="add_ip")
    {
        addip(bank);
    }
    if(s=="renewal")
    {
        renewal(bank);
    }
    if(s=="deposit")
    {
       deposit(bank);
       
    }
    if(s=="withdraw")
    {
       withdraw(bank);
    }
    if(s=="transfer")
    {
        transfer(bank);
    }
    if(s=="add_profits")
    {
        addprofits(bank);
    }
    if(s=="get_loan")
    {

    }
    if(s=="pay_loan")
    {
        
    } 
    print(bank,"s");
    }

    return 0;
}
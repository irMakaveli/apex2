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
    Bank bank(0);
    
    while(true)
    {
        cout<<"Enter your command"<<endl;
        string s;
        cin>>s;
        if(s=="help")
        {
            //help();
        }
        if(s=="create")
        {
            create(bank);
        }
        else if(s=="add_ip")
        {
            addip(bank);
        }
        else if(s=="renewal")
        {
            renewal(bank);
        }
        else if(s=="deposit")
        {
            deposit(bank);
        }
        else if(s=="withdraw")
        {
            withdraw(bank);
        }
        else if(s=="transfer")
        {
            transfer(bank);
        }
        else if(s=="add_profits")
        {
            addprofits(bank);
        }
        else if(s=="get_loan")
        {
            getloan(bank);
        }
        else if(s=="pay_loan")
        {
            payloan(bank);
        }
        else if(s=="exit") 
        {
            break;
        }
        else
        {
            print(bank,s);
        }

    }

    return 0;
}
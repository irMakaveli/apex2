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
  
    Bank bank;
    vector<string>s;
    s = getcomand();
    for (size_t i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<"*"<<endl;
    }
    
    if(s[0]=="create")
    {
        
        user d;
        //d.setusername(bank.getuser() , s[1]);
        if (d.setusername(bank.getuser() , s[1])&& d.setip(bank.getuser(),s) )
        {
            cout<<"user added succesfuly"<<endl;
        }
        else{
            cout<<"wrong information"<<endl;
        }
    }
    if(s[0]=="add_ip")
    {
       int *index = bank.FindUserIndex(s[1],s[2]);
       if (index[0]==-1 || index[2]==-1)
       {
           cout<<"i can not find"<<s[1]<<endl;
       }
       else
       {
           bank.getuser()[index[0]].setip(bank.getuser() , s);
       }
       
    }
    if(s[0]=="renewal")
    {

    }
    if(s[0]=="deposit")
    {
        int * index = bank.FindUserIndex(s[1] , s[2]);
       if (index[0]==-1 || index[2]==-1)
       {
           cout<<"i can not find"<<s[1]<<endl;
       }
       else
       {
           int c;
           stringstream(s[3])>>c;
           bank.getuser()[index[0]].setmoney(c);
       }
        
    }
    if(s[0]=="transfer")
    {

    }
    if(s[0]=="withraw")
    {

        int * index = bank.FindUserIndex(s[1] , s[2]);
       if (index[0]==-1 || index[2]==-1)
       {
           cout<<"i can not find"<<s[1]<<endl;
       }
       else
       {
           int c;
           stringstream(s[3])>>c;
           bank.getuser()[index[0]].getmoney(c);
       }
        
    }
    if(s[0]=="add_profits")
    {

    }
    if(s[0]=="get_loan")
    {

    }
    if(s[0]=="pay_loan")
    {
        
    }

  
    return 0;
}
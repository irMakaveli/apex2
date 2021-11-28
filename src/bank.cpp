#include <iostream>
#include <vector>
#include <string>
#include "Bank.hpp"
using namespace std;
void Bank::setbankmoney(int m)
{
    if(m < 0)
    {
        cout<<"wrong value"<<endl;
        return;
    }
    bankmoney += m;
}
int Bank::getbankmoney()
{
    return this->bankmoney;
}
int Bank::getbankmoney(int m)
{
    if(m > bankmoney )
    {
        cout<<"our bank heve not enough money"<<endl;
        return 0;
    }
    bankmoney -= m;
    return m;
}
int Bank::getusernumber()
{
    return s.size();
}

void Bank::printing(int i)
{
    for(int j = 0 ; j < tr.size(); j++)
    {
        cout<<"j"<<j<<endl;
        cout<<"transaction type : "<<tr[j].transactionmoney(); 
    }
}
void Bank::setTransaction(transaction trs)
{
    tr.push_back(trs);
    
}
vector<transaction>&Bank::gettransaction()
{
    return tr;
}
void Bank::setuser(user d)
{
    s.push_back(d);   
}
int Bank::getuserindex(std::string const & name) const
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getusername()==name)
        {
            return i;
        }
    }
    cout <<"user name not find"<<endl;
    return -1;
}
int Bank::getipindex(std::string const & ip, int index) const
{
    for (size_t i = 0; i< s[index].getip().size(); i++)
    {
        cout<<s[index].getip()[i];  
        cout<<ip;
        if(s[index].getip()[i].find(ip) <= 3)
        {
            cout<<"i"<<i<<endl;
               return i;
        }
    }
    return -1;
}
vector<user>& Bank::getuser() 
{
    return s;
}


#include <iostream>
#include <vector>
#include <string>
#include "Bank.hpp"
using namespace std;
void Bank::setbankmoney(int m)//set kardane mojoodie bank
{
    if(m < 0)
    {
        return;
    }
    bankmoney += m;
}
Bank::Bank(int)//constructor
{
    bankmoney = 0;
}
int Bank::getbankmoney()
{
    return this->bankmoney;
}
int Bank::getbankmoney(int m)//bardasht az bank
{
    if(m > bankmoney )
    {
        cout<<"our bank heve not enough money"<<endl;
        return 0;
    }
    bankmoney -= m;
    return m;
}
int Bank::getusernumber()//tedade moshtari haye bank
{
    return s.size();
}
void Bank::setTransaction(transaction trs)
{
    tr.push_back(trs);
}
vector<transaction>&Bank::gettransaction()
{
    return tr;
}
void Bank::setuser(user d)//add user
{
    s.push_back(d);   
}
int Bank::getuserindex(std::string const & name) const//find index of user
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getusername()==name)//if user find
        {
            return i;//return index
        }
    }
    return -1;//else return wrong value
}
int Bank::getipindex(std::string const & ip, int index) const//find the IP of a user
{
    for (size_t i = 0; i< s[index].getip().size(); i++)
    {
        if(s[index].getip()[i].find(ip) <= 3)
        {
               return i;
        }
    }
    return -1;
}
vector<user>& Bank::getuser()
{
    return s;
}


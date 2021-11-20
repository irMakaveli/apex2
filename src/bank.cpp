#include <iostream>
#include <vector>
#include <string>
#include "Bank.hpp"
using namespace std;
void setbankmoney(int);
int getbankmoney();
int getbankmoney(int);
int getusernumber();
void setuser(user);
transaction * Bank::setTransaction(int money, string str)
{
    transaction tn;
    tn.date = time(NULL);
    tn.money = money;
    tn.type = str;
    tr.push_back(tn);
    return &tr[tr.size()-1];
}
vector<transaction> Bank::gettransaction()
{
    return this->tr;
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
    for (size_t i = 0; i< s.size(); i++)
    {
        if(s[index].getip()[i]==ip)
        {
            return i;
        }
    }
    return -1;
}
vector<user> Bank::getuser() 
{
    return s;
}


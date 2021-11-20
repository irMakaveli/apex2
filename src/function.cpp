#include <iostream>
#include "function.hpp"
#include <vector>
using namespace std;
bool renewal(Bank &bank, int c)
{
    char ch;
    cin>>ch;
    if(ch=='y')
    { 
        if(bank.getuser()[c].getmoney() >= 10000)
        {
            bank.getuser()[c].getmoney(10000);
            bank.setbankmoney(10000);
            bank.getuser()[c].setenddate(2);
        }
        else
        {
            int money = bank.getuser()[c].getmoney();
            bank.getuser()[c].getmoney(money);
            bank.setbankmoney(money);
            bank.getuser()[c].setloan(10000-money);
        }
        return true;
    }
    return false;
}
void brain(string str, vector<string> & v , char ch)
{
    string temp;
    for(int i = 0 ; i <= str.size() ; i++)
    {
        if(str[i] != ch && str[i]!=' ')
        {
            temp+=str[i];
        }
        if(str[i]==ch || str[i]=='\0' || str[i] == ' ')
        {
            v.push_back(temp);
            temp="";
        }   
    }
}

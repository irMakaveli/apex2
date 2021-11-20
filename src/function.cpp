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
            bank.getuser()[c].setloan(10000-money ,true);
        }
        return true;
    }
    return false;
}
vector<string> brain(string str, vector<string> & v , char ch)
{
    string temp;
    for(int i = 0 ; i <= str.size() ; i++)
    {
        
        if(str[i] != ch )
        {
            temp += str[i];
        }
        if(str[i] == ch || str[i]=='\0')
        {
            v.push_back(temp);
            temp="";
        }   
        if(str[i]=='\0')
        break;
    }
    return v;
}
void print(Bank & bank , string s)
{
    if(s.find('.')<= s.size())
    {
        for(int i = 1 ; i <= bank.getusernumber() ; i++)
        {
            if(bank.getipindex(s , i) != -1)
            {
                printuserinfo(bank , i);
                return;
            }
        }
        cout<<"ip not find"<<endl;
        return;
    }
    if(s != "bank")
    {
        for (size_t i = 0; i < bank.getusernumber(); i++)
        {
            if(bank.getuserindex(s) != -1)
            {
                printuserinfo(bank ,  i );
                return;
            }
        }
        cout<<"user not find";
        return ;
    }
}
void printuserinfo(Bank & bank, int i)
{
    cout<<"user name : "<<bank.getuser()[i].getusername()<<endl;
    cout<<"user ip :"<<endl;
    cout<<bank.getuser()[i].getip().size()<<endl;
    for(int j = 1 ; j <= bank.getuser()[i].getip().size() ; j++)
    {
        cout<<bank.getuser()[i].getip()[j-1]<<"\t";
    
        if(j%3==0)
        cout<<endl;
    }
        cout<<endl;

        cout<<"user loan : "<<bank.getuser()[i].getloan()<<endl;
        cout<<"user money : "<<bank.getuser()[i].getmoney()<<endl;
        cout<<"cardnumber : "<<bank.getuser()[i].getcardnumber()<<endl;
        cout<<"accout created "<<(time(NULL)-bank.getuser()[i].getstartdate())/2<<" days ago"<<endl;
        if(bank.getuser()[i].getstatus()==true)
        {
            cout<<"account expiration date : "<<
            (bank.getuser()[i].getenddate()-time(NULL))/2
            <<"days later"<<endl;
        }
        vector<transaction *>d =  bank.getuser()[i].GetTransaction();
        for(int j = 0 ; j < d.size(); j++)
        {
            cout<<"transaction type : "<<d[j]->type<<" date : "<<d[j]->date<<" money : "<<d[j]->money<<endl;
        }
    
}

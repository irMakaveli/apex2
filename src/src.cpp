#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <random>
#include "user.hpp"
#include "function.hpp"
using namespace std;

user::user(int i)
{
    setstartdate();
    setprofitstime();
    this->money=i;
    this->loan=i;
}
void user::Transaction(transaction * trs)
{
    t.push_back(trs);
}
vector<transaction *> user::GetTransaction()
{
    return t;
}
void user::setprofits()
{
    
   if(time(NULL) > getprofitstime() + 30)
   {
       int money = getmoney();
       int profit = (10 * money)/100 + money;
       setmoney(profit);
   } 
}
void user::setprofitstime()
{
    profitstime = time(NULL);
}
int user::getprofitstime()
{
    return this->profitstime;
}
bool user::getstatus() const
{
    if(time(NULL)>getenddate())
    {
        cout<<"tarikh engheza gozasht"<<endl;
        return false;
    }
    else
    {
        return true;
    }
}
int user::getmoney(int i)
{
    if(getstatus()==false)
    {
        return 0;
    }
    if(i > this->money)
    {
        cout<<"you have not enough money"<<endl;
        return 0;
    }
    
        this->money -= i;
        return i;
    
}
void user::setmoney(int m)
{
    if(m >= 0 && m <= 1000000)
    {
        this->money += m;
    }
    else{
        cout<<"wrong variable"<<endl;
    }
}
int user::getmoney()const
{
    return this->money;
}
int user::getenddate()const
{
    return enddate;
}
void user::setenddate(int t)
{
    if(t>0 && t <= 5)//har 1 sal 5 min
    {
        this->enddate+=t*5*60;
    }
    else
    {
        cout<<"wrong value"<<endl;
    }
}
int user::getstartdate()
{
    return this->startdate;
}
void user::setstartdate()
{
    this->startdate = time(NULL);
    setenddate(2);
    return;
}
int user::getcardnumber() const
{
   return this->cardnumber;
}
void user::setcardnumber(vector<user>const &d) 
{
    random_device cn;
    mt19937 eng(cn());
    uniform_int_distribution<int> dist6(1000,9999); // distribution in range [1, 6]
    while(true)
    {
        int c = dist6(eng);
        for(int k = 0 ; k < d.size() ; k++)
        {
            if(d[k].getcardnumber() == c)
            {
                c=0;
                break;
            }
        }
        if(c!=0)
        {
            cardnumber=c;
            break;
        }
    }
}
string user::getusername() const
{
    return this->Username;
}
bool user::setusername(vector<user>const & v,string s)
{
    if(s[0]>='0'&&s[0]<='9')
    {
        cout<<"user name can not start with numbers"<<endl;
        return false;
    }
    for(int i=0 ; i < v.size() ; i++)
    {
        if(s == v[i].getusername())
        {
            cout<<"tekrary"<<endl;
            return false;
        }
    }
    for(int i = 0 ; i<s.size() ; i++)
    {
        if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z' || s[i]>='0'&&s[i]<='9'||s[i]=='_')
        {
            continue;
        }
        else
        {
            cout<<"user name must genareted by a(A) to z(Z) and under_line"<<endl;
            return false;
        }
    }
    this->Username = s;
    return true;
}
vector<string> user::getip() const
{
    return IP;
}
bool user::setip(vector<user>const &v ,vector<string> const & s)
{

    for(int z = 1; z < s.size() ; z++)
    {
        if(s[z].find('.')<=s[1].size())
        {
        vector<string>d;
        brain(s[z],d,'.');
        if(d.size()>4)
        {
            cout<<"not valid IP"<<endl;
            return false;
        }   
        for(int i=0 ; i < v.size() ;i++)
        {
            vector<string>v1=v[i].getip(); 
            for(int j = 0 ; j < v1.size() ;j++)
            {
                if(s[z]==v1[j])
                {
                    cout<<"tekrary"<<endl;
                    return false;
                }
            }
        }
        int c;
        for(int i = 0 ; i<d.size() ;i++)
        {
            stringstream(d[i])>>c;
            if(c>=255 || c <=0)
            {
                cout<<"not suitable number for IP"<<endl;
                return false;
            }
        }
        }
    }
    for (size_t i = 2; i < s.size(); i++)
    {
     IP.push_back(s[i]);
    }
    return true;
}
void user::setloan(int l)
{

}
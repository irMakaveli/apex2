#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <random>
#include "user.hpp"
#include "function.hpp"
using namespace std;
transaction trn;
user::user(int i)
{
    setstartdate();
    this->loan=i;
}
void transaction::settransaction(int i , string s)
{
    date = time(NULL)/2 ;
    money = i;
    type = s;
}
int transaction::transactionmoney()
{
    return money;
}
int transaction::transactiondate()
{
    return date;
}
string transaction::transactiontype()
{
    return type;
}
void user::Transaction(transaction trs)
{
    t.push_back(trs);     
}
vector<transaction > &user::GetTransaction()
{
    return t;
}
void user::setloan(int i, bool b)
{
    if(i < 0)
    {
        cout<<"wrong value"<<endl;
        return;
    }
    if(b == true)
    {
        this->loan += getmoney(i);
        return ;
    }
    else if(i <= 3*getmoney()/4 && b)
    {
        loan += getmoney(i);
        return ;
    }
    else
    {
        cout<<"you have not enough money"<<endl;
        return;
    }
}
bool user::setprofits()
{
    vector<transaction> s;
    s = GetTransaction(); 
    int profits = 10;
    if(getloan()!=0)
    {
        cout<<"first pay your loan"<<endl;
        return false;
    }
    
    int t = time(NULL)/2;
    bool prfit = true;
    int mid=0;
    int count = 0;
    
    for(int i = 0 , j = s.size()-1 ; i<7 ;i++)
    {
        if(t - i>= s[j].transactiondate())
        {
        mid+= s[j].transactionmoney(); 
        count++;
        }
        if(t - i== s[j].transactiondate())
        {
            j--;
            if(j<0)
            break;
        }  
    }
    for(int i = s.size()-1  ;t - 28 >= s[i].transactiondate() && i>=0; i--)
    {
        if(prfit && (s[i].transactiontype()!= "withdraw" && s[i].transactiontype()!= "profits" &&s[i].transactiontype().find("transfer")!=0))
        {
            prfit =true;
        }
        else
        {
            cout<<"false"<<endl;
            prfit = false;
        }
    }
    profits = (prfit) ? 15 : 10;
    if(getmoney() >= 10000000)
    {
        profits+=5;
    }
    for(int  i = s.size()-1 ; t - s[i].transactiondate() <= 60 && i >= 0;i--)
    { 
        if(s[i].transactiontype() == "profits")
        {
            cout<<"you get your profits recently"<<endl;
            return false; 
        }
        else if(s[i].transactiontype() == "loan")
        {
            cout<<"first pay your loan"<<endl;
            return false;
        }
    }
    mid = (mid/count+getmoney())*profits/100;
    setmoney(mid );
    return true;
}
int user::getloan()
{
    return this->loan;
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
        this->enddate= getstartdate()+t*730;
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
    cout<<cardnumber;
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
    return this->IP;
}
bool user::setip(vector<user>const &v ,vector<string> const & s)
{
    for(int z = 1; z < s.size() ; z++)
    {
        vector<string>d;
        brain(s[z],d,'.');
        int dotnumber=0;  
        for(int i = 0; i <s[z].size( );i++)
        {
            if(s[z][i]=='.')
            {
                dotnumber++;
            }
        };   
        if(d.size()>4 || dotnumber +1 != d.size())
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
        for(int i = 0 ; i<d.size() ;i++)//
        {
            for(int j = 0 ; j < d[i].size() ; j++)
            {
                cout<<d[i].size()<<"\t"<<d[i][j]<<endl;
            if(d[i][j]>='0' && d[i][j]<='9')
            {
                stringstream(d[i])>>c;
                if(c>0 && c <=255){continue;}
                else
                {
                    cout<<"not suitable number for IP :"<<"\""<<s[z]<<"\""<<endl;
                    return false;
                }

            }
            else
            {
                cout<<"notttt suitable number for IP :"<<"\""<<s[z]<<"\""<<endl;
                return false;
            }
            }

        }
        
    }
    for (size_t i = 1; i < s.size(); i++)
    {
        IP.push_back(s[i]);
    }
    return true;
}

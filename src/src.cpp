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
    this->money=i;
    this->loan=i;
}
void transaction::settransaction(int i , string s)//transaction info
{
    date = time(NULL) ;
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
bool user::setloan(int i, bool b)
{
    if(loan != 0)
    {
        cout<<"you have a loan \nfirst pay your loan"<<endl;
        return false;
    }
    if(i < 0)//loan must be larger than 0
    {
        cout<<"wrong value"<<endl;
        return false;
    }
    if(b == true)//b = true vaghti estefadeh mishavad ke karbar bekhahad hesabash ra tamdid konad  
    {//va poole kafi nadarad
        this->loan += i;
        return true;
    }
    if(i <= 3*getmoney()/4)
    {
        loan += getmoney(i) + 20*i/100;

        return true;
    }
    else
    {
        cout<<"you have not enough money"<<endl;
        return false;
    }
}
bool user::setprofits()
{
    vector<transaction> s;
    s = GetTransaction(); 
    int profits = 10;//by default
    if(getloan()!=0)
    {
        cout<<"first pay your loan"<<endl;
        return false;
    }
    
    int t = time(NULL);//har 1 rooz 2 sanieh
    bool prfit = true;
    int mid=0;//miangine hesab dar 7 rooze gozashteh
    int count = 0;
    for(int i = 0 , j = s.size()-1 ; i<7 ;i++)//i = rooz 
    {
        if(t - i>= s[j].transactiondate())//t - i yani i rooz ghabl
        {
            if(s[j].transactiontype()== "withdraw")//bardasht baethe kam shodan miangine hesab mishavad
            {
                mid -= s[j].transactionmoney();
                count++;
            }
            if(s[j].transactiontype()=="profits" || s[j].transactiontype()=="deposit" )//sood gereftan miangine hesab ra afzayesh midahad
            {
                mid += s[j].transactionmoney();
                count++;
            }
            if(s[j].transactiontype().find("transfer to")==0)
            {
                mid -= s[j].transactionmoney();
                count++;
            }
            if(s[j].transactiontype().find("transfer from")==0)
            {
                mid += s[j].transactionmoney();
                count++;
            }
            if(s[j].transactiontype()=="pay loan")
            {
                mid -= s[j].transactionmoney();
                count++;
            }
        }
        if(t - i== s[j].transactiondate())
        {
            j--;
            if(j<0)
            break;
        }  
    }
    for(int i = s.size()-1  ;t - 14 >= s[i].transactiondate() && i>=0; i--)//ta vaghti az akharin tarakonesh 7 rooz ya kamtar gozashteh
    {
        if(prfit && (s[i].transactiontype()!= "withdraw" && s[i].transactiontype()!= "profits" &&s[i].transactiontype().find("transfer")!=0))
        {
            prfit =true;//profit = 12
        }
        else
        {
            prfit = false;//profit =10
        }
    }
    profits = (prfit) ? 12 : 10;

    if(getmoney() >= 10000000)
    {
        profits+=5;//soode bishtar
    }
    for(int  i = s.size()-1 ; t - s[i].transactiondate() <= 60 && i >= 0;i--)//agar dar 30 rooze gozashteh 
    { 
        if(s[i].transactiontype() == "profits")//sood pardakht shodeh
        {
            cout<<"you get your profits recently"<<endl;
            return false; //sood variz nakon
        }
        else if(s[i].transactiontype() == "get loan")
        {
            cout<<"first pay your loan"<<endl;
            return false;
        }
    }
    mid = (mid/count)*profits/100;//miangine hesab * sood /100
    setmoney(mid );
    return true;
}
int user::getloan()
{
    return this->loan;
}
int user::getloan(int i)//i toman az vam ra pardakht mikonad
{
    loan = loan -i;
    return i;
}
bool user::getstatus() const//tarikhe engheza ra check mikonad
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
int user::getmoney(int i)//i toman az hesab bardasht mikonad
{
    if(loan!=0)
    {
        cout<<"please pay your loan"<<endl;
        return 0;
    }
    if(getstatus()==false)
    {
        return 0;
    }
    
    if(money - i >=0)//mojoodi bayad bishtar az i bashad
    {
        money =money -  i;
        return i;
    }
    else{
        cout<<"you have not enough money"<<endl;
        return 0;
    }
        
}
void user::setmoney(int m)//varize pool
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
int user::getenddate()const//tarikh engheza 
{
    return enddate;
}
void user::setenddate(int t)//tamdide hesab
{
    if(t>0 && t <= 5)//har 1 rooz 5 sanieh
    {
        this->enddate= getstartdate()+t*720;
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
void user::setcardnumber(vector<user>const &d) //set kardane shomareh hesab 
{
    random_device cn;
    mt19937 eng(cn());
    uniform_int_distribution<int> dist6(1000,9999); // distribution in range 1000 9999
    while(true)
    {
        int c = dist6(eng);//create a number
        for(int k = 0 ; k < d.size() ; k++)
        {
            if(d[k].getcardnumber() == c)//if number is duplicate
            {
                c=0;
                break;//recreate number
            }
        }
        if(c!=0)//if c was not duplicate 
        {
            cardnumber=c;//set card number
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
    if(s[0]>='0'&&s[0]<='9')//user name ba number aghaz nemishavad
    {
        cout<<"user name can not start with numbers"<<endl;
        return false;
    }
    for(int i=0 ; i < v.size() ; i++)
    {
        if(s == v[i].getusername())
        {
            cout<<s<<" is duplicate"<<endl;
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
            cout<<"user name must genareted by a(A) to z(Z) and under_line or numbers"<<endl;
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
    for(int z = 1; z < s.size() ; z++)//z= 0 is username
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
        for(int i=0 ; i < v.size() ;i++)//check mikonad IP tekrary nabashad
        {
            vector<string>v1=v[i].getip(); 
            for(int j = 0 ; j < v1.size() ;j++)
            {
                if(s[z]==v1[j])
                {
                    cout<<"duplicate ip"<<endl;
                    return false;
                }
            }
        }
        int c;
        for(int i = 0 ; i<d.size() ;i++)//
        {
            for(int j = 0 ; j < d[i].size() ; j++)
            {
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
                cout<<"not suitable number for IP :"<<"\""<<s[z]<<"\""<<endl;
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

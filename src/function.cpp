#include <iostream>
#include "function.hpp"
#include <vector>
#include <sstream>
using namespace std;
void create(Bank & bank)
{
    string str;
    cin>>str;
    cout<<"hi"<<endl;
    user d(0);
    vector<string>s1;
    brain(str , s1, ':');
    str = "0";
    int c;
    if(s1.size()>=3&&s1[s1.size()-1].find('.')>s1[s1.size()-1].size())
    {
        str = s1[s1.size()-1];
        s1.pop_back();
        stringstream(str)>>c;
    }
    if(d.setusername(bank.getuser() , s1[0])==true && d.setip(bank.getuser(),s1) )
    { 
        d.setmoney(c);
        d.setcardnumber(bank.getuser());
        bank.setuser(d);
        cout<<"user added succesfuly"<<endl;
    }
    else{
        cout<<"wrong ip or user name"<<endl;
        return;
    }
}
void addip(Bank & bank)
{
    string str;
    cin>>str;
    vector <string>s2;
    brain(str,s2,':');
    int c = bank.getuserindex(s2[0]);
    cout<<c<<"c";
    bank.getuser()[c].setip(bank.getuser() , s2);
}
void renewal(Bank & bank)
{
    string str;
    cin >>str;
    vector <string>s2;
    brain(str,s2,':');
    int c = bank.getuserindex(s2[0]); 
    if(c>= 0 )
    {
        if(bank.getipindex(s2[1], c)>=0)
        {
            if(bank.getuser()[c].getstatus())
            {
                cout<<"tarikh engheza-e hesabe shoma be payan naresideh"<<endl;  
                renewal(bank ,c);
            }
            else
            {
                renewal(bank , c);
            }
        }
    }
}
void deposit(Bank & bank)
{
    string str;
    cin>>str;
    vector<string>s2;
    brain(str , s2 , ':');
    int c = bank.getuserindex(s2[0]);
    if(c >= 0)
    {
        if(bank.getipindex(s2[1] , c) >=0)
        {
           int money ;
           stringstream(s2[2])>>money;
           transaction trs;
           
           
           if(bank.getuser()[c].getstatus()==true)
           {
                trs.settransaction(money , "deposit");
                bank.getuser()[c].setmoney(money);
                bank.setTransaction(trs);
                bank.getuser()[c].Transaction(trs);
           }    
           else if(renewal(bank , c)) 
           {
                bank.getuser()[c].setmoney(money);
                bank.setTransaction(trs);
                bank.getuser()[c].Transaction(trs);
           }            
        }
    }
}
bool renewal(Bank &bank, int c)
{
    cout<<"are you want to pay 10000 and renewal your account? [y/n]"<<endl;
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
void withdraw(Bank & bank)
{
    string str; 
    cin>>str;
    vector<string>s2;
    brain(str , s2 , ':');
    int c = bank.getuserindex(s2[0]);
    if(c >= 0)
    {
        if(bank.getipindex(s2[1] , c) >=0)
        {
            int money ;
            stringstream(s2[2])>>money;
            if(bank.getuser()[c].getstatus())
            {
                bank.getuser()[c].getmoney(money);
            }   
            else if(renewal(bank , c)) 
            {
                bank.getuser()[c].getmoney(money);
            }            
        }
    }
}
void transfer(Bank & bank)
{
    string str;
    cin>>str;
    vector<string> s2;
    brain(str , s2 , ':');
    int c = bank.getuserindex(s2[0]);    
    if(c < 0){return;}
    int c2 = bank.getipindex(s2[1],c);
    if(c2<0){return;}
    int c3;
    if(s2[2].find('.') <= s2[2].size())
    {
        for (size_t i = 0; i < bank.getusernumber(); i++)
        {
            if(bank.getipindex(s2[2] , i)!=-1)
            {
                c3 = i;
                break;
            }
        }
    }
    else
    {
        for(int i = 0 ; i < bank.getusernumber() ; i++)
        {
            if(bank.getuserindex(s2[2]) != -1)
            {
                c3=i;
                break;
            }
        }
        cout<<"user not find"<<endl;
    }
    int c4;
    transaction trs;
    stringstream(s2[3])>>c4;
    string transfers = "";
    bank.getuser()[c].getmoney(c4);
    transfers = "transfer to "+bank.getuser()[c3].getusername();
    trs.settransaction(c4,transfers);
    bank.setTransaction(trs);

    bank.getuser()[c3].setmoney(c4);
    transfers = "transfer from "+ bank.getuser()[c].getusername();
    trs.settransaction(c4 , transfers);
    bank.getuser()[c].Transaction(trs);
    bank.setTransaction(trs);
}
void addprofits(Bank & bank)
{
    string str;
    cin>>str;
    int c = bank.getuserindex(str);
    cout<<c<<endl;
    if(c >= 0)
    {   transaction trs;
        int c1 = bank.getuser()[c].getmoney();
        if(bank.getuser()[c].setprofits())
        {
            int c2 = bank.getuser()[c].getmoney();
            
            //bank.getuser()[c].Transaction(bank.setTransaction(c2-c1 , "profits"));
        }
    }
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
       for(int j = 0 ; j< bank.getuser()[i].GetTransaction().size() ; j++)
       cout<<(bank.getuser()[i].GetTransaction()[j].transactionmoney())<<"++"<<endl;
       
       bank.printing(i);
}

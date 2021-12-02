#include <iostream>
#include "function.hpp"
#include <vector>
#include <sstream>
using namespace std;
void create(Bank & bank)//add a user
{
    string str;
    cin>>str;
    user d(0);
    vector<string>s1;
    brain(str , s1, ':');//separate str
    str = "0";//0 is default money
    int c;
    if(s1.size()>=3&&s1[s1.size()-1].find('.')>s1[s1.size()-1].size())//for same formats ->
    {// username:ip:ip:....:ip:money
        str = s1.back();//s1.back() is money 
        s1.pop_back(); 
        stringstream(str)>>c;
    }
    if(d.setusername(bank.getuser() , s1[0])==true && d.setip(bank.getuser(),s1))//if data is valid
    { 
        d.setmoney(c);
        d.setcardnumber(bank.getuser());
        bank.setuser(d);//add user
        cout<<"user added succesfuly"<<endl;
        return;
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
    int c = bank.getuserindex(s2[0]);//find user index
    bank.getuser()[c].setip(bank.getuser() , s2);//add IP to user IP's
}
void renewal(Bank & bank)
{
    string str;
    cin >>str;
    vector <string>s2;
    brain(str,s2,':');
    int c = bank.getuserindex(s2[0]);//find user
    if(c>= 0 )//if find
    {
        if(bank.getipindex(s2[1], c)>=0)//find IP
        {
            if(bank.getuser()[c].getstatus())
            {
                cout<<"tarikh engheza-e hesabe shoma be payan naresideh"<<endl;  
                renewal(bank ,c);
            }
            else
            {
                cout<<"tarikh engheza-e hesabe shoma be payan resideh"<<endl;  
                renewal(bank , c);
            }
        }
    }
    else{
        cout<<s2[0]<<"not find"<<endl;
    }
}
void deposit(Bank & bank)
{
    string str;
    cin>>str;
    vector<string>s2;
    brain(str , s2 , ':');
    if(s2.size() <= 2)// add_profits username:IP is wrong
    {
        cout<<"wrong command"<<endl;
        return;
    }
    int c = bank.getuserindex(s2[0]);//find user
    if(c >= 0)//if find
    {
        if(bank.getipindex(s2[1] , c) >=0)//if find IP
        {
           int money ;
           stringstream(s2[2])>>money;
           transaction trs;
           if(bank.getuser()[c].getstatus()==true)//check user status
           {
                trs.settransaction(money , "deposit");
                bank.getuser()[c].setmoney(money);//deposit profits
                bank.setTransaction(trs);//set transaction for bank
                bank.getuser()[c].Transaction(trs);// set transacrion for user
           }    
           else if(renewal(bank , c))//if user renew account
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
    cout<<"are you want to pay 100000 and renewal your account for 2 year? [y/n]"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y')
    { 
        if(bank.getuser()[c].getmoney() >= 100000)
        {
            bank.getuser()[c].setenddate(2);
            bank.getuser()[c].getmoney(100000);
            bank.setbankmoney(100000);
        }
        else
        {
            bank.getuser()[c].setenddate(1);
            int money = bank.getuser()[c].getmoney();
            bank.getuser()[c].getmoney(money);
            bank.setbankmoney(money);
            bank.getuser()[c].setloan(money ,true);
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
                bank.getuser()[c].getmoney(money);//bardaasht
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
    if(c < 0){//if user not find
        return;
        cout<<"user not find"<<endl;
    }
    int c2 = bank.getipindex(s2[1],c);
    if(c2<0)//if IP not find
    {
        cout<<"IP not find"<<endl;
        return;
    }
    int c3;
    if(s2[2].find('.') <= s2[2].size())//for format -> username:IP:IP:money
    {
        for (size_t i = 0; i < bank.getusernumber(); i++)
        {
            if(bank.getipindex(s2[2] , i)!=-1)
            {
                c3 = i;
                break;
            }
        }
        cout<<"IP not find"<<endl;
    }
    else//for format -> username:IP:username:money
    {
        c3=bank.getuserindex(s2[2]); 
        if(c3 < 0)
        {
            cout<<"user not find"<<endl;
            return;
        }      
    }
    int c4;
    transaction trs;
    stringstream(s2[3])>>c4;
    string transfers = "";

    bank.getuser()[c].getmoney(c4);//bardasht
    transfers = "transfer to "+ bank.getuser()[c3].getusername();
    trs.settransaction(c4,transfers);
    bank.setTransaction(trs);
    bank.getuser()[c].Transaction(trs);

    bank.getuser()[c3].setmoney(c4);//variz
    transfers = "transfer from "+ bank.getuser()[c].getusername();
    trs.settransaction(c4 , transfers);
    bank.setTransaction(trs);
    bank.getuser()[c3].Transaction(trs);
}
void addprofits(Bank & bank)
{
    string str;
    cin>>str;
    int c = bank.getuserindex(str);
    if(c >= 0)
    {   transaction trs;
        int c1 = bank.getuser()[c].getmoney();
        cout<<c1<<endl;
        if(bank.getuser()[c].setprofits())//agar sood variz shod
        {
            
            int c2 = bank.getuser()[c].getmoney();
            trs.settransaction(c2-c1 , "profits");//c2 -c1 = sood
            bank.setTransaction(trs);
            bank.getuser()[c].Transaction(trs);
        }
    }
}
vector<string> brain(string str, vector<string > &d,char delim)
{
//this function give a string and separat with a delimiter and push back into vector
    string temp;   
    for (size_t i = 0,j =0 ;i <= str.size(); i++)
    {
       
        if(str[i]!=delim && str[i]!='\0' )
        {
            temp+=str[i];
        }
        else if(temp!=""){    

            d.push_back(temp);
            temp.erase();///clear string
        }
    }//end for
 
    return d;
}//end brain
void print(Bank & bank , string s)//print bank info
{
    if(s.find('.')<= s.size())//if s is IP
    {
        for(int i = 1 ; i <= bank.getusernumber() ; i++)
        {
            if(bank.getipindex(s , i) != -1)//find IP
            {
                printuserinfo(bank , i);
                return;
            }
        }
        return;
    }
    else if(s != "bank")//if s is username
    {
            int b = bank.getuserindex(s);
            if(b!= -1)
            {
                cout<<bank.getuserindex(s)<< 0 <<bank.getusernumber()<<endl;
                printuserinfo(bank ,  b );
                return;
            }
    }
    else if(s == "bank")//if s = bank then print all info
    {
        cout<<"bank's money : "<<bank.getbankmoney()<<endl;
        cout<<"bank's coustomers : "<<bank.getusernumber()<<endl;
        for(int i = 0 ; i < bank.getuser().size(); i++)
        {
            printuserinfo(bank , i);
        }
        return;
    }
    //else if s is cardnumber
        int c ;
        stringstream(s)>>c;
        for(int i =  0 ;i< bank.getuser().size() ;i++)
        {
            if(bank.getuser()[i].getcardnumber() == c)
            {
                printuserinfo(bank , i);
                return;
            }
        }
        
    
    cout<<"not related result for : "<<s<<endl;//else
}
void printuserinfo(Bank & bank, int i)
{
    cout<<"user name : "<<bank.getuser()[i].getusername()<<endl;
    cout<<"user ip :"<<endl;
    for(int j = 0 ; j < bank.getuser()[i].getip().size() ; j++)
    {
        cout<<bank.getuser()[i].getip()[j]<<"\t";
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
       cout<<"transaction type : " <<bank.getuser()[i].GetTransaction()[j].transactiontype()
           <<"transaction money : "<<bank.getuser()[i].GetTransaction()[j].transactionmoney()
           <<"transaction date : " <<time(NULL)/2-bank.getuser()[i].GetTransaction()[j].transactiondate()/2
           <<"days ago"<<endl;
       
}
void getloan(Bank & bank)
{
    string str;
    cin>>str;
    vector<string>s1;
    brain(str , s1,':');
    int c = bank.getuserindex(s1[0]);
    if(c < 0)
    {
        cout<<s1[0]<<"not find"<<endl;
        return;
    }
    int c1 = bank.getipindex(s1[1] , c);
    if(c1 < 0)
    {
        cout<<"IP not find"<<endl;
        return;
    }
    int c2 ;
    stringstream(s1[2])>>c2;
    if(bank.getbankmoney()< c2)
    {
        cout<<"the bank have not enought money"<<endl;
        return;
    }
    else if(bank.getuser()[c].setloan(c2, false))
    {
        transaction trs;
        trs.settransaction(c2 , "getloan");
        bank.setTransaction(trs);
        bank.getuser()[c].Transaction(trs);
        bank.getbankmoney(c2);
        cout<<"you now have loan"<<endl;
    }
}
void payloan(Bank & bank)
{
    string str;
    cin>>str;
    vector<string>s1;
    brain(str , s1 ,':');
    int c = bank.getuserindex(s1[0]);
    if(c < 0)
    {
        cout<<s1[0]<<"not find"<<endl;
        return;
    }
    int c2 ;
    stringstream(s1[1])>>c2;
    if(bank.getuser()[c].getloan()< c2)
    {
        bank.getuser()[c].getloan(c2 - bank.getuser()[c].getloan());
        bank.setbankmoney(c2);
        transaction trs;
        trs.settransaction(c2-bank.getuser()[c].getloan() , "payloan");
        return;
    }
}
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <random>
#include "user.hpp"
#include "Bank.hpp"
#include "function.hpp"
using namespace std;
void Bank::setuser(user d)
{
    s.push_back(d);
    
}
int main()
{
  
    Bank bank;
    while(true)
    {
    cout<<"enter your command"<<endl;
    string s,str;
    cin>>s;
    if(s=="create")
    {
        cin>>str;
        cout<<"hi"<<endl;
        user d(0);
        vector<string>s1;
        brain(str , s1, ':');
        if (d.setusername(bank.getuser() , s1[0])==true && d.setip(bank.getuser(),s1) )
        {
            d.setcardnumber(bank.getuser());
            bank.setuser(d);
            cout<<"user added succesfuly"<<endl;
        }
        else{
            cout<<"wrong information"<<endl;
        }
    }
    if(s=="add_ip")
    {
       cin>>str;
       vector <string>s2;
       brain(str,s2,':');
       int c = bank.getuserindex(s2[0]);
       cout<<c<<"c";
       bank.getuser()[c].setip(bank.getuser() , s2);
    }
    if(s=="renewal")
    {
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
    if(s=="deposit")
    {
       cin>>str;
       vector<string>s2;
       brain(str , s2 , ':');
       int c = bank.getuserindex(s2[0]);
       if(c >= 0)
       {
           if(bank.getipindex(s2[1] , c) >=0)
           {cout<<"k";
               int money ;
               stringstream(s2[2])>>money;
               if(bank.getuser()[c].getstatus()==true)
               {
                   bank.getuser()[c].setmoney(money);
                   cout<<money<<endl;
               }   
               else if(renewal(bank , c)) 
               {
                   bank.getuser()[c].setmoney(money);
               }            
           }
       }
    }
    if(s=="withdraw")
    {
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
    if(s=="transfer")
    {
        cin>>str;
        vector<string> s2;
        brain(str , s2 , ':');
        int c = bank.getuserindex(s2[0]);    
        if(c >= 0){}
        int c2 = bank.getipindex(s2[1],c);
        if(c2>=0){}
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
        }
        int c4;
        stringstream(s2[3])>>c4;
        string transfers = "";
        bank.getuser()[c].getmoney(c4);
        transfers = "transfer to "+bank.getuser()[c3].getusername();
        bank.getuser()[c].Transaction(bank.setTransaction(c4 , transfers ));
        bank.getuser()[c3].setmoney(c4);
        transfers = "transfer from "+ bank.getuser()[c].getusername();
        bank.getuser()[c3].Transaction(bank.setTransaction(c4 , transfers));
    }
    if(s=="add_profits")
    {
        cin>>str;
        int c = bank.getuserindex(str);
        if(c >= 0)
        {
            int c1 = bank.getuser()[c].getmoney();
            if(bank.getuser()[c].setprofits())
            {
                int c2 = bank.getuser()[c].getmoney();
                bank.getuser()[c].Transaction(bank.setTransaction(c2-c1 , "profits"));
            }
        }

    }
    if(s=="get_loan")
    {

    }
    if(s=="pay_loan")
    {
        
    } 
    print(bank,"s");
    }

    return 0;
}
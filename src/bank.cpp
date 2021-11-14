#include <iostream>
#include <vector>
#include <string>
#include "Bank.hpp"
using namespace std;
void setprofits(int);
int getprofits();
void setbankmoney(int);
int getbankmoney();
int getbankmoney(int);
int getusernumber();
void setuser(user);
vector<user> Bank::getuser() 
{
    return this->s;
}
int * Bank::FindUserIndex(std::string un,std::string ip)
{
    int index[2]={-1,-1};
    for (size_t i = 0; i < s.size(); i++)
    {
        if(un==s[i].getusername())
        {
            
            for (size_t j = 0; j < s[i].getip().size(); j++)
            {
                if(s[i].getip()[j]==ip)
                {
                    index[0] = i;
                    index[1]=j;
                    return index;
                }
            }
            cout<<"your ip not find"<<endl;
            return index;
        }        
        cout<<"user name not find"<<endl;
        return index;
    }
    
}
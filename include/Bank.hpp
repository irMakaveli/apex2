#ifndef BANK_HPP
#define BANK_HPP
#include<vector>
#include "user.hpp"
class Bank
{
    private:
    std::vector<user> s;
    int bankmoney;
    int profits;
    public:
    void setprofits(int);
    int getprofits();
    void setbankmoney(int);
    int getbankmoney();
    int getbankmoney(int);
    int getusernumber();
    void setuser(user);
    std::vector<user> getuser();
    int * FindUserIndex(std::string un,std::string ip);
};
#endif // !BANK_HPP

#ifndef BANK_HPP
#define BANK_HPP
#include<vector>
#include "user.hpp"
struct transaction
{
    int money;
    int date;
    string type="NULL";
};
class Bank
{
    private:
    std::vector<user> s;
    int bankmoney;
    std::vector<transaction> tr;
    public:
    std::vector<transaction> gettransaction();
    transaction * setTransaction(int , std::string);
    void setbankmoney(int);
    int getbankmoney();
    int getbankmoney(int);
    int getusernumber();
    void setuser(user);
    int getuserindex(std::string const &) const;
    int getipindex(std::string const & , int) const;
    std::vector<user> getuser();
};
#endif // !BANK_HPP

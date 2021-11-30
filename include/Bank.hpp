#ifndef BANK_HPP
#define BANK_HPP
#include<vector>
#include "user.hpp"
class Bank
{
    private:
    std::vector<user> s;
    int bankmoney;
    std::vector<transaction> tr;
    public:
    std::vector<transaction>&gettransaction();
    void setTransaction(transaction);
    void setbankmoney(int);
    int getbankmoney();
    int getbankmoney(int);
    int getusernumber();
    void setuser(user);
    int getuserindex(std::string const &) const;
    int getipindex(std::string const & , int) const;
    std::vector<user> &getuser();
};
#endif // !BANK_HPP

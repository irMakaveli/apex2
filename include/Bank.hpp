#ifndef BANK_HPP
#define BANK_HPP
#include<vector>
#include "user.hpp"
class Bank
{
    private:
    std::vector<user> s;
    
    public:
    void setuser(std::string);
};
#endif // !BANK_HPP

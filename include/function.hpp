#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <string>
#include "Bank.hpp"
#include "user.hpp"

std::vector<std::string>  brain(std::string , std::vector<std::string> & , char);
bool renewal(Bank &, int);
void create(Bank & , std::string);
void creates(Bank &);
void addip(Bank &);
void renewal(Bank &);
void deposit(Bank &);
void withdraw(Bank &);
void transfer(Bank &);
void addprofits(Bank &);
void printuserinfo(Bank & , int);
void print(Bank & , std::string);
void getloan(Bank &);
void payloan(Bank &);
void help();
#endif // !
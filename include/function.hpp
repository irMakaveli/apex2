#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <string>
#include "Bank.hpp"
#include "user.hpp"

std::vector<std::string>  brain(std::string , std::vector<std::string> & , char);
bool renewal(Bank &, int);
void printuserinfo(Bank & , int);
void print(Bank & , std::string);
#endif // !
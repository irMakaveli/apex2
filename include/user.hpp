#ifndef USER_HPP
#define USER_HPP
#include <vector>
#include <string>
std::vector<std::string> getcomand();
class user
{
    private:
    std::string Username;
    std::vector<std::string> IP;
    int cardnumber=0;
    int startdate=0;
    int enddate=0;
    int money=0;
    public:
    void setusername(std::vector<user>& ,std::string);//
    std::string getusername();//
    void setip(std::vector<user> &,  std::vector<std::string> & );//
    std::vector<std::string> getip();//
    void setcardnumber(std::vector<user>&);//
    int getcardnumber();//
    void setstartdate();//
    int getstartdate();//
    void setenddate(int);//
    int getenddate()const;//
    int getmoney()const;//
    int getmoney(int);//
    void setmoney(int);//
    bool getstatus()const;
};
#endif // !USER_HPP

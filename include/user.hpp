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
    int loan=0;
    public:
    void setloan(int);
    int getloan();
    bool setusername(std::vector<user>const & ,std::string);//
    std::string getusername()const;//
    bool setip(std::vector<user> const &,  std::vector<std::string> & );//
    std::vector<std::string> getip() const;//
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

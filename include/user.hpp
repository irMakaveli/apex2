#ifndef USER_HPP
#define USER_HPP
#include <vector>
#include <string>
struct transaction
{
    int money;
    std::string type;
    int date;
};
class user
{
    private:
    std::vector<transaction *>t;
    std::string Username;
    std::vector<std::string> IP;
    int cardnumber;
    int startdate;
    int enddate;
    int money;
    int loan;
    public:
    user(int);
    bool setprofits();
    void Transaction(transaction *);
    std::vector<transaction *> GetTransaction();
    void setloan(int , bool);
    int getloan();
    bool setusername(std::vector<user>const & ,std::string);//
    std::string getusername()const;//
    bool setip(std::vector<user> const & ,std::vector<std::string>const & );//
    std::vector<std::string> getip() const;//
    void setcardnumber(std::vector<user>const &) ;//
    int getcardnumber() const;//
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

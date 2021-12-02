#ifndef USER_HPP
#define USER_HPP
#include <vector>
#include <string>
class transaction
{
    int money;
    std::string type;
    int date;
    public:
    void settransaction(int ,std::string);
    int transactionmoney();
    int transactiondate();
    std::string transactiontype();
};
class user
{
    private:
    std::vector<transaction>t;//taraconesh heye karbar
    std::string Username;
    std::vector<std::string> IP;
    int cardnumber;
    int startdate;
    int enddate;//tarikh engheza
    int money;
    int loan;
    public:
    user(int);
    bool setprofits();//pardakhte sood
    void Transaction(transaction );//set kardane tarakonesh
    std::vector<transaction>& GetTransaction();//return kardane tarakonesh ha
    bool setloan(int , bool);//vam gereftan
    int getloan();//return vam
    int getloan(int);//pardakhtane mablaghi az vam
    bool setusername(std::vector<user>const & ,std::string);//set kardane name karbar
    std::string getusername()const;//return kardane username
    bool setip(std::vector<user> const & ,std::vector<std::string>const & );//set kardane IP
    std::vector<std::string> getip() const;//return IP
    void setcardnumber(std::vector<user>const &) ;//tolide shomare kart
    int getcardnumber() const;//return kardane shomare kart
    void setstartdate();//set kardane tarikhe eftetahe hesab
    int getstartdate();//return kardane tarikhe eftetahe hesab
    void setenddate(int);//set kardane tarikh engheza
    int getenddate()const;//return kardane tarikh engheza
    int getmoney()const;//return kardane mojoodi
    int getmoney(int);//bardasht az hesab
    void setmoney(int);//variz be hasab
    bool getstatus()const;//check kardane tarikh engheza
};
#endif // !USER_HPP

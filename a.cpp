for(int i = 0  ;s[i]->date >= t-14 && s[i]->date < t; i++)
    {
        if(s[i]->type=="withdraw" || s[i]->type.find("transfer")==0)
        {
            mid -= s[i]->money;
            count++;
        }
        if(s[i]->type=="deposot" || s[i]->type=="profits")
        {
            mid += s[i]->money;
            count++;
        }
        int c;
        if(prfit && s[i]->type != "withdraw" && s[i]->type != "profits" && s[i]->type.find("transfer")!=0)
        {
            prfit =true;
        }
        else
        {
            prfit = false;
        }
    }
    profits = (prfit) ? 15 : 10;
    if(getmoney() >= 10000000)
    {
        profits+=5;
    }
    for(int  i = s.size() ; s[i]->date + 60 <= t ;i++ )
    { 
       
        if(s[i]->type == "profits")
        {
            cout<<"you get your profits recently"<<endl;
            return false; 
        }
        else if(s[i]->type == "loan")
        {
            cout<<"first pay your loan"<<endl;
            return false;
        }
    }
    mid = mid/count +getmoney();
    setmoney(profits*mid/100 + getmoney());
    
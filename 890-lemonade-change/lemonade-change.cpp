class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5)
        {
            return false;
        }
        int c5=0;
        int c10=0;
        int c20=0;
        int i=0;
        while(i<bills.size() && c5>=0 && c10>=0 && c20>=0)
        {
            if(bills[i]==5)
            {
                c5++;
            }
            else if(bills[i]==10)
            {
                c5--;
                c10++;
            }
            else{
                c20++;
                if(c10>0 && c5>0)
                {
                    c10--;
                    c5--;
                }
                else if(c5>=3)
                {
                    c5=c5-3;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        if(c5<0 || c10<0 || c20<0)return false;
        return true;
    }
};
class Solution {
public:
    string largestOddNumber(string num) {
        int e=num.length()-1;
        int si=0;
        int ei=-1;
        while(e>=0)
        {
            if((num[e]-'0')%2!=0)
            {
                ei=e;
                return num.substr(0,ei+1);
                break;
            }
            e--;
        }
        string ans="";
        return ans;
    }
};
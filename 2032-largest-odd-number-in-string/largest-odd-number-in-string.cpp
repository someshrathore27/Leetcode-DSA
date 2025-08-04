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
                break;
            }
            e--;
        }
        string ans="";
        for(int i=si;i<=ei;i++)
        {
            ans+=num[i];
        }
        return ans;
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        int oc=0;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                if(oc==0) oc++;
                else{
                    oc++;
                    ans=ans+s[i];
                }
            }
            else if(s[i]==')')
            {
                if(oc==1)
                {
                    oc=0;
                    continue;
                }
                else{
                    ans=ans+s[i];
                    oc--;
                }
            }
        }
        return ans;
    }
};
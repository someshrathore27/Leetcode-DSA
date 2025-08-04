class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string str="";
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ' || i==n-1)
            {
                if(i==n-1 && s[i]!=' ')
                {
                    str=str+s[i];
                }
                if(str.length()==0)
                {
                    continue;
                }
                str=str+" ";
                ans=str+ans;
                str="";
            }
            else{
                str=str+s[i];
            }
        }
        ans.pop_back();
        return ans;
    }
};
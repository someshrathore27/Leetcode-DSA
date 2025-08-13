class Solution {
public:
    bool ispalindrome(int s , int e ,string str)
    {
        while(s<e)
        {
            if(str[s]==str[e])
            {
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void solve(string s,vector<vector<string>>&ans,vector<string>output,int idx)
    {
        if(idx==s.size())
        {
            ans.push_back(output);
            return;
        }
        for(int i=idx;i<s.length();i++)
        {
            if(ispalindrome(idx,i,s))
            {
                output.push_back(s.substr(idx,i-idx+1));
                solve(s,ans,output,i+1);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        if(s.size()==0)
        {
            return ans;
        }
        vector<string>output;
        solve(s,ans,output,0);
        return ans;
    }
};
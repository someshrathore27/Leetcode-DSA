class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto i:mp)
                {
                    maxi=max(maxi,i.second);
                    mini=min(mini,i.second);
                }
                ans=ans+(maxi-mini);
            }
        }
        return ans;
    }
};
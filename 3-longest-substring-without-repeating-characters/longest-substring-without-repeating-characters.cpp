class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        unordered_map<int,int>mp;
        int st=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=i;
                ans=max(ans,i-st+1);
            }
            else{
                int start=st;
                int end=mp[s[i]];
                while(start<=end)
                {
                    mp.erase(s[start]);
                    start++;
                }
                st=start;
                mp[s[i]]=i;
            }
        }
        return ans;
    }
};
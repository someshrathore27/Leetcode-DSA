class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int res=0;

        int i=0;
        vector<int>mp(3,0);
        for(int j=0;j<n;j++)
        {
            char ch=s[j];
            mp[ch-'a']++;

            while(mp[0]>0 && mp[1]>0 && mp[2]>0)
            {
                res=res+(n-j);
                mp[s[i]-'a']--;
                i++;
            }
        }
        return res;
    }
};
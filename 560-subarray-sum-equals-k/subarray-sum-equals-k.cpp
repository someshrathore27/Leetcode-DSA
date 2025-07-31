class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) 
    {
       unordered_map<int,int>mp;
        int currsum=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            currsum=currsum+nums[i];
            if(mp.find(currsum-k)!=mp.end())
            {
                cnt=cnt+mp[currsum-k];
            }
            mp[currsum]++;
        }
        return cnt;
    }
};
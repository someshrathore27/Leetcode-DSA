class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        if(n==0)
        {
            return ans;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int lim=n/3;
        for(auto num:mp)
        {
            if(num.second>lim)
            {
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};
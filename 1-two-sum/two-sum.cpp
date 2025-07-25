class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            auto it=mp.find(nums[i]);
            if(it!=mp.end())
            {
                ans.push_back(mp.at(nums[i]));
                ans.push_back(i);
                return ans;
            }
            mp.insert({target-nums[i],i});
        }
        return ans;
    }
};
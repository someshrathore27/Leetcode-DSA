class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int maxi=0;
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);
        }
        for(auto it:mp)
        {
            if(it.second==maxi)
            {
                return it.first;
            }
        }
        return -1;

    }
};
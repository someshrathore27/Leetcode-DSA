class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        vector<int>ans(temp.size());
        stack<int>st;
        
        for(int i=temp.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=temp[i])
            {
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(temp[i]);
        }
        vector<int>fans;
        for(int i=0;i<nums.size();i++)
        {
            fans.push_back(ans[i]);
        }
        return fans;
    }
};
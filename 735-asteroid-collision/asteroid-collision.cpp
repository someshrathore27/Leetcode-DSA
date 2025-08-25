class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            if(st.empty())
            {
                st.push(arr[i]);
                continue;
            }
            int top=st.top();
            if(top>0 && arr[i]<0)
            {
                if(abs(top)<abs(arr[i]))
                {
                    st.pop();
                    i--;
                }
                else if(abs(top)==abs(arr[i]))
                {
                    st.pop();
                }
                else{
                    continue;
                }
            }
            else{
                st.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
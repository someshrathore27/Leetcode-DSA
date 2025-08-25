class Solution {
public:
    vector<int> getnsl(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getnsr(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) { 
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnsl(arr, n);
        vector<int> nsr = getnsr(arr, n);

        long long sum = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            long long totalways = ls * rs;
            long long totalsum = (long long)arr[i] * totalways;
            
            sum = (sum + totalsum) % mod;
        }
        return sum;
    }
};
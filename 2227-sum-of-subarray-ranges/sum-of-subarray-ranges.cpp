class Solution {
public:
    // Next Smaller to Left (NSL)
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

    // Next Smaller to Right (NSR)
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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnsl(arr, n);
        vector<int> nsr = getnsr(arr, n);

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            long long totalways = ls * rs;
            long long totalsum = (long long)arr[i] * totalways;
            
            sum += totalsum;
        }
        return sum;
    }

    // Next Larger to Left (NLL)
    vector<int> getnll(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Next Larger to Right (NLR)
    vector<int> getnlr(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) { 
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nll = getnll(arr, n);
        vector<int> nlr = getnlr(arr, n);

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long ls = i - nll[i];
            long long rs = nlr[i] - i;
            long long totalways = ls * rs;
            long long totalsum = (long long)arr[i] * totalways;
            
            sum += totalsum;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& arr) {
        long long maxSum = sumSubarrayMaxs(arr);
        long long minSum = sumSubarrayMins(arr);
        return maxSum - minSum; // No modulo here
    }
};

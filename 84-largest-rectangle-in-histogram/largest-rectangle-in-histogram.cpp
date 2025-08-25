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
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnsl(arr, n);
        vector<int> nsr = getnsr(arr, n);

        int area = 0;
        for(int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int currArea = arr[i] * width;
            area = max(area, currArea);
        }
        return area;
    }
};

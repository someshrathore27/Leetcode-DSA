class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (char c : num) 
        {
            while (!st.empty() && k > 0 && st.top() > c) 
            {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // If k still > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // build result
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        // remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};

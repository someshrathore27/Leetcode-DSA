class Solution {
public:
    int myAtoi(string s) {
        int num;
        stringstream ss(s);
        ss >> num;
        return num;
    }
};
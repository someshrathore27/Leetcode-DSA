class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                idx = i + 1;
                break;
            }
        }

        if (idx == 0) {
            return true;
        }

        bool isSorted = true;
        for (int i = 0; i < n - 1; i++) {
            int curr = (idx + i) % n;
            int next = (idx + i + 1) % n;
            if (nums[curr] > nums[next]) {
                isSorted = false;
                break;
            }
        }

        return isSorted;
    }
};
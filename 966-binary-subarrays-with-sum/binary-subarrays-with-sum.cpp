class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int sum = 0, cnt = 0;
        
        for (int num : arr) 
        {
            sum += num;
            if (freq.find(sum - goal) != freq.end()) 
            {
                cnt += freq[sum - goal];
            }
            freq[sum]++;
        }
        
        return cnt;
    }
};

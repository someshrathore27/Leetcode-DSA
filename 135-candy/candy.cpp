class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> minchoco(n, 1);
        for (int i = 1; i < n; i++) 
        {
            if (ratings[i] > ratings[i - 1]) 
            {
                minchoco[i] = minchoco[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) 
        {
            if (ratings[i] > ratings[i + 1] && minchoco[i] <= minchoco[i + 1])
            {
                minchoco[i] = minchoco[i + 1] + 1;
            }
        }
        int sum = 0;
        for (int candy : minchoco) {
            sum += candy;
        }
        return sum;
    }
};
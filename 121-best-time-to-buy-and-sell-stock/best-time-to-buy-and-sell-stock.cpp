class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if(arr.size()==0)
        {
            return 0;
        }
        int buy=arr[0];
        int sell=arr[0];
        int profit=0;
        for(int i=1;i<arr.size();i++)
        {
            buy=min(buy,arr[i]);
            sell=arr[i];
            profit=max(profit,sell-buy);
        }
        return profit;
    }
};
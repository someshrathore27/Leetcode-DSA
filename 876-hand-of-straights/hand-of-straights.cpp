class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if (hand.size() % groupSize != 0) return false;
        
        map<int, int> count;
        for (int card : hand) 
        {
            count[card]++;
        }
        
        // Create min-heap of all unique cards
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [card, freq] : count) 
        {
            pq.push(card);
        }
        
        while (!pq.empty()) {
            int start = pq.top();
            
            // Check if we can form a group starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int current = start + i;
                if (count[current] == 0) return false;
                
                count[current]--;
                if (count[current] == 0) 
                {
                    // Remove from pq only if it's the smallest remaining
                    if (current != pq.top()) return false;
                    pq.pop();
                }
            }
        }
        
        return true;
    }
};
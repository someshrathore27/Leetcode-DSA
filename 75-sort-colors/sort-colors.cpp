class Solution {
public:
    void sortColors(vector<int>& arr) {
        int mid=0;
        int s=0;
        int e=arr.size()-1;
        while(mid<=e)
        {
            if(arr[mid]==0)
            {
                swap(arr[mid++],arr[s++]);
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
            else if(arr[mid]==2)
            {
                swap(arr[mid],arr[e--]);
            }
        }
    }
};
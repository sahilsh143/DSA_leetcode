class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int sum = 0;
        int count = 0;

        // First window
        for(int i = 0; i < k; i++)
            sum += arr[i];

        if(sum >= k * threshold)
            count++;

        // Slide the window
        for(int i = k; i < arr.size(); i++)
        {
            sum = sum - arr[i-k] + arr[i];

            if(sum >= k * threshold)
                count++;
        }

        return count;
    }
};
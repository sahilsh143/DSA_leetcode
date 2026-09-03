class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int res = 0;
        long long product = 1;

        if(k <= 1)
            return 0;

        for(int high = 0; high < n; high++) {

            product = product * nums[high];

            while(product >= k) {
                product = product / nums[low];//removing low shirink window
                low++;
            }

            int len = high - low + 1;
            res = res + len;
        }

        return res;
    }
};
class Solution {
public:
    int findGCD(vector<int>& nums) {

        int small = INT_MAX;
        int large = INT_MIN;

        // Find smallest and largest element
      for (int i = 0; i < nums.size(); i++) {
    small = min(small, nums[i]);
    large = max(large, nums[i]);
}

        // Euclid's Algorithm
        while (large != 0) {
            int rem = small % large;
            small = large;
            large = rem;
        }

        return small;
    }
};
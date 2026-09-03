class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        int mn = *min_element(nums1.begin(), nums1.end());

        if(mn % 2 == 1) {
            return true;
        }
        else {

            for(int i = 0; i < n; i++) {

                if(nums1[i] % 2 != 0) {
                    return false;
                }

            }
        }

        return true;
    }
};
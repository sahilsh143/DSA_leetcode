class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int, int>> arr;
        int n=nums.size();
        int i=0,j=n-1;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(),arr.end());
        while(i<j){
            int sum=arr[i].first +arr[j].first;
            if(sum==target){
                return {arr[i].second,arr[j].second};
            }
            if(sum<target){
                i++;
            }
            if(sum>target){
                j--;
            }
        }
        return {};
    }
};
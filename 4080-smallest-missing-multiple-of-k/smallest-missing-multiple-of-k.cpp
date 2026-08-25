class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        for(int x=1; ;x++){
            int product=k*x;
            bool found=false;
            for(int i=0;i<n;i++){
                if(nums[i]==product){
                    found=true;
                    break;
                }
            }
             if(found == false) {
                return product;
        }
        
    }
    }
};
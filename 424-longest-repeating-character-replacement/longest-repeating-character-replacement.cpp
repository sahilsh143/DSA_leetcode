class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0,high=0;
         int res=0;
        int n=s.size();
        int max_freq=0;
        unordered_map<char,int>f;
        for(high=0;high<n;high++){
            f[s[high]]++;
            max_freq=max(max_freq,f[s[high]]);
            while((high-low+1)-max_freq>k){
                f[s[low]]--;
                low++;
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};
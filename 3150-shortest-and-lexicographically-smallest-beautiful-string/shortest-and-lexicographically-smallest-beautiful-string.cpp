class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int low=0;
        int high=0;
        int ones=0;
       int  bestLen=INT_MAX;
       string ans="";
        for(int high=0;high<s.size();high++){
            if(s[high]=='1'){
                ones++;
            }
            while(ones>k){
                if(s[low]=='1'){
                    ones--;
                }
                low++;
            }
            if (ones == k) {

                // Remove unnecessary zeros from left
                while (s[low] == '0') {
                    low++;
                }
        
            int len=high-low+1;
            string current = s.substr(low, len);
             if (len < bestLen) {
                    bestLen = len;
                    ans = current;
                }

                // Same length -> lexicographically smaller
                else if (len == bestLen && current < ans) {
                    ans = current;
                }
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    long long countCommas(int n) {
        long long res = 0;

        if(n < 1000)
            return 0;

        res = res + (n - 999);

        
           

        return res;
    }
};
class Solution {
public:

    // Checks whether current window contains all required characters
    bool fun(vector<int> &have, vector<int> &need)
    {
        for(int i=0;i<256;i++)
        {
            if(have[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        if(n < m)
            return "";

        vector<int> have(256,0);
        vector<int> need(256,0);

        // Store frequency of characters of t
        for(int i=0;i<m;i++)
            need[t[i]]++;

        int low = 0;
        int high = 0;

        int start = -1;
        int res = INT_MAX;

        for(high=0; high<n; high++)
        {
            // Include current character
            have[s[high]]++;

            // Window contains all characters
            while(fun(have,need))
            {
                int len = high-low+1;

                if(len < res)
                {
                    res = len;
                    start = low;
                }

                // Remove left character
                have[s[low]]--;

                low++;
            }
        }

        if(start==-1)
            return "";

        return s.substr(start,res);
    }
};
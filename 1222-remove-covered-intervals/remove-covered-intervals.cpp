class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if(a[0] == b[0])
                     return a[1] > b[1];

                 return a[0] < b[0];
             });

        int maxEnd = 0;
        int remove = 0;

        for(int i = 0; i < intervals.size(); i++) {

            int s = intervals[i][0];
            int e = intervals[i][1];

            if(e <= maxEnd) {
                remove++;
            }
            else {
                maxEnd = e;
            }
        }

        return intervals.size() - remove;
    }
};
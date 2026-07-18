class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int remove = 0;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            int s = intervals[i][0];
            int e = intervals[i][1];

            if (end <= s) {      // No overlap
                start = s;
                end = e;
            }
            else {               // Overlap
                remove++;

                // Keep the interval that ends earlier
                end = min(end, e);
            }
        }

        return remove;
    }
};
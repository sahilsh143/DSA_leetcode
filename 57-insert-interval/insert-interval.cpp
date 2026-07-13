class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(end >= s) // overlap
            {
                end = max(end, e);
            }
            else
            {
                res.push_back({start, end});
                start = s;
                end = e;
            }
        }

        res.push_back({start, end});
        return res;
    }
};
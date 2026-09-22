class Solution {
public:

    // Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int area = heights[element] * (nse - pse - 1);

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        // Process remaining elements
        while(!st.empty()) {

            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int area = heights[element] * (nse - pse - 1);

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> psum(n, vector<int>(m, 0));

        int maxArea = 0;

        // Build vertical prefix-sum / height matrix
        for(int j = 0; j < m; j++) {

            int sum = 0;

            for(int i = 0; i < n; i++) {

                if(matrix[i][j] == '1') {
                    sum = sum + 1;
                }
                else {
                    sum = 0;
                }

                psum[i][j] = sum;
            }
        }

        // Treat every row as a histogram
        for(int i = 0; i < n; i++) {

            maxArea = max(maxArea, largestRectangleArea(psum[i]));
        }

        return maxArea;
    }
};
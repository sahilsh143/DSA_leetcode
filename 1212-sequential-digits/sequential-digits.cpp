class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        string digits = "123456789";

        for(int len = 2; len <= 9; len++)
        {
            for(int start = 0; start + len <= 9; start++)
            {
                string num = digits.substr(start, len);

                int value = stoi(num);

                if(value >= low && value <= high)
                {
                    ans.push_back(value);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
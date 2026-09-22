class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;
        int n = num.length();

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  k > 0 &&
                  st.top() > num[i]) {

                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // If k is still left, remove from the end
        while(k > 0) {
            st.pop();
            k--;
        }

        if(st.empty()) {
            return "0";
        }

        // Build result
        string res = "";

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Stack gives reverse order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;

        while(i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        if(res.empty()) {
            return "0";
        }

        return res;
    }
};
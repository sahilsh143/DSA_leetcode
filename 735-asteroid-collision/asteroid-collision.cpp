class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {

            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {

                while(!st.empty() &&
                      st.top() > 0 &&
                      st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if(!st.empty() &&
                   st.top() == abs(asteroids[i])) {
                    st.pop();
                }
                else if(st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> answer;

        // Take elements from stack
        while(!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        // Reverse because stack gives elements from top to bottom
        reverse(answer.begin(), answer.end());

        return answer;
    }
};
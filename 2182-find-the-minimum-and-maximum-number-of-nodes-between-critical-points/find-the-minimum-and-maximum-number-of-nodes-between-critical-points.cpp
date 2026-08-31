class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int pos = 1;

        int first = -1;
        int prev = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {

            ListNode* nextNode = curr->next;

            // Check whether current node is a critical point
            bool isCritical = false;

            // Local maximum
            if (curr->val > prevNode->val &&
                curr->val > nextNode->val) {
                isCritical = true;
            }

            // Local minimum
            if (curr->val < prevNode->val &&
                curr->val < nextNode->val) {
                isCritical = true;
            }

            if (isCritical) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                } 
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);

                    // Distance from first critical point
                    maxDist = max(maxDist, pos - first);
                }

                prev = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        // Fewer than two critical points
        if (first == -1 || prev == first) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};
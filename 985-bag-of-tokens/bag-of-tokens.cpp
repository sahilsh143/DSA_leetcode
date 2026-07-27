class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int left=0;
        int right=n-1;
        int score=0;
        int maxscore=0;
        while(left<=right){
            if(tokens[left]<=power){
                power-=tokens[left];
                score++;
                maxscore=max(maxscore,score);
                left++;
            }
            else if(score>0){
                power+=tokens[right];
                 score--;
                 right--;

            }
            else{
                break;
            }
        }
        return maxscore;
        
    }
};
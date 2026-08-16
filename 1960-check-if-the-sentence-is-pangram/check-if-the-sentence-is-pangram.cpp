class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>aplha(26,0);
        for(int i=0;i<sentence.size();i++){
            aplha[sentence[i]-'a']=1;
        }
        for(int i=0;i<26;i++){
            if(aplha[i]==0){
                return false;
            }
        }
        return true;
    }
};
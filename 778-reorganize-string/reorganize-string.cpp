class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        
        // max heap {freq, char}
        priority_queue<pair<int,char>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        
        string res = "";
        int seat = 0;
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();   // ❗ pop first
            
            // if first position OR not same as previous
            if(seat == 0 || res[seat-1] != p.second){
                
                res.push_back(p.second);
                seat++;
                
                p.first--;
                if(p.first > 0){
                    pq.push(p);
                }
            }
            else{
                // need second best option
                if(pq.empty()){
                    return "";   // ❗ not possible
                }
                
                auto p2 = pq.top();
                pq.pop();
                
                res.push_back(p2.second);
                seat++;
                
                p2.first--;
                if(p2.first > 0){
                    pq.push(p2);
                }
                
                // push back original element
                pq.push(p);
            }
        }
        
        return res;
    }
};
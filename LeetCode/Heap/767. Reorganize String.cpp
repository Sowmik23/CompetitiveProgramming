// 767. Reorganize String
class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> mp;
        for(auto& ch: s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto& m: mp){
            pq.push({m.second, m.first});
        }

        string str = "";

        while(pq.size()>1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            str+=top1.second;
            top1.first--;
            str+=top2.second;
            top2.first--;

            if(top1.first>0) pq.push(top1);
            if(top2.first>0) pq.push(top2);
        }
        if(pq.size()>0){
            auto top = pq.top();
            if(top.first>1) return "";
            str+=top.second;
        }
       
        return str;    
    }
};

//"abbabbaaab"
// aaaaa bbbbb

//"ogccckcwmbmxtsbmozli"
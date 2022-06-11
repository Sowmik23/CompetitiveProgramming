class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        
        unordered_map<string, int> mp;
        
        for(int i=0;i<messages.size();i++){
            
            stringstream ss(messages[i]);
            string word;
            int cnt = 0;
            while(ss>>word){
                cnt++;
            }
//             if(cnt>mx){
//                 mx = cnt;
//                 sender = senders[i];
//             }
//             else if(cnt==mx){
//                 sender = sender>senders[i] ? sender : senders[i];
//             }
            
            mp[senders[i]]+=cnt;   
        }
        
        string sender = "";
        int mx = 0;
       
        for(auto& i: mp){
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second>mx){
                mx = i.second;
                sender = i.first;
            } 
            else if(i.second ==mx){
                if(i.first>sender){
                    sender = i.first;
                }
            }
        }
        
        
        
        return sender;
    }
};

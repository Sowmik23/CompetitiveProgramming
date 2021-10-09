class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        // unordered_map<string, int> sameEmails;
        unordered_set<string> uniqueEmails;
        
        for(int i=0;i<emails.size();i++){
            
            string mail = emails[i];
            
            string m = "";
            bool flag = false;
            int j = 0;
            for(j = 0; ;j++){
                if(mail[j]=='+'){
                    flag = true;
                    continue;
                } 
                if(mail[j]=='@') break;
                if(mail[j]!='.' and flag==false) m+=mail[j];
            }
            
            string domain = mail.substr(j+1, mail.size()-j-1);
            cout<<m<<" "<<domain<<endl;
            uniqueEmails.insert(m+"@"+domain);
            
            // sameEmails[m+"@"+domain]++;
        }
        
        return uniqueEmails.size();
    }
};

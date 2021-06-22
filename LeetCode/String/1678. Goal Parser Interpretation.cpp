class Solution {
public:
    string interpret(string command) {
        
        string res = "";
        for(int i=0;i<command.size();i++){
            
            if(command[i]=='G') res+='G';
            else if(command[i]=='(' ){
                if(command[i+1]==')') {
                    res+='o';
                    i++;
                }
                else if(command[i+1]=='a' and command[i+2]=='l' and command[i+3]==')') {
                    res+='a';
                    res+='l';
                    i+=3;
                }
            }
            else res+=command[i];
        }
        
        return res;
    }
};

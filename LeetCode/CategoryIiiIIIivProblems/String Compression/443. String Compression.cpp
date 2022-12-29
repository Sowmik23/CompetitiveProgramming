class Solution {
public:
    int compress(vector<char>& chars) {

        string str = "";
        int i = 1, j = 1;
        int cnt = 1;
        str+=chars[0];

        while(i<chars.size()){
            if(chars[i]==chars[i-1]){
                while(i<chars.size() and chars[i]==chars[i-1]){
                    cnt++;
                    i++;
                }
            }
            else {
                if(cnt>1){
                    str+=to_string(cnt);
                    cnt = 1;
                }
                str+=chars[i];
                i++;
            }
        }
        if(cnt>1) {
            str+=to_string(cnt);
        }

        //cout<<str<<endl;
        for(int i=0;i<str.size();i++){
            chars[i] = str[i];
        }

        return str.size();
    }
};

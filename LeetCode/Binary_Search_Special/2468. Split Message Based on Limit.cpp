class Solution {
public:
    vector<string> splitMessage(string message, int limit) {

        int total = 0;
        int len =0;

        //binary search
        for(int i=1;i<=10009;i++){
            len += to_string(i).size();
            int totalStrlen = (3+to_string(i).size())*i + len + message.size();  // <len/to_string(i)>message
            int tillSecondLastLen = (i-1)*limit;

            if(totalStrlen - tillSecondLastLen<=limit){
                total = i;
                break;
            }
        }

        if(total==0)  return {};
        return resString(message, total, limit);
    }
private:
    vector<string> resString(string message, int total, int limit){
        vector<string> res;
        int cnt = 1;
        int i = 0;
        string suffix = "<"+to_string(cnt)+"/"+to_string(total)+">";
        string str = "";

        while(i<message.size()){
            str+=message[i];
            if(str.size()+suffix.size()==limit){
                str+=suffix;
                res.push_back(str);
                str = "";
                cnt++;
                suffix = "<"+to_string(cnt)+"/"+to_string(total)+">";
            }
            i++;
        }
        if(cnt==total and str.size()+suffix.size()<=limit){
            str+=suffix;
            res.push_back(str);
        }

        return res;
    }
};

/* Input:
"this is really a very awesome message"
9
"short message"
15
"sree sowmik kumar sarker and some else"
8
"sree sowmik kumar sarker and some else"
5
"test ca"
10
"test ca"
1
"hello world"
10
"abbababbbaaa aabaa a"
8

Output:
["thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]
["short mess<1/2>","age<2/2>"]
["sr<1/29>","ee<2/29>"," s<3/29>","ow<4/29>","mi<5/29>","k <6/29>","ku<7/29>","ma<8/29>","r <9/29>","s<10/29>","a<11/29>","r<12/29>","k<13/29>","e<14/29>","r<15/29>"," <16/29>","a<17/29>","n<18/29>","d<19/29>"," <20/29>","s<21/29>","o<22/29>","m<23/29>","e<24/29>"," <25/29>","e<26/29>","l<27/29>","s<28/29>","e<29/29>"]
[]
["test <1/2>","ca<2/2>"]
[]
["hello<1/3>"," worl<2/3>","d<3/3>"]
["abb<1/7>","aba<2/7>","bbb<3/7>","aaa<4/7>"," aa<5/7>","baa<6/7>"," a<7/7>"]
*/

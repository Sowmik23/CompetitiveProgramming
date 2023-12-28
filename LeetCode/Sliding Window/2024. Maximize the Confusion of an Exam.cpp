// 2024. Maximize the Confusion of an Exam
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        //sliding window
        int res = 0;
        int cnt = 0;
        int left = 0, right = 0;
        while(right<answerKey.size()){
            if(answerKey[right]=='F') cnt++;
            while(cnt>k){
                if(answerKey[left]=='F') cnt--;
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }

        cnt = 0;
        left = 0, right = 0;
        while(right<answerKey.size()){
            if(answerKey[right]=='T') cnt++;
            while(cnt>k){
                if(answerKey[left]=='T') cnt--;
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};
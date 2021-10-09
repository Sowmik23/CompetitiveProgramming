class Solution {
public:
    string numberToWords(int num) {
        
        
        if(num==0) return "Zero";
        
        string res = "";
        
        vector<string> bigTens = {"Billion", "Million", "Thousand", "Hundred"};
        vector<int> bigTensValues = {1000*1000*1000, 1000*1000, 1000, 100};
        
        for(int i=0;i<bigTensValues.size();i++){
            int div = num/bigTensValues[i];
            
            if(div!=0){
                if(res.size()>0){
                    res+=" ";
                }
                res+= numberToWords(div)+ " "+bigTens[i];
            }
            num%=bigTensValues[i];
        }
        
        if(num>0){
            if(res.size()>0){
                res+=" ";
            }
            res+=convertNumberLessThanHundred(num);
        }
        
        return res;
    }
    
private:
    string convertNumberLessThanHundred(int num){
        
        vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
        vector<string> elevenToNineteen = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if(num<10) return digits[num];
        if(num%10==0){
            return tens[num/10-1];
        }
        if(num<20){
            return elevenToNineteen[num-11];
        }
        
        return tens[num/10-1]+" "+digits[num%10];
    }
};

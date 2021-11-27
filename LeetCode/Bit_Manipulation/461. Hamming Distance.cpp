class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int val = x^y;
        
        return convertToBinary(val);
    }
private:
    int convertToBinary(int x){
//         string str = bitset<8>(x).to_string();
//         int cnt = 0;
        
//         for(int i=0;i<str.size();i++)
//         {
//             if(str[i]=='1') cnt++;
//         }
//         return cnt;
        
        int cnt = 0;
        while(x!=0){
            if(x%2==1) cnt++;
            x = x/2;
        }
        
        return cnt;
    }
};

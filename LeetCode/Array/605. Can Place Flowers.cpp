class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n>flowerbed.size()/2 + 1) return false;
        if(flowerbed.size()==1 and n==1){
            if(flowerbed[0]==0) return true;
            else return false;
        }
        
        int i = 0;
        while(i<flowerbed.size() and flowerbed[i]==0) i++;
        
        int cnt;
        if(i==flowerbed.size()){
            if(i>2) cnt = (i+1)/2;
            else cnt = 1;
        }
        else cnt = i/2;
    
        
        while(i<flowerbed.size()){
            while(i<flowerbed.size() and flowerbed[i]==1) i++;
            
            int c = 0;
            while(i<flowerbed.size() and flowerbed[i]==0){
                c++;
                i++;
                if(i==flowerbed.size()){
                    cnt+=c/2;
                    c = 0;
                }
            }
            cnt+=(c-1)/2;
        }
        
        if(cnt>=n) return true;
        return false;
    }
};

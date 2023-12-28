// 2591. Distribute Money to Maximum Children
class Solution {
public:
    int distMoney(int money, int children) {
        
        if(children>money) return -1;
        int res = 0;
        
        int x = children*8;
        while(x<=money){
            money-=x;
            res+=children;
            break;
        }
        // cout<<res<<endl;
        if(res==0){
            money = money - children;
            res = money/7;
            int k = money%7;
            if(res+1==children and k+1==4) return res-1<0 ? 0: res-1;
            return res;
        }
        
        if(money==0) return res;
        int a = money%8;
        if(a==0 and money/8>=1) return res-1<0 ? 0 : res-1;
        if(a>0) return res-1<0 ? 0 : res-1;
        
        return res;
    }
};
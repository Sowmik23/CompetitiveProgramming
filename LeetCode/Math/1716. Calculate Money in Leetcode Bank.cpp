// 1716. Calculate Money in Leetcode Bank

class Solution {
public:
    int totalMoney(int n) {
        
        int total = 0;
        int totalWeek = n/7;
        int tw = totalWeek;
        int extraDay = n%7;

        int x = 0;
        int y = 7;
        while(totalWeek>0){
            total +=((y*(y+1)/2)-(x*(x+1)/2));
            totalWeek--;
            x++;
            y++;
        }
        // cout<<x<<" "<<y<<" "<<total<<" "<<extraDay<<" "<<(((x+extraDay)*(x+extraDay+1)/2)-(x*(x+1)/2))<<endl;

        total+=(((x+extraDay)*(x+extraDay+1)/2)-(x*(x+1)/2));

        return total;
    }
};

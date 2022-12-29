class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {

        int x, y;
        vector<int> nums1, nums2;
        unordered_map<int, int> blocked;

        int n = 1;
        while(true){
            if(n&divisor1){
                uniqueCnt1--;
                blocked[n] = 1;
                x = n;
            }
            if(uniqueCnt1==0) break;
            n++;
        }


        n = 1;
        while(true){
            if(n&divisor2 and blocked[n]!=1){
                uniqueCnt2--;
                y = n;
            }
            if(uniqueCnt2==0) break;
            n++;
        }
        cout<<x<<" "<<y<<endl;
        return max(x, y);




        //actual solution(don't read it! read the problem first as it is leetcode premium problem)
        long long lcm=divisor1;
        lcm*=divisor2;
        lcm/=__gcd(divisor1,divisor2);
        long long Max=2e9+100000000,Min=0;
        while(Max>Min+1){
            long long mid=(Max+Min)/2;
            long long sum=mid-mid/lcm;
            long long aa=mid-mid/divisor1,bb=mid-mid/divisor2;
            if(sum>=a+b&&aa>=a&&bb>=b)Max=mid;
            else Min=mid;
        }
        return Max;

    }
};

// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        int cnt = 0;
        int x = 0;
        for(int i=0;i<n;i++){
            x^=arr[i];
            for(int j=i+1;j<n;j++){
                x^=arr[j];
                if(x==0) cnt+=j-i;
            }
            x = 0;
        }
        return cnt;
    }
};
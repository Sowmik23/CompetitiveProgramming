// 888. Fair Candy Swap
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
     
        //TotalA - x + y == TotalB-y+x;
        // y = (TotalB-TotalA)/2 + x;

        //x == Alice
        //y == Bob

        int sumA = 0, sumB = 0;
        for(auto& alice: aliceSizes) sumA+=alice;
        for(auto& bob: bobSizes) sumB+=bob;

        int alpha = (sumB-sumA)/2;
        set<int> st;
        for(auto& bob: bobSizes) st.insert(bob);
        for(auto& alice: aliceSizes){
            if(st.count(alice+alpha)>0) return {alice, alice+alpha};
        }
        return {};
    }
};
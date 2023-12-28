// 1187. Make Array Strictly Increasing
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        sort(arr2.begin(), arr2.end()) ;
        
        int res = dfs(0, -1, arr1, arr2);
        if(res<2001) return res;
        return -1;
    }
private:
    map<pair<int, int>, int> mp;
    int dfs(int index, int prev, vector<int> &arr1, vector<int> &arr2){
        if(index==arr1.size()) return 0;
        if(mp.find({index, prev})!=mp.end()) return mp[{index, prev}];

        int cost = 2001;
        if(arr1[index]>prev) cost = dfs(index+1, arr1[index], arr1, arr2);

        int idx = bisetArr2(arr2, prev);
        if(idx<arr2.size()){
            cost = min(cost, 1+dfs(index+1, arr2[idx], arr1, arr2));
        }
        mp[{index, prev}] = cost;
        return cost;
    }
    int bisetArr2(vector<int> &arr2, int value){
        int left = 0, right = arr2.size();
        while(left<right){
            int mid = left+(right-left)/2;
            if(arr2[mid]<=value) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
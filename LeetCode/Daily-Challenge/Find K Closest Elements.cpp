class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     
        vector<int> res;
        sort(arr.begin(), arr.end());
        
        int pos = binarySearch(arr, x);
        int a = INT_MAX, b = INT_MAX;
        int l=pos-1;
        // cout<<"Something "<<pos<<endl;
        
        while(k--){
            if(pos<arr.size()){
                a = abs(arr[pos] - x);
            }
            else if(pos>=arr.size()) a = INT_MAX;
            
            if(l>=0){
                b = abs(arr[l] - x);
            }
            else if(l<0) b  =INT_MAX;
            
            
            if(a<b){
                res.push_back(arr[pos]);
                pos++;
                // k--;
            }
            else {
                res.push_back(arr[l]);
                l--;
                // k--;
            }
        }
        
        // for(auto i: res) cout<<i<<" ";
        // cout<<endl;
        sort(res.begin(), res.end());
        
        return res;
    }
private:
    int binarySearch(vector<int> arr, int x){
        int left = 0, right = arr.size()-1, mid;
        
        while(left<right){
            mid = (left+right)/2;
            
            if(arr[mid]>=x){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        
        if(left<x and arr[left]<x) left++;
        
        return left;
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    
        for(auto i: arr){
            pq.push({abs(i-x), i});
        }
        
        while(!pq.empty()){
            k--;
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            res.push_back(pq.top().second);
            if(k==0) break;
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        // for(auto i: res) cout<<i<<" ";
        
        return res;
    }
};


auto speedup = []() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
    
private:
    map<int, int> mp;
    vector<int> vec;
    
public:
    //compare function to sort the mp according to greater frequency
     struct comp {
         bool operator() (pair<int, int> a, pair<int, int> b){
             return a.second>b.second;
         }
     };
    
    
    
    int partition(int left, int right, int pivotIndex){
        int pivot_frequency = mp[vec[pivotIndex]];
        
        //move pivot to the end
        swap(vec[pivotIndex], vec[right]);
        
        //move all less frequent elements to the left
        int store_index = left;
        for(int i=left;i<=right;i++){
            if(mp[vec[i]] < pivot_frequency) {
                swap(vec[store_index], vec[i]);
                store_index++;
            }
        }
        
        //move pivot to it's final place
        swap(vec[right], vec[store_index]);
        
        return store_index;
        
    }
    
    void quickSelect(int left, int right, int k_smallest){
        
        //base case: list has only one elements
        if(left==right) return;
        
        int pivot = left + rand()%(right-left+1);
        
        //find pivot position in a sorted list
        pivot = partition(left, right, pivot);
        
        //if pivot is in its final sorted position
        if(k_smallest==pivot) return ;
        
        else if(k_smallest < pivot) { //go left
            quickSelect(left, pivot-1, k_smallest);
        }
        else { //go right
            quickSelect(pivot+1, right, k_smallest);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //approach-01: map + heap: O(nlogk)
        
      /*  map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        //compare function to sort the mp according to greater frequency
        auto comp = [&mp](int num1, int num2){
            return mp[num1]>mp[num2];
        };
        
        //initialize pq with most frequent element at the top
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        
        
        for(auto i: mp){
            pq.push(i.first);
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i] = pq.top();
            pq.pop();
        }
        
        return res;
        
        */
        
        //same thing but another way to write compare function
       /* map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        
        
        //declare a heap/priority_queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        
        for(auto i: mp){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i] = pq.top().first;
            pq.pop();
        }
        
        return res;
        */
        
        //approach:02 :Quick Select algorithm
        
        for(int i: nums){
            mp[i]++;
        }
        
        for(auto i:mp){
            
            vec.push_back(i.first);
        }
        
        size_t n = mp.size();
        
        quickSelect(0, n-1, n-k);
        
        
        //return top k frequent elements
        
        vector<int> top_k_frequent(k);
        
        copy(this->vec.begin()+n-k, this->vec.end(), top_k_frequent.begin());
        
        return top_k_frequent;
        
        
    }
    
};

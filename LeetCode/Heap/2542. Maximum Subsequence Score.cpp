// 2542. Maximum Subsequence Score
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        //Priority Queue
        int n = nums1.size();
        vector<pair<int, int>> tmp;
        priority_queue<int, vector<int>, greater<int>> pq; //min pq

        for(int i=0;i<n;i++){
            tmp.push_back({nums1[i], nums2[i]});
        }

        sort(tmp.begin(), tmp.end(), [](auto& a, auto& b){
            return a.second>b.second;
        });

        long sum = 0;
        for(int i=0;i<k;i++){
            sum+=tmp[i].first;
            pq.push(tmp[i].first);
        }
        long mx = sum*tmp[k-1].second;

        for(int i=k;i<n;i++){
            sum-=pq.top();
            pq.pop();
            sum+=tmp[i].first;
            pq.push(tmp[i].first);
            mx = max(mx, sum*tmp[i].second);
        }   
        return mx;
    }
};
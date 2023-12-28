// Binary Search-Line Sweep-Prefix Sum 2251. Number of Flowers in Full Bloom



// You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom 
// from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith 
// person will arrive to see the flowers.

// Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.



class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        //Blooming flowers = started flowers - ended flowers

        //Approach: 01 Binary Search
        //Time: O(nlogn)
            // Collect start bloom time point array, then sort it.
            // Collect end bloom time point array, then sort it.

            // For each time point t in persons:

            // Binary search the upper bound of t in start, then we find the started flowers.
            // Binary search the lower bound of t in end, then we find the started flowers.
            // Blooming flowers = started flowers - ended flowers

/*
        vector<int> start, end;
        for(auto &flower: flowers){
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> res;
        for(int pos: people){
            int started = upper_bound(start.begin(), start.end(), pos) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), pos) - end.begin();
            res.push_back(started - ended);
        }
        return res;
*/

/*
        //Approach-02: Compressed Line Sweep
        map<int, int> mp{{0, 0}};
        for(const auto f : flowers){
            mp[f[0]]++;
            mp[f[1]+1]--;
        }
        for(auto it = next(mp.begin()); it!=mp.end();it++){
            it->second += prev(it)->second;
        }
        transform(people.begin(), people.end(), people.begin(), [&](int p){
            return prev(mp.upper_bound(p))->second; 
        });
        
        return people;
*/

        //Approach-03: Prefix sum
        map<int,int> mp;
        
        for(auto &x : people)
            mp[x] = 0;
        
        // Formalising the Idea of Range Query Update in O(1) using the Map
        for(auto &v : flowers){
            int start = v[0], end = v[1]+1;
            mp[start]++;
            mp[end]--;
        }
        
        int total = 0;
		// Generating the Prefix Sum
        for(auto &p : mp){
            total += p.second;
            mp[p.first] = total;
        }
        
        int n = people.size();
        vector<int> ans(n);
        
		// Generating the Resultant vector, by just taking the values from the map.
        for(int i=0;i<n; i++){
            ans[i] = mp[people[i]];
        }
        return ans;
    }
};
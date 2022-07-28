class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        //first thinking dp
        //Time: 2^n
        
        /*sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
         return a[1]<b[1];
        });
        
        return recursive(courses, 0, 0);
        
        */
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
         return a[1]<b[1];
        });
        
        int sum = 0;
        
        priority_queue<int> pq;
        
        for(auto& x: courses){
            sum+=x[0];
            pq.push(x[0]);
            if(sum>x[1]){
                sum-=pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
        
    }
private:
    int recursive(vector<vector<int>> &courses, int i, int totalDay){
        if(i>=courses.size()) return 0;
        
        int taken = 0;
        int notTaken = 0;
        int duration = courses[i][0];
        int lastDay = courses[i][1];
        
        if(totalDay+duration<=lastDay){
            taken = 1 + recursive(courses, i+1, totalDay+duration);
        }
        notTaken = recursive(courses, i+1, totalDay);
        
        return max(taken, notTaken);
    }
};

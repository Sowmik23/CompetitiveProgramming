class Solution {
public:
    double average(vector<int>& salary) {
        
        int max = INT_MIN, min = INT_MAX;
        double sum = 0;
        for(int i: salary){
            if(i>max) max = i;
            if(i<min) min = i;
            // sum += i;
        }
        
        int cnt = 0;
        for(int i: salary){
            if(i!=max and i!=min) {
                // cout<<i<<endl;
                sum+= i;
                cnt++;
            }
        }
        // cout<<max<<" "<<min<<" "<<sum<<" "<<cnt<<endl;
        // sum-=(max+min);
        // cout<<sum<<endl;
        
        return sum/(double)cnt;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
       /* set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int mx = INT_MIN, sndmx = INT_MIN, trdmx = INT_MIN;
        
        //for(auto i: st) cout<<i<<" ";
        //cout<<*st.rbegin()<<endl;
        if(st.size()<3) return *st.rbegin();  //return last element of the set;
        else {
            mx = *st.rbegin();
            set<int>::reverse_iterator it;
            int flag1=0, flag2=0;
            
            for(it=st.rbegin(); it!=st.rend();it++){
                if(*it<mx and flag1==0){
                    sndmx = *it;
                    flag1=1;
                }
                else if(*it<mx and flag1==1 and *it<sndmx){
                    trdmx = *it;
                    break;
                }
            }
            return trdmx;
        }
        */
        
        long int mx = LONG_MIN, sndmx = LONG_MIN, trdmx = LONG_MIN;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(mx==nums[i] or sndmx==nums[i] or trdmx==nums[i]) continue;
            cnt++;
            if(nums[i]>mx){
                trdmx = sndmx;
                sndmx = mx;
                mx = nums[i];
            }
            else if(nums[i]>sndmx){
                trdmx = sndmx;
                sndmx = nums[i];
            }
            else if(nums[i]>trdmx){
                trdmx = nums[i];
            }
        }
        //cout<<mx<<" "<<sndmx<<" "<<trdmx<<endl;
        if(cnt>2) return trdmx;
        else return mx;
    }
};

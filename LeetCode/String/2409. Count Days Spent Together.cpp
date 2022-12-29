class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aMonth = stoi(arriveAlice.substr(0, 2));
        int aDate = stoi(arriveAlice.substr(3, 2));
        int lMonth = stoi(leaveAlice.substr(0, 2));
        int lDate = stoi(leaveAlice.substr(3, 2));

        int baMonth = stoi(arriveBob.substr(0, 2));
        int baDate = stoi(arriveBob.substr(3, 2));
        int blMonth = stoi(leaveBob.substr(0, 2));
        int blDate = stoi(leaveBob.substr(3, 2));


        vector<vector<int>> v = { {aMonth, aDate, 1}, {lMonth, lDate, 2}, {baMonth, baDate, 3}, {blMonth, blDate, 4}};
        sort(v.begin(), v.end());
        // for(auto& i: v){
        //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        // }
        // cout<<"Sowmik"<<endl;

        int res = 0;
        if(arriveAlice==arriveBob and leaveAlice==leaveBob) {
            int x = v[1][0];
            int y = v[2][0];
            int m1 = v[1][1];
            int m2 = v[2][1];

            if(x==y){
                res+= m2-m1+1;
            }
            else {
                // 4 14 3
                // 7 14 2
                int initial = m1;
                for(int i=x;i<y;i++){
                   // cout<<i<<" "<<months[i-1]-initial+1<<endl;
                    res+=months[i-1]-initial+1;
                    initial = 1;
                }
                res+=m2;
            }
            return res;
        }
        if(v[0][2]==1 and v[1][2]==2 and v[2][2]==3 and v[3][2]==4) return 0;
        else if(v[0][2]==3 and v[1][2]==4 and v[2][2]==1 and v[3][2]==2) return 0;
        else {
            int x = v[1][0];
            int y = v[2][0];
            int m1 = v[1][1];
            int m2 = v[2][1];

            if(x==y){
                res+= m2-m1+1;
            }
            else {
                // 4 14 3
                // 7 14 2
                int initial = m1;
                for(int i=x;i<y;i++){
                    //cout<<i<<" "<<months[i-1]-initial+1<<endl;
                    res+=months[i-1]-initial+1;
                    initial = 1;
                }
                res+=m2;
            }
            return res;
        }

        return 0;
    }
};

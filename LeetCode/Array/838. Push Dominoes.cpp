class Solution {
public:
    string pushDominoes(string dominoes) {

        int n = dominoes.size();
        vector<int> forces(n,  0);

        int force = 0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R')  force = n;
            else if(dominoes[i]=='L') force = 0;
            else force = max(force-1, 0);
            forces[i]+=force;
        }

        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L')  force = n;
            else if(dominoes[i]=='R') force = 0;
            else force = max(force-1, 0);
            forces[i]-=force;
        }

        string str = "";
        for(auto& f: forces){
            if(f>0) str+='R';
            else if(f<0)  str+='L';
            else str+='.';
        }

        return str;
    }
};

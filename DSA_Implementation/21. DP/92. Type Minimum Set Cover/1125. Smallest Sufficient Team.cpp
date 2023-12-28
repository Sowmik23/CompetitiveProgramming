// 1125. Smallest Sufficient Team
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        // => Weekend original plan - hang out with friendz 🥳
        // => New weekend plan - wrestling with three straight DPs to keep the 
        // leetcode streak alive 😩   

        // --> This is basically a minimum set cover problem. No matter why it is Hard.
        
        //TODO: Minimum set cover algorithm

        //Time: O(2^m * n)
        
        int m = req_skills.size();
        int n = people.size();

        unordered_map<string, int> skillId;
        for(int i=0;i<m;i++){
            skillId[req_skills[i]] = i;
        }

        vector<int> skillsMaskOfPerson(n);
        vector<long long> dp(1<<m, -1); //2^m

        for(int i=0;i<n;i++){
            for(string skill: people[i]){
                skillsMaskOfPerson[i] |= 1<<skillId[skill];
            }
        }

        // long long ansMask = func(n, (1<<m) - 1, dp, skillsMaskOfPerson);
        long long ansMask = recursiveWithMemo(n, (1<<m)-1, dp, skillsMaskOfPerson);

        vector<int> res;
        for(int i=0;i<n;i++){
            if((ansMask>>i)&1) res.push_back(i);
        }
        return res;
    }
private:
    long long recursiveWithMemo(int n, int skillHaveMask, vector<long long> &dp, vector<int> &skillsMaskOfPerson){
        if(skillHaveMask==0) return 0;
        if(dp[skillHaveMask]!=-1) return dp[skillHaveMask];

        long long ans = INT_MAX;
        for(int i=0;i<n;i++){
            int skills = skillHaveMask & ~skillsMaskOfPerson[i]; //no of skills from person i
            if(skills!=skillHaveMask){
                long long choosen = recursiveWithMemo(n, skills, dp, skillsMaskOfPerson) | (1LL<<i); //containing person i
                bitset<60> bChoosen(choosen);
                bitset<60> cntAns(ans);
                //check whether few people
                if(bChoosen.count()<cntAns.count()) ans = choosen;
            }
        }
        return dp[skillHaveMask] = ans;
    }



    long long func(int n, int skillMask, vector<long long> &dp, vector<int> &skillsMaskOfPerson){
        if(skillMask==0) return 0;
        if(dp[skillMask]!=-1) return dp[skillMask];

        for(int i=0;i<n;i++){
            int smallerSkillsMask = skillMask & ~skillsMaskOfPerson[i];
            if(smallerSkillsMask !=skillMask){
                long long peopleMask = func(n, smallerSkillsMask, dp, skillsMaskOfPerson) | (1LL<<i);
                if(dp[skillMask]==-1 || __builtin_popcountll(peopleMask)<__builtin_popcountll(dp[skillMask])){
                    dp[skillMask] = peopleMask;
                }
            }
        }
        return dp[skillMask];
    }
};
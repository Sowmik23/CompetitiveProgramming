// 1079. Letter Tile Possibilities
class Solution {
public:
    int numTilePossibilities(string tiles) {
        
        // backtracking + hashset
        string tmp="";
        backTrack(tiles, tmp);
        return st.size();
    }
private:
    set<string> st;
    unordered_map<int, bool> mp;

    void backTrack(string tiles, string tmp){
        if(tmp.size()>tiles.size()) return;
        if(tmp!="") st.insert(tmp);

        for(int i=0;i<tiles.size();i++){
            if(mp[i]) continue;
            tmp+=tiles[i];
            mp[i] = true;
            backTrack(tiles, tmp);
            tmp.pop_back();
            mp[i] = false;
        }
    }
};
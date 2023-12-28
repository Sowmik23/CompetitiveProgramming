// 1418. Display Table of Food Orders in a Restaurant
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        vector<vector<string>> res;
        map<int, map<string, int>> tableVsFood;
        map<string, bool> foods;

        for(auto& order: orders){
            int table = stoi(order[1]);
            string food = order[2];

            tableVsFood[table][food]++;
            foods[food] = true;
        }

        vector<string> tmp;
        tmp.push_back("Table");
        for(auto& food: foods){
            tmp.push_back(food.first);
        }
        res.push_back(tmp);

        for(int table=1;table<=500;table++){
            if(tableVsFood.find(table)!=tableVsFood.end()){
                //cout<<table<<": ";
                tmp = vector<string> ();
                tmp.push_back(to_string(table));
                for(auto& f: foods) {
                    string food = f.first;
                    //cout<<food<<" : "<<tableVsFood[table][food]<<" ";
                    tmp.push_back(to_string(tableVsFood[table][food]));
                }
                //cout<<endl;
                res.push_back(tmp);
            }
        }

        return res;
    }
};
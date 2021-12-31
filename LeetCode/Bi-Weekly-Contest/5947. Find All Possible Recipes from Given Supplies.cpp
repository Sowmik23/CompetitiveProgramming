class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        vector<string> res;
        unordered_map<string, int> recipe;
        unordered_map<string, int> supplie;
        
        for(int i=0;i<recipes.size();i++){
            recipe[recipes[i]] = i;
        }
        for(int i=0;i<supplies.size();i++){
            supplie[supplies[i]] = i;
        }
        isAvailable(recipes, recipe, supplie, ingredients, res);
        
        return res;
    }
private:
    void isAvailable(vector<string>& recipes, unordered_map<string, int> &recipe, unordered_map<string, int> &supplie, vector<vector<string>>& ingredients, vector<string> &res){
        
        for(int i=0;i<ingredients.size();i++){
            bool flag = true;
            
            for(int j=0;j<ingredients[i].size();j++){
                if(supplie.find(ingredients[i][j])!=supplie.end()){
                    continue;
                }
                else if(recipe.find(ingredients[i][j])!=recipe.end()){
                    int x = recipe[ingredients[i][j]];
                    
                    int lower = lower_bound(res.begin(), res.end(), ingredients[i][j])-res.begin();
                    if(lower>=0 and lower<res.size() and res.at(lower)==ingredients[i][j]) {
                        continue;
                    }
                    isAvailable(recipes, recipe, supplie, ingredients, res);
                }
                else flag = false;
                if(flag==false) break;
            }
            if(flag==true) res.push_back(recipes[i]);
        }
    }
};

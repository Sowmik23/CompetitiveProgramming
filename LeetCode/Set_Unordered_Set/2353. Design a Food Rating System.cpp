// 2353. Design a Food Rating System

class FoodRatings {
public:
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;
    unordered_map<string, set<pair<int, string>>> cuisineFood;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            cuisineFood[cuisines[i]].insert({-ratings[i], foods[i]}); 
        }
    }
    
    void changeRating(string food, int newRating) {

        auto cuisineName = foodCuisine[food];
        auto oldCuisineRating = cuisineFood[cuisineName].find({-foodRating[food], food});
        cuisineFood[cuisineName].erase(oldCuisineRating);

        foodRating[food] = newRating;
        cuisineFood[cuisineName].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        
        auto highestRated = *cuisineFood[cuisine].begin();
        return highestRated.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
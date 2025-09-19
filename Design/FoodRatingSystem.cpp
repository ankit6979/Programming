class FoodRatings {
public:
    struct Comparator {
        bool operator() (const pair<int, string>&a, const pair<int, string>&b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator>> cuisine_food_rating;
    map<string, int> food_rating;
    map<string, string> food_cuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int food = 0; food < foods.size(); ++food) {
            cuisine_food_rating[cuisines[food]].push(make_pair(ratings[food], foods[food]));
            food_rating[foods[food]] = ratings[food];
            food_cuisine[foods[food]] = cuisines[food];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        cuisine_food_rating[cuisine].push(make_pair(newRating, food));
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        while(cuisine_food_rating[cuisine].top().first != food_rating[cuisine_food_rating[cuisine].top().second]) {
            cuisine_food_rating[cuisine].pop();
        }
        return cuisine_food_rating[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

//  | Operation   | Time Complexity                                                             | Space Complexity |
// | ----------- | --------------------------------------------------------------------------- | ---------------- |
// | Constructor | **O(n log n)**                                                              | O(n)             |
// | Add         | **O(log n)**                                                                | +1               |
// | Edit        | **O(log n)**                                                                | +1 stale entry   |
// | Remove      | **O(log n)**                                                                | no heap shrink   |
// | ExecTop     | **O(log n)** amortized, but worst-case **O(k log n)** if many stale entries | shrinks map      |

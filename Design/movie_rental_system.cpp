class MovieRentingSystem {
public:
    struct Res {
        int price;
        int shop_id;
        int movie_id;

        bool operator<(const Res &other) const {
            if (price != other.price) 
                return price < other.price;
            if (shop_id != other.shop_id) 
                return shop_id < other.shop_id;
            return movie_id < other.movie_id;
        }
    };
    struct ShopMoviePrice {
        int price;
        int shop_id;

        bool operator< (const ShopMoviePrice &other) const {
            if (price == other.price) return shop_id < other.shop_id;
            return price < other.price; 
        }
    };
    unordered_map<int, unordered_set<int>> movie_by_shop;
    unordered_map<int, unordered_map<int, int>> movie_price;
    unordered_map<int, set<ShopMoviePrice>> shop_by_movie;
    set<Res> rented_movies;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            movie_by_shop[entry[0]].insert(entry[1]);
            movie_price[entry[1]][entry[0]] = entry[2];
            shop_by_movie[entry[1]].insert({entry[2], entry[0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> movie_list;
        int no_of_movies = 0;
        set<ShopMoviePrice>:: iterator it = shop_by_movie[movie].begin();
        
        while (it != shop_by_movie[movie].end() && no_of_movies < 5) {
            movie_list.push_back(it->shop_id);
            ++no_of_movies;
            ++it;
        }

        return movie_list;
    }
    
    void rent(int shop, int movie) {
        if (movie_by_shop[shop].find(movie) != movie_by_shop[shop].end()) {
            int price_of_movie = movie_price[movie][shop];
            movie_by_shop[shop].erase(movie);
            rented_movies.insert({price_of_movie, shop, movie});
            if (shop_by_movie[movie].find({price_of_movie, shop}) != shop_by_movie[movie].end()) {
                shop_by_movie[movie].erase({price_of_movie, shop});
            }
        }
    }
    
    void drop(int shop, int movie) {
        movie_by_shop[shop].insert(movie);
        int price_of_movie = movie_price[movie][shop];
        shop_by_movie[movie].insert({price_of_movie, shop});
        rented_movies.erase({price_of_movie, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int no_of_movies = 0;
        set<Res>:: iterator it = rented_movies.begin();
        
        while (it != rented_movies.end() && no_of_movies < 5) {
            ans.push_back({it->shop_id, it->movie_id});
            ++no_of_movies;
            ++it;
        }
       return ans; 
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
class ProductOfNumbers {
public:
    vector<int> number_stream;
    int zero_idx, curr_idx;
    ProductOfNumbers() {
        curr_idx = 0;
        zero_idx = INT_MIN;
    }
    
    void add(int num) {
        if(num == 0) {
            zero_idx = curr_idx;
        }
        if(number_stream.size()) {
            if(number_stream[number_stream.size() - 1] == 0) {
                number_stream.push_back(num);
            }
            else {
                number_stream.push_back(number_stream[number_stream.size() - 1] * num);
            }
        }
        else {
            number_stream.push_back(num);
        }
        curr_idx += 1;
    }
    
    int getProduct(int k) {
        if((long long)(number_stream.size() - k) <= zero_idx) {
            // cout<<number_stream.size() - k<<" "<<zero_idx<<endl;
            // cout<<" yes"<<endl;
            return 0;
        }
        else if(k == number_stream.size() || number_stream[number_stream.size() - k - 1] == 0) {
            return number_stream[number_stream.size() - 1];
        }
        else if(number_stream.size() && k <= number_stream.size()) {
            return (number_stream[number_stream.size() - 1] / number_stream[number_stream.size() - k - 1]);
        }
        else {
            return 1;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
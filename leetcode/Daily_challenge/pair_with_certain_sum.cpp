class FindSumPairs {
public:
    unordered_map<int, int> nums1Counts;
    unordered_map<int, int> nums2Counts;
    vector<int> nums2Data;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            nums1Counts[num] += 1;
        }
        for (int num : nums2) {
            nums2Counts[num] += 1;
        }
        nums2Data = nums2;
    }
    
    void add(int index, int val) {
        int oldVal = nums2Data[index];;
        int newVal = oldVal + val;
        
        if (--nums2Counts[oldVal] == 0) {
            nums2Counts.erase(oldVal);
        }

        nums2Data[index] = newVal;
        nums2Counts[newVal]++;
    }
    
    int count(int tot) {
        int totalPairs = 0;
        for(auto const& [num, count1] : nums1Counts) {
            int complement = tot - num;
            auto it = nums2Counts.find(complement);
            if (it != nums2Counts.end()) {
                totalPairs += count1 * it->second;
            }
        }
        return totalPairs;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long sum_nums1 = 0, sum_nums2 = 0, count_zeroes_nums1 = 0, count_zeroes_nums2 = 0, min_sum = 0;
    
            for (auto num : nums1) {
                if(num == 0) {
                    count_zeroes_nums1 += 1;
                }
                sum_nums1 += num;
            }
    
            for (auto num : nums2) {
                if(num == 0) {
                    count_zeroes_nums2 += 1;
                }
                sum_nums2 += num;
            }
    
            //-1 condition
            if((count_zeroes_nums1 == 0 && sum_nums2 + count_zeroes_nums2 > sum_nums1) || ((count_zeroes_nums2 == 0 && sum_nums1 + count_zeroes_nums1 > sum_nums2))) {
                return -1;
            }
    
            if(count_zeroes_nums1 >= count_zeroes_nums2) {
                sum_nums1 += count_zeroes_nums2;
                sum_nums2 += count_zeroes_nums2;
                count_zeroes_nums1 -= count_zeroes_nums2;
                if(sum_nums2 >= sum_nums1 + count_zeroes_nums1) {
                    min_sum = sum_nums2;
                }
                else{
                    min_sum = sum_nums1 + count_zeroes_nums1;
                }
            }
    
            else {
                sum_nums1 += count_zeroes_nums1;
                sum_nums2 += count_zeroes_nums1;
                count_zeroes_nums2 -= count_zeroes_nums1;
                if(sum_nums1 >= sum_nums2 + count_zeroes_nums2) {
                    min_sum = sum_nums1;
                }
                else{
                    min_sum = sum_nums2 + count_zeroes_nums2;
                }
            }
    
            return min_sum;
        }
    };
    auto init = []() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return 'c';
    }();
// Time -> O(n*ln(n)) space -> O(n) solution using map
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> numsFreq;
        int n = nums.size()/2;
        int repeatedNTimesNum;

        for (int num : nums) {
            if (numsFreq.find(num) != numsFreq.end()) {
                numsFreq[num] += 1;
                if (numsFreq[num] == n) {
                    repeatedNTimesNum = num;
                }
            }
            else {
                numsFreq[num] = 1;
            }
        }

        return repeatedNTimesNum;
    }
};

// Time -> O(n) space -> 0(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int firstNum = -1, secondNum = -1, freq = 0;
        int n = nums.size()/2;

        for (int num : nums) {
            if (num == firstNum) {
                freq += 1;
            }
            else {
                if (freq == 0) {
                    secondNum = firstNum;
                    firstNum = num;
                    freq = 1;
                }
                else if (freq == 1){
                    secondNum = firstNum;
                    firstNum = num;
                    freq = 0;
                }
                else {
                    freq -= 1;
                }
            }
        }

        int freqFirstNum = 0, freqSecondNum = 0;
        for (int num : nums) {
            if (num == firstNum) {
                freqFirstNum += 1;
            }
            else if (num == secondNum) {
                freqSecondNum += 1;
            }
        }

        cout<<firstNum<<" "<<secondNum<<" "<<n<<endl;
        if (freqFirstNum == n) {
            return firstNum;
        }
        return secondNum;
    }
};
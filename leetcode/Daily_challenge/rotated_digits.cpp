class Solution {
public:
    bool isGood (int num) {
        bool grp1 = false, grp2 = false, grp3 = false;

        while (num != 0) {
            int digit = num % 10;
            if (digit == 0 || digit == 1 || digit == 8) {
                grp1 = true;
            }
            else if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                grp2 = true;
            }
            else {
                grp3 = true;
            }
            num = num / 10;
        }

        if (grp3) return false;
        else if ((grp1 && grp2) || grp2) return true;
        else return false;
    }
    int rotatedDigits(int n) {
        int good_nums = 0;

        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                good_nums += 1;
            }
        }

        return good_nums;
    }
};
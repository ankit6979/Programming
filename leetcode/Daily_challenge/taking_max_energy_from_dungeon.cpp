class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxEnergy = INT_MIN;
        int magicians = energy.size();
        vector<int> visited (magicians, -1);
        bool reset;
        int currPower;

        for (int magician = 0; magician < magicians; ++magician) {
            int startMagician = magician;
            reset = true;

            while (startMagician < magicians && visited[startMagician] == -1) {
                if (reset) {
                    currPower = energy[startMagician];
                    reset = false;
                }
                else {
                    currPower += energy[startMagician];
                }
                if (currPower < 0) {
                    reset = true;
                }
                visited[startMagician] = 1;
                startMagician = startMagician + k;
            }
            maxEnergy = max (maxEnergy, currPower);
        }

        return maxEnergy;
    }
};
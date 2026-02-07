class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = 0, emptyBottles = numBottles, numOfExchange = numExchange, drunkBottles = numBottles;

        while (numOfExchange <= (fullBottles + emptyBottles)) {
            // Exchange step
            if (emptyBottles >= numOfExchange) {
                emptyBottles -= numOfExchange;
                fullBottles += 1;
                numOfExchange += 1;
            }
            // Drink step
            if (fullBottles) {
                drunkBottles += fullBottles;
                emptyBottles += fullBottles;
                fullBottles = 0;
            }
        }

        return drunkBottles;
    }
};
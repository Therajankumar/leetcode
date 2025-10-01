class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int drank = numBottles;      // total bottles we drink
        int empty = numBottles;      // initially empty after drinking them

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;   // how many new bottles we can get
            drank += newBottles;                   // drink them
            empty = empty % numExchange + newBottles; // remaining empty + new empty
        }

        return drank;
    }
};
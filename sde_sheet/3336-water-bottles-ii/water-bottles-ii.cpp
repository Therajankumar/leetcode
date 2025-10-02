class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
         int ans = numBottles;  // you can immediately drink all full bottles you initially have
        
        while (numBottles >= numExchange) {
            // Use numExchange empties to get 1 full bottle:
            // after drinking, your new numBottles = (numBottles - numExchange) + 1 (the new one you get and drink)
            numBottles = (numBottles - numExchange + 1);
            ans++;
            // increase the cost for next exchange
            numExchange++;
        }
        
        return ans;
    }
};
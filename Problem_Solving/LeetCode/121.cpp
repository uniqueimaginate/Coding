class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNum = numeric_limits<int>::max();
        int maxNum = numeric_limits<int>::min();
        int profit = 0;
        int n = prices.size();
        for(int i=0; i<n; ++i){
            if(prices[i] < minNum){
                minNum = prices[i];
            } 
            else{
                profit = max(profit, prices[i] - minNum);
            }
            
        }
        return profit;
    }
};
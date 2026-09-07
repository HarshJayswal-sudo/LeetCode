class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyAT=prices[0],maxprofit = 0;
       
            int profit=0;
            for(int i=1;i<prices.size();i++){
                if(buyAT<prices[i]){
                    profit+=prices[i]-buyAT;
                    buyAT=prices[i];
                }else{
                    buyAT = prices[i];
                }
            }
            return profit;
            
    }
};
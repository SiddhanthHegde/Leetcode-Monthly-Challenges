class Solution {
    public int maxProfit(int k, int[] prices) {
        if(k==0 || prices.length==0)return 0;
         int[] profit = new int[prices.length];
        if(k>=prices.length/2){
             int p = 0;
              for(int i=1;i<prices.length;i++){
             if(prices[i]>prices[i-1]){
               p = p+ prices[i]-prices[i-1]; 
             }
           }
           return p;
        }
        
        //1 trans 
        int min = prices[0] , p = 0;
        for(int i =0;i<prices.length;i++){
            min = Math.min(min,prices[i]);
            p = Math.max(p,prices[i]-min);
            profit[i]=p;
        }
        
        //k = 3
        for(int i=1;i<k;i++){
           ktimes(prices, profit);      
        } 
        
        int ans = 0;
        for(int i=0;i<profit.length;i++){
            ans = Math.max(profit[i],ans);
        }
        
        return ans;
    }
    
     void ktimes(int[] prices,int[] profit){
          int b2 = Integer.MAX_VALUE;
          int p2 = 0;
          for(int i=0;i<prices.length;i++){
           b2 = Math.min(b2,prices[i]-profit[i]);
           p2 = Math.max(p2,prices[i]-b2);
           profit[i] = p2;
          }  
     }
}
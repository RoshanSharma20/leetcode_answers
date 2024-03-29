class Solution {
public:
    long long int solution(int index,vector<int>& coins,vector<vector<long long int>>& dp,int target)
    {
        if(index==0)
        {
            return (target%coins[0]==0);
        }
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        int nottake = solution(index-1,coins,dp,target);
        int take = 0;
        if(coins[index]<=target)
            take = solution(index,coins,dp,target-coins[index]);
        return dp[index][target]=take+nottake;
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<long long int>> dp(coins.size(),vector<long long int>(amount+1,0));
        // return solution(coins.size()-1,coins,dp,amount);
        for(int i=0;i<=amount;++i)
        {
            if(i%coins[0]==0)
                dp[0][i]=1;
        }
        
        for(int i=1;i<coins.size();++i)
        {
            for(int sum=0;sum<=amount;++sum)
            {
                int nottake = dp[i-1][sum];
                int take = 0;
                if(coins[i]<=sum)
                    take = dp[i][sum-coins[i]];
                dp[i][sum]=take + nottake;
            }
        }
        return dp[coins.size()-1][amount];
    }
};
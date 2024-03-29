//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solution(int index,int W,int wt[],int val[],vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(W>=wt[0])
                return val[0];
            else
                return 0;
        }
        
        if(dp[index][W]!=-1)
            return dp[index][W];
        
        int notpick = solution(index-1,W,wt,val,dp);
        int pick = -1e9;
        if(wt[index]<=W)
        {
            pick = val[index]+solution(index-1,W-wt[index],wt,val,dp);
        }
        
        return dp[index][W]=max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,0));
    //   return solution(n-1,W,wt,val,dp);
        for(int x=wt[0];x<=W;++x)
        {
            dp[0][x]=val[0];
        }
        
        for(int index=1;index<n;++index)
        {
            for(int x=0;x<=W;++x)
            {
                int notpick = dp[index-1][x];
                int pick = -1e9;
                if(wt[index]<=x)
                {
                    pick = val[index]+dp[index-1][x-wt[index]];
                }
                dp[index][x]=max(pick,notpick); 
            }
        }
        return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
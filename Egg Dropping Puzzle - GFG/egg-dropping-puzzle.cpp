//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solution(int e,int f,vector<vector<int>> &dp)
    {
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        
        if(dp[e][f]!=-1)
            return dp[e][f];
         
        int mini = INT_MAX;   
        for(int k=1;k<=f;++k)
        {
            int temp = 1 + max(solution(e-1,k-1,dp),solution(e,f-k,dp));
            mini = min(temp,mini);
        }
        return dp[e][f]=mini;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solution(n,k,dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solution(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if(i==j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i;k<j;++k)
        {
            mini=min(mini,arr[i-1]*arr[k]*arr[j]+solution(i,k,arr,dp)+solution(k+1,j,arr,dp));
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        // return solution(1,N-1,arr,dp);
        
        for(int i=N-1;i>=1;--i)
        {
            for(int j=i+1;j<N;++j)
            {
                int mini = INT_MAX;
                for(int k=i;k<j;++k)
                {
                    mini=min(mini,arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                }
                dp[i][j]=mini; 
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n,1),count(n,0);
	    int maxi_val=arr[0];
	    count[0]=arr[0];
	    for(int i=1;i<n;++i)
	    {
	        count[i]=arr[i];
	        for(int j=0;j<i;++j)
	        {
	            if(arr[j]<arr[i] && count[i]<count[j]+arr[i])
	            {
	               // dp[i]=dp[j]+1;
	                count[i]=arr[i]+count[j];
	                maxi_val=max(maxi_val,count[i]);
	            }
	        }
	    }
	    return maxi_val;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
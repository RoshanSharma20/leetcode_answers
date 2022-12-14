class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int curr=0,res=0;
        stack<int> s;
        for(int i=0;i<n;++i)
        {
            while((s.empty()==false) && (heights[s.top()]>=heights[i]))
            {
                int tp = s.top();
                s.pop();
                curr = heights[tp]*(s.empty()?i:(i-s.top()-1));
                res=max(curr,res);
            }
            s.push(i);
        }
        while(s.empty()==false)
        {
            int tp = s.top();
            s.pop();
            curr = heights[tp]*(s.empty()?n:(n-s.top()-1));
            res=max(res,curr);
        }
        return res;
    }
};
class Solution {
public:
    int n;
    vector<vector<int>>dp;
    vector<int>dp2;

    int solve(int i,int j,string &s){
        if(i>=j)return dp[i][j]= 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = solve(i+1,j-1,s);
        return dp[i][j] = 0;
    }

    int solve2(int i,int l,string &s){
        if(i==s.size())return 0;
        if(dp2[i]!=-1)return dp2[i];   
        int ans=0;
        ans=max(ans,solve2(i+1,l,s));
        for(int k=i;k<n;k++){
            if(dp[i][k] == 1 && (k-i+1)>=l )ans = max(ans,1+solve2(k+1,l,s));
        }
        return dp2[i] =  ans;
    }
    int maxPalindromes(string s, int k) {
         n = s.size();
         dp.resize(n+1,vector<int>(n+1,-1));
         dp2.resize(n+1,-1);

         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                solve(i,j,s);
            }
         } 
         int ans=solve2(0,k,s);
         return ans;
    }
};
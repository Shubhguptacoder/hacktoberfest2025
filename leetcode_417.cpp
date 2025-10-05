class Solution {
public:
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    void solve(int i , int j , int n , int m ,vector<vector<int>>& heights , vector<vector<int>>&vis){
        if(i<0 or j<0 or i>=n or j>=m) return ;
        vis[i][j]=1;
        
       

        for(int k=0;k<4;k++){
            int new_i = i+dir[k].first;
            int new_j = j+dir[k].second;
            if(new_i>=0 and new_j>=0 and new_i<n and new_j<m ){
                if( heights[new_i][new_j]>=heights[i][j] and !vis[new_i][new_j])
               solve(new_i,new_j,n,m,heights,vis);
            }
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>vis1(n,vector<int>(m,0));
         vector<vector<int>>vis2(n,vector<int>(m,0));

        //pacific
        for(int i=0;i<m;i++){
            solve(0,i,n,m,heights,vis1);
        }
        
        //pacific
        for(int i=0;i<n;i++){
            solve(i,0,n,m,heights,vis1);
        }
        
        // Atlantic
        for(int i=0;i<m;i++){
            solve(n-1,i,n,m,heights,vis2);
        }

        // Atlantic
        for(int i=0;i<n;i++){
            solve(i,m-1,n,m,heights,vis2);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] and vis2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};

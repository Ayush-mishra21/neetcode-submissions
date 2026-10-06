class Solution {
   public:
   vector<int>ans,visited,done;
   vector<vector<int>>adj;
    bool solve(int node){
        if(visited[node])return false;
        if(done[node])return true;
        visited[node] = 1;
        for(int A : adj[node]){
            if(!solve(A)){
                return false;
            }
        }
        ans.push_back(node);
        done[node] = 1;
        visited[node] = 0;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {       adj.resize(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        done.resize(numCourses, 0);
        visited.resize(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(!solve(i))return {};
        }
        return ans;
}
};

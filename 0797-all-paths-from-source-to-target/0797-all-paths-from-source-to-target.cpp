class Solution {
public:
    void dfs(int node, vector<int>&path, vector<vector<int>>&paths, vector<vector<int>>&graph){
        path.push_back(node);
        if(node==graph.size()-1){
            paths.push_back(path);
        }
        else for(auto it: graph[node]){
            dfs(it, path, paths, graph);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>paths;
        vector<int>path;
        dfs(0, path, paths, graph);
        return paths;
    }
};
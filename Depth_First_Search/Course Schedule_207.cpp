//bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].insert(pre.first);
        }
        vector<int> indegree(numCourses);
        for(auto adj_list: graph){
            for(int adj: adj_list){
                ++indegree[adj];
            }
        }
        queue<int> noPre;
        for(int i = 0; i < numCourses; ++i){
            if(!indegree[i]) noPre.push(i);
        }
        for(int i = 0; i < numCourses; ++i){
            if(noPre.empty()) return false;
            int pre = noPre.front();
            noPre.pop();
            for(int course: graph[pre]){
                if(!--indegree[course])
                    noPre.push(course);
            }
        }
        return true;
    }
};

//dfs 
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].insert(pre.first);
        }
        vector<bool> onPath(numCourses), visited(numCourses);
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i, onPath, visited, graph))
                return false;
        }
        return true;
    }
    
    bool dfs(int node, vector<bool>& onPath, vector<bool>& visited, vector<unordered_set<int>>& graph){
        if(visited[node]) return true;
        if(onPath[node]) return false;
        onPath[node] = true;
        for(int adj: graph[node]){
            if(!dfs(adj, onPath, visited, graph))
                return false;
        }
        visited[node] = true;
        return true;
    }
};
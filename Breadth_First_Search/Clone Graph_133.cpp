/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//bfs
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        mp[node] = nodeCopy;
        while(!q.empty()){
            UndirectedGraphNode* n = q.front();
            q.pop();
            for(auto v: n->neighbors){
                if(!mp.count(v)){
                    UndirectedGraphNode* u = new UndirectedGraphNode(v->label);
                    mp[v] = u;
                    q.push(v);
                }
                mp[n]->neighbors.push_back(mp[v]);
            }
            
        }
        return nodeCopy;
    }
};
//dfs
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        if(!mp.count(node)){
            mp[node] = new UndirectedGraphNode(node->label);
            for(auto v: node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(v));
            }
        }
        return mp[node];
    }
};
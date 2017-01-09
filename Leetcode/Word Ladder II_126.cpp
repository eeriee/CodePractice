// double ended bfs. Actually it can use a simple dijkstra to find the path first and then print.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> paths;
        if(!bfs(mp, beginWord, endWord, wordList)) return paths;
        vector<string> path;
        path.push_back(beginWord);
        getPath(path, paths, mp, beginWord, endWord);
        return paths;
    }
    bool bfs(unordered_map<string, vector<string>>& mp, string& beginWord, string& endWord, unordered_set<string> &wordList){
        unordered_set<string> beginList({beginWord}), endList({endWord});
        bool begin = true;
        bool done = false;
        while(!beginList.empty() && !endList.empty()){
            unordered_set<string> midList;
            if(beginList.size() > endList.size()){
                begin = !begin;
                swap(beginList, endList);
            }
            //avoid the visited node in the shortest path to be visited again
            for(string s: beginList) wordList.erase(s);
            for(string s: endList) wordList.erase(s);
            for(string s: beginList){
                string word = s;
                for(int i = 0; i < s.size(); ++i){
                    char letter = s[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        s[i] = c;
                        if(endList.count(s)){
                            begin? mp[word].push_back(s):mp[s].push_back(word);
                            done = true;
                        }
                        if(wordList.count(s)){
                            begin? mp[word].push_back(s):mp[s].push_back(word);
                            midList.insert(s);
                        }
                    }
                    s[i] = letter;
                }
            }
            if(done) return true;
            swap(beginList, midList);
        }
        return false;
    }
    void getPath(vector<string>& prev, vector<vector<string>>& res, unordered_map<string, vector<string>>& mp, string& word, string& endWord){
        if(word == endWord){
            res.push_back(prev);
            return;
        }
        for(string s: mp[word]){
            prev.push_back(s);
            getPath(prev, res, mp, s, endWord);
            prev.pop_back();
        }
    }
};

// slow method
//1). Use BFS to find the shortest distance between start and end, tracing the distance of crossing nodes from start node to end node, and store node's next level neighbors to HashMap;
//2). Use DFS to output paths with the same distance as the shortest distance from distance HashMap: compare if the distance of the next level node equals the distance of the current node + 1.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, unordered_set<string>> mp;
        unordered_map<string, int> dist;
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        bool find = false;
        int len = 0;
        //bfs
        dist[beginWord] = 0;
        while(!q.empty() && !find){
            int breadth = q.size();
            ++len;
            for(int i = 0; i < breadth; ++i){
                string word = q.front();
                string tmp = word;
                q.pop();
                for(int j = 0; j < word.size(); ++j){
                    char letter = word[j];
                    for(char c = 'a'; c <= 'z'; ++c){
                        if(letter == c) continue;
                        word[j] = c;

                        if(wordList.count(word)){
                            mp[tmp].insert(word);
                            if(dist.count(word)){
                                continue;
                            } 
                            dist[word] = len;
                            q.push(word);
                        }
                        
                        if(word == endWord){
                            find = true;
                            break;
                        }
                    }
                    word[j] = letter;
                }
            }
        }
        vector<vector<string>> res;
        vector<string> prev({beginWord});
        printPath(prev, res, mp, beginWord, endWord, dist);
        return res;
    }
    void printPath(vector<string>& prev, vector<vector<string>>& res, unordered_map<string, unordered_set<string>>& mp, string& word, string& endWord, unordered_map<string,int>& dist){
        if(word == endWord){
            res.push_back(prev);
            return;
        }
        
        for(string s: mp[word]){
            if(dist[s] == dist[word]+1){
                prev.push_back(s);
                printPath(prev, res, mp, s, endWord, dist);
                prev.pop_back();
            }
        }
    }
};
/*
Why use hash table? Not O(n^2) preprocessing time while O(1) for shortest? 
The O(n^2) + O(1) solution is a poor decision any time n (the number of words) > the number of times shortest method is called. 
Lets take an example say n = 64 and shortest is called 20 times. 
Now if we look at the approximate total number of operations in our O(n^2) + O(1) solution we would get 64^2 + 20 = 4116. 
now if you observe others O(n)+O(n) solution their approximate total number of operations would be 64 + (20 * 64) = 1280.
In short O(n^2) + O(1) solution is only better if shortest is called n times.
*/

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i){
            mp[words[i]].push_back(i); 
        }
    } // O(n)

    int shortest(string word1, string word2) {
        int dist = INT_MAX;
        vector<int> v1 = mp[word1], v2 = mp[word2]; 
        //copy the vector is faster than directly use mp[word1] to access value
        //52ms vs 68 ms
        for(int i = 0, j = 0; i < v1.size() && j < v2.size(); ){
            int w1 = v1[i], w2 = v2[j];
            dist = min(dist, abs(w1 - w2));
            if(w1 < w2) ++i;
            else ++j;
        }
        return dist;
    } //O(n+m)
    
private:
    unordered_map<string, vector<int>> mp;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

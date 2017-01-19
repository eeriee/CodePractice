// faster
class Vector2D {
private:
    vector<vector<int>>::iterator i, iend;
    int j;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iend = vec2d.end();
        j = 0;
    }

    int next() {
        return (*i)[j++];
    }

    bool hasNext() {
        while(i != iend && j == (*i).size()){ // to skip empty vector
            ++i;
            j = 0;
        }
        return i != iend;
    }
};

// slower solution 
class Vector2D {
private:
    queue<pair<vector<int>::iterator,vector<int>::iterator>> q;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(vector<int>& vec: vec2d){ // be aware of &, it gives a reference
            if(!vec.empty()){
                q.push(make_pair(vec.begin(), vec.end()));
            }            
        }
    }

    int next() {
        vector<int>::iterator it1 = q.front().first;
        vector<int>::iterator it2 = q.front().second;
        if(it1+1 != it2){
            q.front().first = it1+1;
        }else{
            q.pop();
        }
        return *it1;
    }

    bool hasNext() {
        return !q.empty();
    }
};
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
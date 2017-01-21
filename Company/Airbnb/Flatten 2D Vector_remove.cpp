#include <iostream>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"

class vector2D{
  private:
    vector<vector<int>>::iterator start, p, end;
    int idx;
  public:
    vector2D(vector<vector<int>> & vec){
      start = vec.begin();
      p = start;
      end = vec.end();
      idx = 0;
    }
    
    int getNext(){
      return (*p)[idx++];
    }
    bool hasNext(){
     while(p != end && idx == (*p).size()){
        ++p;
        idx = 0; 
     }
     return p != end;
    }
    void remove(){
      if(p == start && idx == 0) return;
      if(idx) --idx;
      else{
        while(p != start && idx == 0){
          --p;
          idx = (*p).size()-1; 
        }    
      }
      (*p).erase((*p).begin() + idx);
    }
  
};
int main() {
  vector<vector<int>> vec = {{0},{1},{2},{3,4,5}};
  vector2D vec2d(vec);
  if(vec2d.hasNext()) cout << vec2d.getNext() << endl;
  if(vec2d.hasNext()) cout << vec2d.getNext() << endl;
  if(vec2d.hasNext()) cout << vec2d.getNext() << endl;
  vec2d.remove();
  for(auto nums: vec){
    for(int num: nums)
      cout << num << endl;
  }
  if(vec2d.hasNext()) cout << vec2d.getNext() << endl;
  if(vec2d.hasNext()) cout << vec2d.getNext() << endl;
  return 0;
}

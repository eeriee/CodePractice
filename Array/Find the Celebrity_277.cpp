// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int cel = 0;
        
        for(int i = 1; i < n; ++i){
            if(!knows(i, cel)) cel = i;
        }
        
        for(int i = 0; i < cel; ++i){
            if(knows(cel,i) || !knows(i,cel)){
                return -1;
            }
        }

        for(int i = cel+1; i < n; ++i){
            if(knows(cel,i)){
                return -1;
            }
        }
        
        return cel;
    }
};
//Moore's Voting Algorithm 

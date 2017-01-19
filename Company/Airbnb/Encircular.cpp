/*
 We are given a string consisting of letters- F,L,R. - which is the instruction a robot follows

F- goes forward by one step.

L-turn left.

R- turn right.

String length can be upto 2500 characters.

The string runs itself infinite times. We need to tell if there exists a circle with a radius, r( r can be any real number), such that the robot never leaves the circle. 
 */
bool existCircle(string& str){
    int direction = 0; // N, E, S, W
    int x = 0, y = 0;
    for(int i = 0; i < 4; ++i){
        for(char c: str){
            switch(c){
                case 'G':
                    if(direction%2){
                        x += 2-direction;
                    }else{
                        y += 1-direction;
                    }
                    break;
                case 'R':
                    if(direction == 3) direction = 0;
                    else  ++direction;
                    break;
                case 'L':
                    if(!direction) direction = 3;
                    else --direction;
                    break;
                default:
                    return false;
            }
        }
        if(!x && !y) return true;
    }
    return false; 
}
vector < string > doesCircleExist(vector < string > commands) {
    vector<string> res;
    for(string command: commands){
        if(existCircle(command)){
            res.push_back("YES");
        }else{
            res.push_back("NO");
        }
    }
    return res;
}


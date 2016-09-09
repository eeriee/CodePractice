//first idea. # of strings + " " + length of each string + " " +strings.
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = to_string(strs.size()) + " ";
        for(string s: strs){
            encoded += to_string(s.size()) + " ";
        }
        for(string s: strs){
            encoded += s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n, i;
        vector<int> lens;
        for(i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                n = stoi(s.substr(0,i));
                cout<<n<<endl;
                break;
            }
        }
        int start = ++i;
        for(int j = 0; j < n; ++j){
            while(s[i] != ' ') ++i;
            string l = s.substr(start, i-start);
            lens.push_back(stoi(l));
            start = ++i;
        }
        vector<string> decoded;
        for(int len: lens){
            decoded.push_back(s.substr(start, len));
            start = start+len;
        }
        return decoded;
    }
};
//optimal solution. len of str + " " + str.
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(string s: strs){
            encoded += to_string(s.size()) + " " + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i = 0; i < s.size();){
            int pos = s.find_first_of(" ", i);
            int len = stoi(s.substr(i, pos-i));
            decoded.push_back(s.substr(pos+1, len));
            i = pos+len+1;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

/*Question:
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

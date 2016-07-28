class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i = 0; i < dictionary.size(); ++i){
            string word = dictionary[i];
            string abbr = getAbbr(word);
            abbrDict[abbr].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        if(abbrDict.find(abbr) == abbrDict.end()) 
            return true;
        set<string> dict = abbrDict[abbr];
        if(dict.find(word) != dict.end() && dict.size() == 1)
            return true;
        return false;
    }
    
    string getAbbr(string word){
        int len = word.length();
        if(len <= 2) return word;
        return word[0] + to_string(len-2) + word[len-1];
    }
private:
    unordered_map<string, set<string>> abbrDict;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
/* 
Question:
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

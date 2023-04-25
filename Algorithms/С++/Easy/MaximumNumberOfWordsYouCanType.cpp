    /*
        There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
        Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken,
        return the number of words in text you can fully type using this keyboard
    */



class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
      int count = 0 ;
      string word="";

      for(int i  = 0;i<text.size();++i) {
          if(text.at(i)==' ') {
              if(word.find_first_of(brokenLetters)==string::npos) {
                  count++;
              }
              word="";
          } else {
              word+=text[i];
          }
      }
        if(word.find_first_of(brokenLetters)==string::npos) {
            count++;
        }
        return count;
    }
};

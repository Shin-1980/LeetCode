class Solution {

private:
    bool checkTransform(string s1, string s2) {
        
        int dif = 0;
        for (int i=0;i<s1.size();i++) {
            if (s1[i] != s2[i]) dif++;
        }

        if (dif == 1) return true;
        return false;
        
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool log[wordList.size()];
        for (int i=0;i<wordList.size();i++) log[i] = 0;
        
        queue<string> q;
        q.push(beginWord);
        int wordCount = 1;

        while (!q.empty()) {
            wordCount++;
            int loop = q.size();
            //cout << loop << endl;
            for (int i=0;i<loop;i++) {
                string s1 = q.front();
                q.pop();
                //cout << q.size() << endl;

                int idx = 0;
                for(auto word: wordList){
                    //cout << word << endl;
                    if (!log[idx] && checkTransform(s1,word)){
                        //cout << "find " << word << endl;
                        q.push(word);
                        log[idx] = true;
                        if (word == endWord) {
                            return wordCount;
                        }
                    }
                    idx++;
                }
            }
        }
        return 0;

    }
};

/*
return the number of words in the shortest transformation sequence
0 if no such sequence exists.

hit -> hot -> dot ->lot 

*/
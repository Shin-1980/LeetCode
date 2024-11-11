class Solution {
public:
    bool isValid(string s) {

        std::stack<char> stc = {};

        for (auto c: s) {
            cout << c << std::endl;
            if (c == '(' || c == '{' || c == '[') {
                stc.push(c);
            }
            else{
                if (stc.empty()){
                    return false;
                }
                else{
                    char tmp = stc.top();

                    if ((c == ')' && tmp != '(') || (c == '}' && tmp != '{') || (c == ']' && tmp != '[')) {                        
                        return false;
                    }
                    stc.pop();
                }
            }
        }

        return stc.empty();
    }
};

// using three stacks: use arraies
// (,{, or [ is called: 
// push ), ], or } is called pop (if no value in stuck, error)
// if all stacks are empty, OK

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ht;

        int mse = 0;// max size of emails address

        for (const string& email : emails) {
            string local;
            for (const char c : email) {
                if (c == '+' || c == '@') break;
                if (c == '.') continue;
                local += c;
            }
            
            string domain = email.substr(email.find('@'));
            ht.insert(local + domain);
        }

        return ht.size();
    }
};

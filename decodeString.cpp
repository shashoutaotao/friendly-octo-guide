class Solution {
public:
    bool isDigit(char d) {
        if(d <= '9' && d >= '0') {
            return true;
        }
        return false;
    }
    string decodeString(string str) {
        stack<char> s;
        for(int n = 0; n < str.size(); ++n) {
            s.push(str[n]);
            int index;
            switch(s.top()) {
                case ']': {
                    s.pop();
                    vector<char> letter;
                    vector<char> digit;
                    while(s.top() != '[') {
                        letter.push_back(s.top());
                        s.pop();
                    }
                    s.pop();
                    while(!s.empty() && isDigit(s.top())) {
                        digit.push_back(s.top());
                        s.pop();
                    }
                    // back to stack
                    string t = "";
                    for(int i = digit.size() - 1; i >= 0; --i) {
                        t = t + digit[i];
                    }
                    for(int i = 0; i < stoi(t); ++i) {
                        for(int j = letter.size() - 1; j >= 0; --j) {
                            s.push(letter[j]);
                        }
                    }
                }
            }
        }
        string stack = "";
        while(!s.empty()) {
            stack = stack + s.top();
            s.pop();
        }
        // return the reverse
        string sol = "";
        for(int i = stack.size() - 1; i >= 0; --i) {
            sol += stack[i];
        }
        return sol;
    }
};


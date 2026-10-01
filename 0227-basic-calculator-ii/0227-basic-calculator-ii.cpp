class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    long long prev = st.top(); st.pop();
                    st.push(prev * num);
                } else if (op == '/') {
                    long long prev = st.top(); st.pop();
                    st.push(prev / num);
                }

                op = c;
                num = 0;
            }
        }

        long long result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return (int)result;
    }
};
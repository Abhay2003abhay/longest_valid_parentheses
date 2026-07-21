#include <iostream>
#include <string>
#include <stack>
using namespace std;

int longestvalidparenthesislen(string s) {
    stack<int> st;
    st.push(-1); 
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop(); 
            if (st.empty()) {
                st.push(i); 
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Longest valid parentheses length: " 
         << longestvalidparenthesislen(s) << endl;

    return 0;
}

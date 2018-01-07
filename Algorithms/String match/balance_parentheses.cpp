#include <stack>

using namespace std;

int matching(string &exp) {
    // exp is a pointer to a string to check
    int state = 1, i = 0;
    char e;
    stack<char> s;
    while (i < exp.length() && state) {
        switch (exp[i]) {
            case '(':
                s.push('(');
                i++;
                break;
            case ')':
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                    i++;
                } else
                    state = 0;// an error occurs
                break;
            default:
                i++;
                break;
        }
    }
    if (state && s.empty())
        return 1;
    else return 0;
}
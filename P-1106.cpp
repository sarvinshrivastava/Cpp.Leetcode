class Solution {
public:
    stack <char> st;

    void callAND() {
        st.pop();
        char a;
        bool res = true;

        while (!st.empty() && st.top() != ')') {
            a = st.top(); st.pop();

            if (a == 't')
                res &= true;
            else
                res &= false;
        }

        st.pop();
        if (res == true) {
            st.push('t');
            cout << "true and" << endl;
        }
        else {
            st.push('f');
            cout << "false and" << endl;
        }
    }

    void callOR() {
        st.pop();
        char a;
        bool res = false;

        while (!st.empty() && st.top() != ')') {
            a = st.top(); st.pop();

            if (a == 't')
                res |= true;
            else
                res |= false;
        }

        st.pop();
        if (res == true) {
            st.push('t');
            cout << "true or" << endl;
        }
        else {
            st.push('f');
            cout << "false or" << endl;
        }
    }

    void callNOT() {
        st.pop();
        char a;

        a = st.top(); st.pop();
        st.pop();
        if (a == 't') {
            st.push('f');
            cout << "false not" << endl;
        }
        else {
            st.push('t');
            cout << "true not" << endl;
        }

    }


    bool parseBoolExpr(string ex) {
        for (long i = ex.size() - 1; i >= 0; i--) {
            if (ex[i] == ')' || ex[i] == '(' || ex[i] == 't' || ex[i] == 'f') {
                st.push(ex[i]);
                cout << ex[i] << endl;
            }
            else if (ex[i] == '&') {
                cout << "callAND" << endl;
                callAND();
            }
            else if (ex[i] == '|') {
                cout << "callOR" << endl;
                callOR();
            }
            else if (ex[i] == '!') {
                cout << "callNOT" << endl;
                callNOT();
            }
            else
                continue;
        }

        if (st.top() == 'f')
            return false;
        else
            return true;
    }
};

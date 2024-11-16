bool isValid(char* s) {
    int st[strlen(s)];  // stack  ( 1, { 2, [ 3 
    int idx = 0;

    for (int i=0;i<strlen(s);i++) {
        switch (s[i]){
            case '(':
                st[idx++] = 1;
                break;
            case '{':
                st[idx++] = 2;
                break;
            case '[':
                st[idx++] = 3;
                break;
            case ')':
                if (idx < 1 || st[idx-1] != 1) return false;
                idx--;
                break;
            case '}':
                if (idx < 1 || st[idx-1] != 2) return false;
                idx--;
                break;
            case ']':
                if (idx < 1 || st[idx-1] != 3) return false;
                idx--;
                break;
            default:
                break;
        }
    }

    if (idx == 0) return true;
    return false;

}

/*
The goal of this algorithm is to determine whether the parentheses in a given string follow the correct pairing and nesting rules. To address this issue, I use the stack data structure.

In this approach, the stack is used to keep track of the opening parentheses as they appear in the string. When a closing parenthesis is encountered, the algorithm checks if it maches the top of the stack. If it does, the top element is popped from the stack; otherwise, the string is invalid. This process continues from the beginning of the string to the end. At the end of the traversal, if the stack is empty, the string is valid; otherwise, it is invalid.
*/
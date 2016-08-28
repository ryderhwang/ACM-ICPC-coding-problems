class Solution {
public:
    struct Node {
        Node( int p, Node* n, int d) :  parlen(p), parent(n), depth(d){};
        int parlen;
        Node* parent;
        int depth;
    };
    int lengthLongestPath(string input) {
        int ind = 0;
        Node* longNode = nullptr;
        Node* root = new Node(-1, nullptr, -1);
        stringstream sst;
        bool isFile = false;
        while(input[ind] != '\n' && ind < input.length()) {
            if(input[ind] == '.'){
                isFile = true;
            }
            sst << input[ind++];
        }
        Node* cur;
        cur = new Node(sst.str().length(), root, 0);
        int curdepth = 0;
        int longest = 0;
        if(isFile) {
            longest = cur->parlen;
        }
        
        for (int i = ind; i < input.length(); i++){
            isFile = false;
            char next = input[i];
            assert(input[i++] == '\n');
            int dep = 0;
            
            while(isspace(input[i])) {
                if(dep == curdepth + 1) {
                    break;
                }
                if(input[i] == '\t'){
                    dep++;
                    i++;
                }
                else if(input[i] == ' ' && input[i + 1] == ' ' && input[i + 2] == ' ' && input[i + 3] == ' '){
                    dep++;
                    i += 4;
                }
            }
            stringstream ss;
            while (input[i] != '\n' && i < input.length()) {
                if(input[i] == '.') {
                    isFile = true;
                }
                ss << input[i++];
            }
            string curStr = ss.str();
            Node* n;
            while(dep < curdepth + 1) {
                cur = cur->parent;
                curdepth--;
            }
            
            n = new Node( cur->parlen + curStr.length() + 1, cur, dep);
            
            if(isFile && longest < n->parlen) {
                longest = n->parlen;
                longNode = n;
            }
            cur = n;
            curdepth = dep;
            i--;
        }
        return longest;
    }
};

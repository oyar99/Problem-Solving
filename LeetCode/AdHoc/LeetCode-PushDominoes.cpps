class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        
        vector<int> pos;
        
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                pos.push_back(i);
            }
        }
        
        string finalState;
        
        char lastDominoSeen = 'L';
        
        int j = 0;
        
        for (int i = 0; i < n;) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                lastDominoSeen = dominoes[i];
                finalState += lastDominoSeen;
                ++j;
                ++i;
                continue;
            }
            
            if (lastDominoSeen == 'R') {
                
                if (j >= pos.size()) {
                    while (i < n) {
                        finalState += 'R';
                        ++i;
                    }
                    break;
                }
                
                char nextDomino = dominoes[pos[j]];
                
                if (nextDomino == 'R') {
                    
                    while (i < pos[j]) {
                        finalState += 'R';
                        ++i;
                    }
                } else {
                    
                    int len = pos[j] - i;
                    
                    int k = 0;
                    while (k < (len / 2)) {
                        finalState += 'R';
                        ++k;
                        ++i;
                    }

                    if (len & 1) {
                        finalState += '.';
                        ++i;
                    }
                    
                    while (i < pos[j]) {
                        finalState += 'L';
                        ++i;
                    }
                }
            } else {
                
                if (j >= pos.size()) {
                    while (i < n) {
                        finalState += '.';
                        ++i;
                    }
                    break;
                }
                
                char nextDomino = dominoes[pos[j]];
                
                if (nextDomino == 'L') {
                    
                    while (i < pos[j]) {
                        finalState += 'L';
                        ++i;
                    }
                } else {
                    while (i < pos[j]) {
                        finalState += '.';
                        ++i;
                    }
                }
            }
        }
        
        return finalState;
    }
};

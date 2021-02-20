#define v vector<int>&
struct Solution{
    int countStudents(v S,v W){
        int a=0,b=0,n=W.size();
        for(int s:S)!s?++a:++b;
        for(int i=0;i<n;++i){
            if(!W[i]&&a--);
            else if(!W[i])return n-i;
            if(W[i]&&b--);
            else if(W[i])return n-i;
        }
        return 0;
    }
};

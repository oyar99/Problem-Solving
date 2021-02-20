#define v vector<int>&
#define r return
struct Solution{int countStudents(v S,v W){int a=0,b=0,n=W.size();for(int s:S)!s?++a:++b;int i=0;for(int w:W){if(!w&&a--);else if(!w)r n-i;if(w&&b--);else if(w)r n-i;++i;}r 0;}};

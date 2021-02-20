struct Solution{string generateTheString(int n){string s;if(~n&1)for(;n;--n)n-1?s+='a':s+='b';else for(;n;--n)s+='a';return s;}};

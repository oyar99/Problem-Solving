struct Solution{int canBeTypedWords(string&t,string&b){int a=0;vector<bool>d(26);bool p=1;for(char&i:b)d[i-'a']=1;for(char&c:t+' ')a+=p&&c==' ',p=(p||c==' ')&&(c==' '||!d[c-'a']);return a;}};

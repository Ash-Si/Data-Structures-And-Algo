#include <bits/stdc++.h>
using namespace std;

void reversestr(string &s, int i){
    reverse(s.begin(),s.begin()+i);
    reverse(s.begin()+i,s.end());
    reverse(s.begin(),s.end());
}

bool rotateString(string s, string goal) {
    for(int i=1;i<=s.size();i++){
        reversestr(s,1);
        if(s==goal) return true;
    }
    return false;
}

bool rotateString2(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    s.append(s);
    if(s.find(goal)!=string::npos) return true;
    return false;
}

int main() {
    cout << rotateString("abcde","decab") ;  
    return 0;
}
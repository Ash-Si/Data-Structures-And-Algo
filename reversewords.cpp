#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string result="";
    int left=0;
    int right=s.size()-1;
    string temp;
    while(left<=right){
        char ch;
        ch=s[left];
        if(ch!=' '){
            temp+=ch;
        }else{
            if(result!="")
                result=temp+" "+result;
            else 
                result=temp;
            temp="";
        }
        left++;
    }
    if(right!=' ')
        result=temp+" "+result;
    
    left=0;
    while(result[left]==' ')
        left++;
    result.erase(result.begin(),result.begin()+left);
    return result;
    }

string reverseWords2(string s) {
    reverse(s.begin(), s.end());
    string result=s;
    int n = result.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n) {
        while (i < n && result[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && result[i] != ' ') {
            result[right++] = result[i++];
        }
        reverse(result.begin() + left, result.begin() + right);
        result[right++] = ' ';
        left = right;
        i++;
    }
    result.resize(right - 1);
    return result;
    }

int main() {
    string s = "the      sky";
    cout << reverseWords2(s) ;  
    return 0;
}
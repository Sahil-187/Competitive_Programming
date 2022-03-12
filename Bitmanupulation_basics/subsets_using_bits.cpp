#include <iostream>
using namespace std;

void generatesubsets(string &s) {
    int l = s.length();
    for(int i = 0; i < (1<<l); ++i) {
          int j = i; 
          int it = 0;
          while(j) {
              if(j&1) cout<<s[it];
              it++;
              j>>=1;
          }
          cout<<endl;
}
}

int main() {
    string s = "abcd";
    generatesubsets(s);
    return 0;
}
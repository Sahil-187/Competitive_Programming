#include <iostream>
using namespace std;

int count_bits(int n) {
   int cnt = 0; 
   while(n) ++cnt, n = n&(n-1); // remove last set bit from number
   return cnt;
}
int main() {
    int n = 5;
    cout<<count_bits(n)<<endl;
    return 0;
}
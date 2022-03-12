#include <iostream>
#include <vector>
const int mod = 1000000007;
using namespace std;
struct matrix{
    int sz;
    vector< vector<long long> > p;
    matrix(int x) {
         sz = x;
         p.resize(sz);
         for(auto &itr : p) itr.resize(sz);
    }
    void make_iden(){
        make_zero();
        for(int i = 0; i < sz; ++i) p[i][i] = 1;
    }
    void make_zero(){
        for(int i = 0; i < sz; ++i) for(int j = 0; j < sz; ++j) p[i][j] = 0;
    }
    void pprint(){
        for(auto &itr : p) {for(auto &it : itr) cout<<it<< " "; cout<<endl;}
    }
};
    matrix operator* (matrix &a,matrix &b) {
        matrix ans(a.sz);
         for(int i = 0; i < a.sz; ++i) {
             for(int j = 0; j < a.sz; ++j) {
                long long sum = 0;
                 for(int k = 0; k < a.sz; ++k) {
                     sum+=((a.p[i][k]%mod)*(b.p[k][j]%mod)); 
                     sum%=mod;
                 }
                 ans.p[i][j] = sum;
             }
         }
         return ans;
    }
/*int fib_fast(long long n,long long a,long long b,long long c, long long d,long long e){
    matrix ans(size);
    matrix t(size);
    t.make_zero();
    ans.make_iden();
    --n;
    while (n)
    {
        if(n&1) ans = ans*t;
        t = t * t;
        n/=2;
    }
    return ...
} */
int main() {
    return 0;
}
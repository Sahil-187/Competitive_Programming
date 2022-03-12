/*
    Created by Sahil
    Every passing minute is another chance to turn it all around
*/

#include <bits/stdc++.h>

using namespace std;

#define ll             long long int

const int mod = 1000000007;
struct matrix{
    int sz;
    ll **p;
    matrix(int x) {
         sz = x;
          p = new ll*[sz];
         for(int i = 0; i < sz; ++i) {
             p[i] = new ll[sz];
         }
    }
    void make_iden(){
        make_zero();
        for(int i = 0; i < sz; ++i) p[i][i] = 1;
    }
    void make_zero(){
        for(int i = 0; i < sz; ++i) for(int j = 0; j < sz; ++j) p[i][j] = 0;
    }
};
    matrix operator* (matrix &a,matrix &b) {
        matrix ans(a.sz);
        ans.make_zero();
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
int fib_fast(long long n,long long a,long long b,long long c, long long d,long long e){
    matrix ans(5);
    matrix t(5);
    t.make_zero();
    t.p[0][0] = a;
    t.p[0][1] = b;
    t.p[0][2] = c;
    t.p[0][3] = (c+c+d)%mod;
    t.p[0][4] = (c+d+e)%mod;
    t.p[1][0] = 1;
    t.p[2][2] = 1;
    t.p[2][3] = 2;
    t.p[2][4] = 1;
    t.p[3][3] = 1;
    t.p[3][4] = 1;
    t.p[4][4] = 1;
    ans.make_iden();
    --n;
    while (n)
    {
        if(n&1) ans = ans*t;
        t = t * t;
        n/=2;
    }
    long long res = (ans.p[0][0]*3)%mod + (ans.p[0][1]*2)%mod + (ans.p[0][4])%mod+(ans.p[0][2])%mod+(ans.p[0][3])%mod;
    int ab =  (res%mod);
    return ab;
}

long long  n,a,b,c,d,e;
void tc(){
   cin >> n;
   cin >> a >> b >> c >> d >> e;
   if(n<2){
       if (n==0) return void(cout<<2<<endl);
       if(n==1) return void(cout<<3<<endl);
   }
   long long ans= 0;
   ans =  fib_fast(n,a,b,c,d,e);
   cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t z = clock();
    tc();
    return 0;
}
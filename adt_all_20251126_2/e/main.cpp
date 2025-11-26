#if __has_include(<yoniha/all.h>)
#include <yoniha/all.h>
using namespace atcoder;
#else
#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#endif
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)((n) - 1); i >= 0; i--)
template <typename T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template <typename T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

// using mint = modint;

signed main(){
  int n, k; cin >> n >> k;
  int sum = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  while(n--){
    int a, b; cin >> a >> b;
    q.emplace(a, b);
    sum += b;
  }
  if(sum <= k){
    println("{}", 1);
    return 0;
  }
  while(true){
    auto [a, b] = q.top(); q.pop();
    sum -= b;
    if(sum <= k){
      println("{}", a + 1);
      return 0;
    }
  }
}

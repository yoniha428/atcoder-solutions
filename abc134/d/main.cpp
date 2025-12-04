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
  int n; cin >> n;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector<int> box(n, 0), ans;
  rrep(i, n){
    // i+1の倍数-1がindex
    int sum = 0;
    for(int j = i; j < n; j += i + 1) sum += box.at(j);
    if(sum % 2 != a.at(i)){
      box.at(i) = 1;
      ans.emplace_back(i);
    }
  }
  cout << ans.size() << '\n';
  for(auto i : ans) cout << i + 1 << ' ';
  cout << '\n';
}
/*
調和級数はo(N^2)ですと言われていそう
逆順に決めれば良さそう
*/

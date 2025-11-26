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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  sort(all(a));
  // priority_queue<int, vector<int>, greater<>> q;
  set<int> q, ans;
  q.emplace(0);
  while(ans.size() < k){
    auto top = *q.begin(); q.erase(top);
    for(auto& ai : a) q.emplace(top + ai);
    if(top != 0) ans.emplace(top);
  }
  cout << *ans.rbegin() << '\n';
}

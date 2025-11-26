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
  int n, m; cin >> n >> m;
  vector<bool> checked(m, false);
  priority_queue<tuple<int, bool, int>, vector<tuple<int, bool, int>>, greater<>> q;
  rep(i, m){
    int a, b; cin >> a >> b; a--; b--;
    q.emplace(a, true, i);
    q.emplace(b, false, i);
  }
  int ans = 0;
  vector<int> seen;
  while(!q.empty()){
    auto [t, f, i] = q.top(); q.pop();
    if(f){
      seen.emplace_back(i);
    }
    else{
      if(checked.at(i)) continue;
      for(auto j : seen) checked.at(j) = true;
      seen.clear();
      ans++;
    }
  }
  cout << ans << '\n';
}

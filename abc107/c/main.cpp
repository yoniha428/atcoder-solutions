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
  vector<int> x(n); for(auto&& xi : x) cin >> xi;
  deque<int> q;
  rep(i, k) q.emplace_back(x.at(i));
  int ans = q.back() - q.front() + min(abs(q.front()), abs(q.back()));
  for(int i = k; i < n; i++){
    q.emplace_back(x.at(i));
    q.pop_front();
    chmin(ans, q.back() - q.front() + min(abs(q.front()), abs(q.back())));
  }
  cout << ans << '\n';
}

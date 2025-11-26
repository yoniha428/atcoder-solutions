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
  string s; cin >> s;
  vector<string> ans;
  int cnt_max = 0;
  rep(i, n - k + 1){
    string t = s.substr(i, k);
    int cnt = 0;
    rep(j, n) cnt += s.substr(j, k) == t;
    if(cnt > cnt_max){
      cnt_max = cnt;
      ans.clear();
      ans.emplace_back(t);
    }
    else if(cnt == cnt_max){
      ans.emplace_back(t);
    }
  }
  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());
  cout << cnt_max << '\n';
  for(auto& i : ans) cout << i << '\n';
}

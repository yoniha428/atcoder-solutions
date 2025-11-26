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
  vector<set<int>> st(m);
  vector<vector<int>> vec(n);
  rep(i, m){
    int k; cin >> k;
    while(k--){
      int a; cin >> a; a--;
      st.at(i).emplace(a);
      vec.at(a).emplace_back(i);
    }
  }
  int ans = 0;
  while(n--){
    int b; cin >> b; b--;
    for(auto&& i : vec.at(b)){
      st.at(i).erase(b);
      ans += st.at(i).empty();
    }
    cout << ans << '\n';
  }
}

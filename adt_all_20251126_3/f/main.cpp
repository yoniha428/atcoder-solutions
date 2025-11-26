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
  int h, w; cin >> h >> w;
  vector a(h, vector<int>(w));
  for(auto&& ai : a) for(auto&& aij : ai) cin >> aij;
  vector<bool> per(h + w - 2, false);
  rep(i, h - 1) per.at(h + w - 3 - i) = true;
  int ans = 0;
  do{
    int i = 0, j = 0;
    set<int> st{a.at(0).at(0)};
    for(auto pi : per){
      (pi ? i : j)++;
      st.emplace(a.at(i).at(j));
    }
    ans += st.size() == h + w - 1;
  }while(next_permutation(all(per)));
  println("{}", ans);
}

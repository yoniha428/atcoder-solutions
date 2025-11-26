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
  auto sier = [](auto sier, int k) -> vector<string>{
    if(k == 0) return {"#"};
    int size = 1; rep(i, k) size *= 3;
    auto small = sier(sier, k - 1);
    vector ret(size, string(size, '.'));
    rep(i, size) rep(j, size){
      if(i >= size / 3 && i < size * 2 / 3 && j >= size / 3 && j < size * 2 / 3) continue;
      ret.at(i).at(j) = small.at(i % (size / 3)).at(j % (size / 3));
    }
    return ret;
  };
  auto ans = sier(sier, n);
  for(auto si : ans) cout << si << '\n';
}

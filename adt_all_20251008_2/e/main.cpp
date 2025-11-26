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
  vector<int> a(n); for(auto&& ai : a) cin >> ai, ai--;
  sort(all(a));
  int ok = 0, ng = n + 1;
  while(ng - ok > 1){
    int mid = (ok + ng) / 2;
    // [0, mid)がすべて揃えられる
    vector<bool> have(mid, false);
    int cnt = 0;
    for(auto ai : a){
      if(ai < mid && !have.at(ai)) have.at(ai) = true;
      else cnt++;
    }
    int have_cnt = reduce(all(have), 0ll);
    (have_cnt + cnt / 2 >= mid ? ok : ng) = mid;
  }
  println("{}", ok);
}

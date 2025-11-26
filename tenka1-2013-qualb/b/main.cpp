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
  int q, l; cin >> q >> l;
  deque<pair<int, int>> que;
  int size = 0;
  while(q--){
    string op; cin >> op;
    if(op == "Push"){
      int n, m; cin >> n >> m;
      if(size > l - n){
        cout << "FULL" << '\n';
        return 0;
      }
      que.emplace_back(m, n);
      size += n;
    }
    if(op == "Pop"){
      int n; cin >> n;
      if(size < n){
        cout << "EMPTY" << '\n';
        return 0;
      }
      size -= n;
      while(n > 0){
        auto&& [val, cnt] = que.back();
        int pop = min(cnt, n);
        cnt -= pop;
        n -= pop;
        if(cnt == 0) que.pop_back();
      }
    }
    if(op == "Top"){
      if(size == 0){
        cout << "EMPTY" << '\n';
        return 0;
      }
      auto&& [val, cnt] = que.back();
      cout << val << '\n';
    }
    if(op == "Size"){
      cout << size << '\n';
    }
  }
  cout << "SAFE" << '\n';
}

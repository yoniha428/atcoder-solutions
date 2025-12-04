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
  int q; cin >> q;
  vector<pair<string, int>> query(q);
  for(auto&& [op, x] : query){
    cin >> op;
    if(op == "DELETE") x = -1;
    else cin >> x;
  }
  vector g(1, vector<int>());
  int now = 0;
  for(auto&& [op, x] : query){
    ;
  }
}
/*
クエリ先読みすれば永続データ構造が要らなそう
各操作で、新しい頂点を追加していく
SAVEは、zは今の頂点を指すんだよということ

*/

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
  vector<string> s(3); for(auto&& si : s) cin >> si;
  int q; cin >> q;


  while(q--){}
}
/*
#になるときと.になるときを分けて考える

#になるときは、縦に見て他の.の左右の距離から答えを出し、#へはinfとする
.になるときは、min(今の答え、)

ある頂点への距離が更新されたときに、それを左右に流していないのが問題そう
*/
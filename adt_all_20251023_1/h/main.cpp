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
  vector<int> c(9); for(auto&& ci : c) cin >> ci;
  int min_c = 1ll << 60, idx = -1;
  rep(i, 9) if(c.at(i) <= min_c){
    min_c = c.at(i);
    idx = i;
  }
  string ans(n / min_c, idx + '1');
  int left = n % min_c;
  rep(i, ans.size()){
    rep(j, 9) if(left + c.at(ans.at(i) - '1') - c.at(j) >= 0 && ans.at(i) < char(j + '1')){
      left += c.at(ans.at(i) - '1') - c.at(j);
      ans.at(i) = j + '1';
    }
  }
  cout << ans << '\n';
}
/*
回数を減らして得をすることはない
最大回数10倍にしたあとに、前から貪欲に買えるうち最も高い奴に変更していく

10^nくらいまでいくので、うまいことしなければいけない
*/


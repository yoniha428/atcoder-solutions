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
  int n, w; cin >> n >> w;
  vector<int> imos(200001, 0);
  while(n--){
    int s, t, p; cin >> s >> t >> p;
    imos.at(s) += p;
    imos.at(t) -= p;
  }
  int now = 0;
  for(auto i : imos){
    now += i;
    if(now > w){
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}

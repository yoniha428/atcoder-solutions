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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)((n) - 1); i >= 0; i--)
template <typename T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template <typename T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

// using mint = modint;

template <class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

signed main(){
  int n; cin >> n;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;

  int ans = 0;
  ordered_set<pair<int, int>> st;
  rep(i, n){
    ans += st.order_of_key({a.at(i), -1}) * a.at(i);
    st.insert({a.at(i), i});
  }
  st.clear();
  rrep(i, n){
    ans -= (st.size() - st.order_of_key({a.at(i), n})) * a.at(i);
    st.insert({a.at(i), i});
  }
  cout << ans << '\n';
}
/*
a.at(i)はどれだけ答えに寄与するか
左にある自分より小さい要素だけプラス
右にある自分より大きい要素だけマイナス
*/

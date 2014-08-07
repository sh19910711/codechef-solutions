#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <limits>
#include <tuple>
using namespace std;

typedef long long Int;

const Int N_MAX = 200 + 11;
const Int M_MAX = 400 + 11;
const Int C_MAX = 400 + 11;
const Int MEMO_NONE = -1;

Int N;
Int M;
Int C[M_MAX];

void input() {
  cin >> N >> M;
  for ( int i = 0; i < M; ++ i ) {
    cin >> C[i];
  }
  for ( int i = 0; i < M; ++ i ) C[i] --;
}

Int orders[C_MAX][M_MAX]; // orders[c_id][i] := c_id's i-th order pos in C
Int order_num[C_MAX];
Int pos_to_order[C_MAX][M_MAX];
bool keeped[M_MAX];
Int memo[M_MAX][M_MAX];

void init() {
  for ( int i = 0; i < M_MAX; ++ i ) {
    fill(memo[i], memo[i] + M_MAX, MEMO_NONE);
  }
  fill(order_num, order_num + C_MAX, 0);
  fill(keeped, keeped + M_MAX, false);
}

Int rec( const Int& l, const Int& r ) {
  auto& res = memo[l][r];
  if ( res != MEMO_NONE ) return res;
  res = 0;
  bool flag = false;
  for ( Int i = l + 1; i < r; ++ i ) {
    const auto& c_id = C[i];
    const auto& order_ind = pos_to_order[c_id][i];
    if ( order_ind + 1 < order_num[c_id] ) {
      flag = true;
      const auto& ret = rec(i, min(r, orders[c_id][order_ind + 1]));
      res += ret;
    }
  }
  if ( ! flag ) return 1;
  return res;
}

Int solve() {
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    orders[c_id][order_num[c_id]] = i;
    pos_to_order[c_id][i] = order_num[c_id];
    order_num[c_id] ++;
  }
  Int res = 0;
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    const auto& order_ind = pos_to_order[c_id][i];
    if ( order_ind + 1 < order_num[c_id] ) {
      const auto& next_order_pos = orders[c_id][order_ind + 1];
      const auto& ret = rec(i, next_order_pos);
      if ( ret < N ) {
        if ( ! keeped[i] ) res ++;
        keeped[next_order_pos] = true;
        continue;
      }
    }
    if ( ! keeped[i] ) res ++;
  }
  return res;
}

int main() {
  int tests;
  cin >> tests;
  for ( int i = 0; i < tests; ++ i ) {
    init();
    input();
    cout << solve() << endl;
  }
  return 0;
}

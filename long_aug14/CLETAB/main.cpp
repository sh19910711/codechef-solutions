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
const Int INF = numeric_limits<Int>::max();

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

typedef tuple <Int, Int, Int> Node; // rem, next_order, c_id
const Int NODE_C_ID = 2;
typedef set <Node, less<Node>> NodeSet;

Int R[C_MAX]; // rem
Int O[C_MAX][M_MAX];
Int OC[C_MAX];
Int OI[C_MAX];
bool D[C_MAX]; // using
NodeSet S;

void init() {
  fill(R, R + C_MAX, 0);
  fill(OC, OC + C_MAX, 0);
  fill(OI, OI + C_MAX, 0);
  fill(D, D + C_MAX, false);
  S = NodeSet();
}

Node get_node( const Int& a, const Int& b, const Int& c ) {
  return Node(a, b, c);
}

Int solve() {
  Int res = 0;
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    R[c_id] ++;
    O[c_id][OC[c_id] ++] = i;
  }
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    auto& rem = R[c_id];
    const auto& orders = O[c_id];
    auto& order_index = OI[c_id];
    const auto& order_num = OC[c_id];

    if ( D[c_id] ) {
      S.erase(get_node(rem, orders[order_index - 1], c_id));
      rem --;
      S.insert(get_node(rem, orders[order_index ++], c_id));
      continue;
    }

    if ( S.size() >= N ) {
      const auto& rm = *S.begin();
      const auto& rm_c_id = get<NODE_C_ID>(rm);
      D[rm_c_id] = false;
      S.erase(rm);
    }

    rem --;
    if ( order_index + 1 >= order_num ) {
      S.insert(get_node(rem, M_MAX, c_id));
    } else {
      S.insert(get_node(rem, orders[order_index ++], c_id));
    }
    D[c_id] = true;
    res ++;
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

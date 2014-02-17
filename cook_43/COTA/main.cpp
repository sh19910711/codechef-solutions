
// @snippet<sh19910711/contest-base-simple:header.cpp>
#define __THIS_IS_CPP11__
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdio>
#include <cmath>

#ifdef __THIS_IS_CPP11__
#include <memory>
#include <array>
#endif

// @snippet<sh19910711/contest-base-simple:solution/template-typedef.cpp>
namespace solution {
  typedef long long Int;
  typedef long double Double;
  typedef std::string String;
}

// @snippet<sh19910711/contest-base-simple:solution/template-constants.cpp>
namespace solution {
  const Int MAX_N = 18 * 2 + 1;
  const Int MAX_BIT = ( 1 << 18 ) + 11;
  const Int MAX_M = 2 * MAX_N * ( 2 * MAX_N - 1 ) / 2;
  const Int INF = std::numeric_limits<Int>::max() / 3;
  const Int MEMO_NONE = -1;
  typedef std::array<Int, MAX_M> IntArray;
}

// @snippet<sh19910711/contest-base-simple:solution/template-storages.cpp>
namespace solution {
  struct Input {
    Int N;
    Int M;
    IntArray U;
    IntArray V;
    IntArray P;
  };
  struct Output {
    Int result;
  };
}

// @snippet<sh19910711/contest-base-simple:solution/solution-multi-tests.cpp>
namespace solution {
  struct Solution {
    //
    // Implement here
    //
    
    typedef std::array<std::array<Int, MAX_N>, MAX_N> AdjacentMatrix;
    typedef std::array<std::array<Int, MAX_BIT>, 2> Memo;

    Int N;
    AdjacentMatrix G;
    Memo memo;
    
    void solve() {
      N = in->N * 2;
      init_graph();
      generate_graph();
      find_dist();
      init_memo();

      Int ret1 = rec(0, 0);
      Int ret2 = rec(0, 1);
      out->result = std::min(ret1, ret2);
    }

    void init_memo() {
      for ( auto i = 0; i < 2; ++ i ) {
        for ( auto j = 0; j < MAX_BIT; ++ j ) {
          memo[i][j] = MEMO_NONE;
        }
      }
    }

    Int rec( const Int& s, const Int& offset ) {
      Int& res = memo[offset][s];

      if ( res != MEMO_NONE )
        return res;

      if ( s == ( Int(1) << ( N / 2 ) ) - 1 )
        return res = 0;

      res = INF;
      for ( Int i = 0; i * 2 + offset < N; ++ i ) {
        Int bi = Int(1) << i;
        if ( s & bi )
          continue;
        for ( Int j = i + 1; j * 2 + offset < N; ++ j ) {
          Int bj = Int(1) << j;
          if ( s & bj )
            continue;
          Int ret = rec(s | bi | bj, offset);
          res = std::min(res, ret + G[i * 2 + offset][j * 2 + offset]);
        }
        break;
      }
      return res;
    }

    void find_dist() {
      for ( auto k = 0; k < N; ++ k ) {
        for ( auto i = 0; i < N; ++ i ) {
          for ( auto j = 0; j < N; ++ j ) {
            G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
          }
        }
      }
    }

    void generate_graph() {
      for ( auto i = 0; i < in->M; ++ i ) {
        auto u = in->U[i];
        auto v = in->V[i];
        auto p = in->P[i];
        G[u][v] = G[v][u] = p;
      }
    }

    void init_graph() {
      for ( auto i = 0; i < MAX_N; ++ i ) {
        for ( auto j = 0; j < MAX_N; ++ j ) {
          G[i][j] = INF;
        }
      }
    }
    
    bool input() {
      if ( ! ( std::cin >> in->N >> in->M ) )
        return false;
      for ( auto i = 0; i < in->M; ++ i )
        if ( ! ( std::cin >> in->U[i] >> in->V[i] >> in->P[i] ) )
          return false;
      return true;
    }
    
    void output() {
      std::cout << out->result << std::endl;
    }
    
    //
    //
    //
    Solution( Input* in, Output* out ): in(in), out(out) {
      // pre calc
    }
    
    int run() {
      int tests = 0;
      std::cin >> tests;
      for ( int i = 0; i < tests; ++ i ) {
        this->before_action(i);
        this->action();
        this->after_action(i);
      }
      return 0;
    }
    
    bool action() {
      if ( ! this->input() ) {
        return false;
      }
      this->solve();
      this->output();
      return true;
    }
    
    void before_action( const int& t_id ) {}
    
    void after_action( const int& t_id ) {}
    
    Input* in;
    Output* out;
  };
}

// @snippet<sh19910711/contest-base-simple:main_func.cpp>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  using namespace solution;
  static Input in;
  static Output out;
  static Solution sol(&in, &out);
  return sol.run();
}

// @snippet<sh19910711/contest-base-simple:main.cpp>



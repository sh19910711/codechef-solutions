// @snippet <contest-base-simple#0.0.5:header.cpp>
/* default headers {{{ */
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
#include <cassert>

#if __cplusplus >= 201103L
#include <memory>
#include <array>
#endif
/* }}} */
// @snippet <contest-base-simple#0.0.5:solution/template-typedef.cpp>
namespace solution {

  using namespace std;

  /* primitives {{{ */
  typedef long long Int;
  typedef long double Double;
  /* }}} */

}
// @snippet <contest-base-simple#0.0.5:solution/template-constants.cpp>
namespace solution {
  // const Int N = 1000000 + 11;

}
// @snippet <contest-base-simple#0.0.5:solution/template-storages.cpp>
namespace solution {

  struct Input {
    Int N;
    Int D;
  };

  struct Output {
    Int res;
  };

}
// @snippet <contest-base-simple#0.0.5:solution/solution-io.cpp>
namespace solution {

  struct SolutionIO {

    Input in;
    Output out;

    template <class Stream> bool input( Stream& s ) {
      if ( s >> in.N >> in.D ) {
        return true;
      }
      return false;
    }

    template <class Stream> bool output( Stream& s ) {
      return s << out.res << endl;
    }

  };

}
// @snippet <contest-base-simple#0.0.5:solution/solution.cpp>
namespace solution {

  struct Solution: SolutionIO {

    Solution() {}

    const Int INF = numeric_limits<Int>::max();
    typedef vector<Int> IntVector;
    typedef vector<Int> Points;
    typedef vector<Points> Layer;

    Int N;
    Int D;
    IntVector M;

    bool solve() {
      this->N = in.N;
      this->D = in.D;
      out.res = find_min();
      return true;
    }

    Int to_hash( const IntVector& p ) {
      Int res = 0;
      Int base = 1;
      for ( auto it = p.begin(); it != p.end(); it ++ ) {
        res += (*it) * base;
        base *= D;
      }
      return res;
    }

    Int find_min() {
      M = IntVector(1 << 17, INF);
      IntVector s(N, D - 1);
      return rec(s);
    }

    Int xor_sum( const IntVector& v ) {
      Int res = 0;
      for ( auto& x : v ) {
        res ^= x;
      }
      return res;
    }

    Int add_sum( const IntVector& v ) {
      Int res = 0;
      for ( auto& x : v ) {
        res += x;
      }
      return res;
    }

    Int calc_cost( const IntVector& v ) {
      return xor_sum(v) * add_sum(v);
    }

    Int rec(IntVector& pos) {
      const Int& hash = to_hash(pos);
      Int& memo = M[hash];
      if ( memo != INF ) return memo;
      if ( hash == 0 ) {
        memo = 0;
        return 0;
      }

      memo = calc_cost(pos);
      Int best = INF;
      for ( auto& p : pos ) {
        p --;
        if ( p >= 0 ) {
          best = min(best, rec(pos));
        }
        p ++;
      }
      memo += best;
      return memo;
    }

    /* action methods {{{ */
    void before_action( const int& t_id ) {}

    void after_action( const int& t_id ) {}

    bool action( const int& t_id = -1 ) {
      before_action(t_id);
      bool res = input(std::cin) && solve() && output(std::cout);
      after_action(t_id);
      return res;
    }
    /* }}} */
  };

}
// @snippet <contest-base-simple#0.0.5:solution/runner-normal.cpp>
/* Runner Class {{{ */
namespace solution {

  struct Runner {
    static int run() {
      int q;
      if ( cin >> q ) {
        for ( int i = 0; i < q; ++ i ) {
          Solution* sol = new Solution;
          sol->action();
          delete sol;
        }
      }
      return 0;
    }
  };

}
/* }}} */
// @snippet <contest-base-simple#0.0.5:main_func.cpp>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  return solution::Runner::run();
}
// @snippet <contest-base-simple#0.0.5:main.cpp>


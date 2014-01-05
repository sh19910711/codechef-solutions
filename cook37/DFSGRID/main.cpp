
// @snippet<sh19910711/contest:headers.cpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

// @snippet<sh19910711/contest:solution/interface.cpp>
namespace solution {
  class SolutionInterface {
  public:
    virtual int run() = 0;
    
  protected:
    SolutionInterface() {}
    virtual void pre_calc() {}
    virtual bool action() = 0;
    virtual void init() {};
    virtual bool input() { return false; };
    virtual void output() const {};
  };
}

// @snippet<sh19910711/contest:solution/solution-base-multi-tests.cpp>
namespace solution {
  class SolutionBase: public SolutionInterface {
  public:
    virtual int run() {
      int tests = 0;
      std::cin >> tests;
      for ( int i = 0; i < tests; ++ i ) {
        this->action();
      }
      return 0;
    }
    
  };
}

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
  typedef std::istringstream ISS;
  typedef std::ostringstream OSS;
  typedef long long Int;
  typedef long double Double;
  typedef std::string String;
  
}

// @snippet<sh19910711/contest:solution/namespace-area.cpp>
namespace solution {
  // namespaces, types
  using namespace std;
  
}

// @snippet<sh19910711/contest:solution/consts-area.cpp>
namespace solution {
  // constant vars
  
  
}

// @snippet<sh19910711/contest:solution/storages-area.cpp>
namespace solution {
  // storages
  Int R, C;
  Int SR, SC;
  Int TR, TC;
  
  Int result;
}

// @snippet<sh19910711/contest:solution/solver-area.cpp>
namespace solution {
  class Solver {
  public:
    void solve() {
      result = calc_visited_cells(R, C, SR, SC, TR, TC);
    }

    void print(int h, int w, int sr, int sc, int tr, int tc) {
      cout << h << ", " << w << ", s = " << sr << ", " << sc << " / t = " << tr << ", " << tc << endl;
    }

    Int calc_visited_cells( const Int& H, const Int& W, const Int& sr, const Int& sc, const Int& tr, const Int& tc ) {
      if ( sr == tr && sc == tc )
        return 1;
      
      if ( sr == tr ) {
        if ( sc <= tc ) {
          return abs(sc - tc) + 1;
        } else { // sc > tc
          if ( sr == H ) {
            if ( H >= 2 && sc < W ) {
              return ( H - sr ) * W + W - tc + 1 + W - sr;
            } else {
              return ( H - sr ) * W + W - tc + 1;
            }
          } else {
            return ( H - sr - 1 ) * W + W + tc + ( W - sc + 1 );
          }
        }
      }

      if ( W == 1 ) {
        if ( sr <= tr ) {
          return tr - sr + 1;
        } else {
          return H - tr + 1;
        }
      }

      if ( tc == W ) {
        if ( sr <= tr ) {
          return W - sc + tr - sr + 1;
        }
      }

      if ( sr > tr ) {
        if ( ( H - sr ) % 2 == 1 ) {
          if ( sc <= tc ) {
            return ( H - sr + 1 ) * W + tc - sc + 2;
          } else {
            return ( H - sr + 1 ) * W + W + ( tr - 1 >= 1 ? W : 0 );
          }
        } else {
          if ( sr == H ) {
            if ( tr == H - 1 && sc <= tc ) {
              if ( W == 2 && sc == W ) {
                return 1 + 1 + 2;
              }
              if ( sc == 1 ) {
                return W + W - tc + 1;
              } else {
                return W + tc;
              }
            }
          }
          if ( sr == H ) {
            if ( sr - tr == 2 ) {
              if ( sc == W ) {
                return ( H - tr ) * W + W - tc + 1;
              } else {
                return ( H - tr ) * W + tc;
              }
            } else if ( sr - tr >= 3 ) {
              if ( sc == W ) {
                if ( ( H - tr ) % 2 == 0 ) {
                  return ( H - tr ) * W + W - tc + 1;
                } else {
                  return ( H - tr ) * W + tc;
                }
              } else if ( sc == 1 ) {
                if ( ( H - tr ) % 2 == 0 ) {
                  return ( H - tr ) * W + tc;
                } else {
                  return ( H - tr ) * W + W - tc + 1;
                }
              } else {
                if ( ( H - tr ) % 2 == 0 ) {
                  return ( H - tr ) * W + tc;
                } else {
                  return ( H - tr ) * W + W - tc + 1;
                }
              }
            }
          }
          return ( H - sr + 1 ) * W + tc;
        }
      }

      if ( tr == H ) {
        return W - sc + H - sr + 1 + W - tc;
      }

      if ( sr < tr ) {
        if ( ( H - tr ) % 2 == 0 ) {
          return ( H - tr ) * W + W - sc + 1 + tr - sr + W - tc;
        } else {
          return ( H - tr ) * W + W - sc + 1 + tr - sr + tc;
        }
      }

      return -200;
    }

  protected:
    
  };
}

// @snippet<sh19910711/contest:solution/solution.cpp>
namespace solution {
  class Solution: public SolutionBase {
  public:
  protected:
    virtual bool action() {
      this->init();
      if ( ! this->input() )
        return false;
      solver.solve();
      this->output();
      return true;
    }
    
    bool input() {
      return std::cin >> R >> C >> SR >> SC >> TR >> TC;
    }
    
    void output() {
      std::cout << result << std::endl;
    }
    
    Solver solver;
  };
}

// @snippet<sh19910711/contest:main.cpp>
#ifndef __MY_UNIT_TEST__
int main() {
  std::cin.sync_with_stdio(false);
  return solution::Solution().run();
}
#endif



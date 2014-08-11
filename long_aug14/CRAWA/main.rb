YES = "YES"
NO = "NO"

def f(x, y)
  lb = 0
  ub = 10**10
  100.times do
    mid = ( lb + ub ) / 2
    if 2 * mid < [x.abs, y.abs].max
      lb = mid
    else
      ub = mid
    end
  end
  return lb
end

def h(x, y, sx, sy, tx, ty)
  # puts "h: #{x}, #{y}, #{sx}, #{sy}, #{tx}, #{ty}"
  if ( x == sx || x == tx )
    return true if ( [sy, ty].min <= y && y <= [sy, ty].max )
  end
  if ( y == sy || y == ty )
    return true if ( [sx, tx].min <= x && x <= [sx, tx].max )
  end
  return false
end

def g(k, tx, ty)
  # puts "g: k = #{k}, t: (#{tx}, #{ty})"
  x = -2 * k
  y = -2 * k
  d = k * 4 + 1
  dx = [1, 0, -1, 0]
  dy = [0, 1, 0, -1]
  12.times do |t|
    nx = x + d * dx[t % 4]
    ny = y + d * dy[t % 4]
    # puts "g: #{k * 4 + t + 1}: (#{x}, #{y}) => (#{nx}, #{ny}), t(#{tx}, #{ty}), #{h(tx, ty, x, y, nx, ny)}"
    return true if h(tx, ty, x, y, nx, ny)
    x = nx
    y = ny
    d += 1
  end
  return false
end

def solve(x, y)
  return g(f(x, y), x, y)
end

if $DEBUG
  5.times do |x|
    # puts "(#{-6 + x}, #{-6}): #{solve(-6 + x, -6)}"
  end

  s = 20
  s.times {|dy|
    s.times {|dx|
      x = -(s/2) + dx
      y = (s/2) - dy
      print ( solve(x, y) ? 'o' : 'x' )
    }
    puts ""
  }
end

gets.to_i.times { puts solve(*gets.split.map(&:to_i)) ? YES : NO }

#
#
#

if $DEBUG
  require 'minitest/autorun'

  class TC_solve < Minitest::Test
    def test_1
      assert_equal solve(0, 0), true
      assert_equal solve(0, -2), true
      assert_equal solve(1, -2), true
      assert_equal solve(1, 1), true
      assert_equal solve(3, 3), true
      assert_equal solve(3, 4), true
      assert_equal solve(3, 0), true
      assert_equal solve(-2, 0), true
      assert_equal solve(2, 4), true
      assert_equal solve(-2, 4), true
      assert_equal solve(-3, 4), true
      assert_equal solve(-4, 4), true
      assert_equal solve(-1 * ( 10 ** 9 ), -1 * ( 10 ** 9 )), true
    end

    def test_a
      assert_equal solve(-1, -2), true
    end

    def test_false
      assert_equal solve(-1, -1), false
      assert_equal solve(-1, 1), false
      assert_equal solve(0, 1), false
      assert_equal solve(0, -1), false
      assert_equal solve(0, -2), true
      assert_equal solve(2, 3), false
      assert_equal solve(2, 2), false
      assert_equal solve(2, 1), false
      assert_equal solve(2, 0), false
      assert_equal solve(-3, -3), false
      assert_equal solve(-5, 4), false
      assert_equal solve(-5, -5), false
    end
  end

  class TC_g < Minitest::Test
    def test_start
      assert_equal g(0, 0, 0), true
    end

    def test_outer
      assert_equal g(0, 0, 1), false
    end

    def test_inner
      assert_equal g(0, 1, 1), true
    end

    def test_point
      assert_equal g(0, 1, 2), true
      assert_equal g(49, -100, -100), true
    end
  end

  class TC_f < Minitest::Test
    def test_a
      assert_equal f(0, 0), 0
    end

    def test_b
      assert_equal f(1, 0), 0
    end

    def test_c
      assert_equal f(1, 2), 0
    end

    def test_d
      assert_equal f(-2, 2), 0
    end

    def test_e
      assert_equal f(-2, -2), 0
    end

    def test_h
      assert_equal f(3, -2), 0
    end

    def test_i
      assert_equal f(3, 4), 1
    end

    def test_j
      assert_equal f(-100, -100), 49
    end
  end
end



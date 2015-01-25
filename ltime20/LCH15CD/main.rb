require "set"

def xor_sum(list)
  list.inject(0) {|sum, x| sum ^= x }
end

def add_sum(list)
  list.inject(0) {|sum, x| sum += x }
end

def solve(n, d)
  res = nil
  m = Hash.new
  q = Array.new
  spos = (1..n).map { 0 }
  gpos = (1..n).map { d - 1 }
  s = [0].concat spos
  q.push s
  m[spos] = 0
  m.rehash
  until q.empty?
    key = q.first.clone
    q.shift
    cost = key.shift
    pos = key
    next if res && cost >= res
    if gpos == pos
      cost if res.nil? || cost < res
    end
    n.times do |k|
      [1, -1].each do |dpos|
        pos[k] += dpos
        if pos[k] >= 0 && pos[k] < d
          ncost = cost + xor_sum(pos) * add_sum(pos)
          memo = m[pos]
          if res.nil? || ncost < res
            if memo.nil? || ncost < memo
              memo = ncost
              m.rehash
              q.push [ncost].concat(pos)
            end
          end
        end
        pos[k] -= dpos
      end
    end
  end
  res
end

gets.to_i.times do
  puts solve *gets.split.map(&:to_i)
end

def xor_sum(list)
  list.inject(0) {|sum, x| sum ^= x }
end

def add_sum(list)
  list.inject(0) {|sum, x| sum += x }
end

def f(list, n, d)
  if list.length >= n
    p list, xor_sum(list), add_sum(list), xor_sum(list)*add_sum(list)
    return
  end

  d.times do |x|
    list.push x
    f list, n, d
    list.pop
  end
end

f [], 2, 3

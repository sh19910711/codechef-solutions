YES = "YES"
NO = "NO"

def solve(n, k, a)
  n.times do |k1|
    k1 += 1
    (n-k1+1).times do |i|
      return true if a[i, k1].count(&:even?) == k
    end
  end
  
  return false
end

gets.to_i.times { puts solve(*gets.split.map(&:to_i), gets.split.map(&:to_i)) ? YES : NO }


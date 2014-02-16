require 'scanf'

tests = gets.to_i

tests.times {
  a, b = gets.scanf "%d%d"
  puts "#{[a, b].max} #{a + b}"
}


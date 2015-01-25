# @snippet <contest.rb#0.0.7:namespace.rb>
module Solution; end
# @snippet <contest.rb#0.0.7:header.rb>
require "scanf"
require "set"
# @snippet <contest.rb#0.0.7:runner.rb>
class Solution::Runner

  def self.run(input_format, input_stream = STDIN, output_stream = STDOUT, &block)
    Solution::Solver.new(input_format, input_stream, output_stream) do
      input do |args|
        if block.nil?
          output solve(*args)
        else
          output block.call(*args)
        end
      end
    end
  end

end
# @snippet <contest.rb#0.0.7:solver.rb>
class Solution::Solver

  attr_reader :input_format
  attr_reader :input_stream
  attr_reader :output_stream

  def initialize(new_input_format, new_input_stream, new_output_stream, &block)
    @input_format = new_input_format
    @input_stream = new_input_stream
    @output_stream = new_output_stream

    instance_eval(&block) if block_given?
  end

  def input
    while s = gets
      break if s.nil?
      s.scanf(input_format) do |*args|
        yield(*args)
      end
    end
  end

  def output(res)
    puts res
  end

end
# @snippet <contest.rb#0.0.7:main.rb>

class Solution::Solver
  def output(res)
    puts res ? "YES" : "NO"
  end
end

gets.to_i.times do
  input_format = "%s" # scanf(input_format)
  Solution::Runner.run(input_format) do |s|
    ("a".."z").any? do |c|
      s.count(c) * 2 === s.length
    end
  end
end


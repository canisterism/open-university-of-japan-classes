def gcd(x,y)
  count = 0

  while x != y
    count += 1
    puts "x: #{x}, y: #{y}"
    if x > y
      x = x - y
    else
      y = y - x
    end
  end
  puts count
  return x
end

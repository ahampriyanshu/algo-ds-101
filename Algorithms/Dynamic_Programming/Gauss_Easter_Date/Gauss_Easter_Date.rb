def gauss_easter(y)
    a = y % 19
    b = y % 4
    c = y % 7
    
    p = (y / 100).floor
    q = ((13 + 8 * p) / 25).floor
    m = (15 - q + p - (p / 4)) % 30
    
    n = (4 + p - (p / 4)) % 7
    
    d = (19 * a + m) % 30
    
    e = (2 * b + 4 * c + 6 * d + n) % 7
    
    day = (22 + d + e)
      
    if (d == 29) && (e == 6)
        puts("The Easter date for your entered year is: #{y}-04-19")
    elsif (d == 28) && (e == 6)
        return puts("The Easter date for your entered year is: #{y}-04-18")
    else
        if day > 31
            return puts("The Easter date for your entered year is: #{y}-04-#{day-31}")
        else
            return puts("The Easter date for your entered year is: #{y}-03-#{day}")
        end
    end    
end

print("Enter the year you want to calculate the Easter date: ")
y = Integer(gets.chomp())
gauss_easter(y)
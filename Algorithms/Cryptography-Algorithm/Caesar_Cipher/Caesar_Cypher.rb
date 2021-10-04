class CaesarCipher
  ORDER_ALPHABET = ("a".."z").to_a # Array of valid letter rotation (Only english alphabet letters)
  class << self
    def encrypt(sentence, times = 3)
      # Converts to_s allowing to map through each char of it
      sentence.to_s.chars.map.with_index {|char, index|
        # If char is not included in the array, return the char without rotate
        ORDER_ALPHABET.include?(char.downcase) ? rotate(times, char, index) : char
      }.join("")
    end
  
    private
    # Rotates the n times assigned by the user
    def rotate(times,current_char, index)
      ORDER_ALPHABET.rotate(times)[ORDER_ALPHABET.index(current_char.downcase)]
    end
  end
end

puts CaesarCipher.encrypt("Hello World", 13) # uryyb jbeyq
puts CaesarCipher.encrypt("Uryyb jbeyq", -13) # hello world
puts CaesarCipher.encrypt("Th1s 1s @ compl3x w0rd", 5) # ym1x 1x @ htruq3c b0wi
puts CaesarCipher.encrypt(["Also", "Works", "for", "complex", "structures"], 7) # ["hszv", "dvyrz", "mvy", "jvtwsle", "zaybjabylz"]
puts CaesarCipher.encrypt(nil)
puts CaesarCipher.encrypt("Nothing change", 0) # nothing change
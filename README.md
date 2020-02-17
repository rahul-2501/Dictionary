# WordMagic

Functionality


1.Determine if a word can be formed using the letters given to you.
   
    magic("edzlatsh", "hazel") -> true
    magic("uwtaqicy", "watch") -> false
    
2.Handle wildcard characters. "?" can represent any of the 26 characters.
    
    magic("d??????", "code") -> true
    magic("g???", "code") -> false
    
3.Determine the longest word in the enable1 dictionary that can be formed.
    
    longest("uruqrnytrois") -> "turquois"
    longest("rryqeiaegicgeo??") -> "greengrocery"
    
In the case of a tie, any word that's tied for the longest is a valid output.


Functionality 1 & 2 are solved by magic() method.

Functionality 3 is solved by longest() method.

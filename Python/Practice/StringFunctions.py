astring = "Hello world"
bstring = "hello"
#print(len(astring))  # returns length of a string(number of characters)
#print(astring.index("o")) # returns an index of a first occurrence of a chosen character
#print(astring.count("l")) # returns a number of occurrences of a given character in a string
#print(astring[0:5:2]) # returns a substring of a string [starting index:ending index:step] [::] <- from beginning to the end [::-1] <- reverses string
#print(astring.lower())  # all lowercase
#print(astring.upper())  # all caps
#print(bstring.capitalize()) # changes first letter to a capital letter

#print(astring.startswith("Hello")) # this checks if a string starts with something 
#print(astring.endswith("asdf")) # this checks if a string ends with something 

afewwords = astring.split("o")
print(afewwords)
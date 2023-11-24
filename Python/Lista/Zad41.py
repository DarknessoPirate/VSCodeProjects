def cipher(string,key):
    newResult = ""
    for i in string:
        newLetter = ord(i) + key
        if newLetter > ord('z'):
            newLetter -= 26 # if we are out ouf the alphabet scope we get back to the start
        elif newLetter < ord('a'):
            newLetter += 26
        newResult += chr(newLetter)

    return newResult

def decipher(string, key):
    oldResult = ""
    for i in string:
        oldLetter = ord(i) - key
        if oldLetter > ord('z'):
            oldLetter -= 26
        elif oldLetter < ord('a'):
            oldLetter +=26
        oldResult += chr(oldLetter)

    return oldResult

st = "pies"
key = 5
ciphered = cipher(st,key)
deciphered = decipher(ciphered,key)
print(f"{ciphered} = {deciphered}")

        
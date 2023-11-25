
letterDict = {'I':1,
           'V':5,
           'X':10,
           'L':50,
           'C':100,
           'D':500,
           'M':1000}

def fromRoman(str):
    sum = 0

    for i in range(len(str)-1,-1,-1):
        if(i+1 >= len(str)):
            sum += letterDict[str[i]]
        elif(letterDict[str[i]] >= letterDict[str[i+1]]):
            sum += letterDict[str[i]]
        else:
            sum -= letterDict[str[i]]

    return sum
print(fromRoman("MIXX"))
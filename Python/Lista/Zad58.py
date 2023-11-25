
M = ["", "M", "MM", "MMM"]

C = ["", "C", "CC", "CCC", "CD", "D",
    "DC", "DCC", "DCCC", "CM "]

X = ["", "X", "XX", "XXX", "XL", "L",
    "LX", "LXX", "LXXX", "XC"]

I = ["", "I", "II", "III", "IV", "V",
    "VI", "VII", "VIII", "IX"]

def toRoman(str):
    thousands = M[str//1000]
    hundreds = C[(str%1000)//100]
    tens = X[(str%100)//10]
    ones = I[(str%10)]
    result = (thousands + hundreds + tens + ones)

    return result

print(toRoman(1254))
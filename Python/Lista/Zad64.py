from collections import Counter 
import sys



word = Counter(sys.argv[1])
samogloski = ['a','e','i','o','u','ó','y','ą','ę']
sum = 0
for letter in word:
    if letter in samogloski:
        sum += word[letter]

print(f"liczba samoglosek {sum}")
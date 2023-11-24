import sys
import statistics
# python -u  .\Zad16.py liczby.txt <- użycie
numbers = []
sum = 0
file = open(sys.argv[1])

for x in file:
    x = x.strip().split(",")
    for i in x:
        numbers.append(int(i))
        sum += int(i)


print(numbers)
print(f"Suma: {sum}")
if len(numbers) == 0:
    raise ZeroDivisionError("Brak liczb w pliku. Dzielenie przez 0!")

mediana = statistics.median(numbers)
print(f"Średnia: {sum/len(numbers)}")
print(f"Mediana: {mediana}")
file.close()
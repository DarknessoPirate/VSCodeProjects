import sys
import statistics

args = len(sys.argv) - 1
sum = 0

for i in range(1,args+1):
    sum += int(sys.argv[i])

subarray = [int(word) for word in sys.argv[1:args+1]]
srednia = sum/args
mediana = statistics.median(subarray)
print("suma: ", sum)
print(f"średnia: {srednia}", srednia)
print("mediana: ", mediana)
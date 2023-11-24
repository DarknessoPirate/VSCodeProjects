import Zad38 as z
import random as r
import time as t
import math
import sys

sys.setrecursionlimit(10000)

def standardDeviation(arr, sr):
    sum = 0
    for i in arr:
        sum += math.pow(i - sr,2)

    return math.sqrt(sum)



l1 = [r.randint(1,10000) for i in range(10000)]
l2 = [r.randint(1,10000) for i in range(10000)]
l3 = [r.randint(1,10000) for i in range(10000)]
bubble_sum = 0
insert_sum = 0
quick_sum = 0
bubble_times =[]
insert_times = []
quick_times = []
b_sd = 0
i_sd = 0
q_sd = 0


for i in range(3):
    start_bubble = t.time()
    z.bubbleSort(l1)
    end_bubble = t.time()

    start_insert = t.time()
    z.insertionSort(l2)
    end_insert = t.time()

    start_quick = t.time()
    z.quickSort(l3,0,999)
    end_quick = t.time()

    bubble_time = end_bubble - start_bubble
    insert_time = end_insert - start_insert
    quick_time = end_quick - start_quick
    bubble_times.append(bubble_time)
    insert_times.append(insert_time)
    quick_times.append(quick_time)
    bubble_sum += bubble_time
    insert_sum += insert_time
    quick_sum += quick_time

bubble_sr = round(bubble_sum/3,8)
insert_sr = round(insert_sum/3,8)
quick_sr = round(quick_sum/3,8)

b_sd = round(standardDeviation(bubble_times,bubble_sr),8)
i_sd = round(standardDeviation(insert_times,insert_sr),8)
q_sd = round(standardDeviation(quick_times,quick_sr),8)

    

today_info = t.localtime()
today_date = f"{today_info.tm_year}_{today_info.tm_mon}_{today_info.tm_mday}"
print(today_date)
print(f"Bubble: {bubble_sr}")
print(f"Insert: {insert_sr}")
print(f"Quick: {quick_sr}")
print(f"Odchylenia {b_sd} , {i_sd}, {q_sd}")
    
with open(f"raport_[{today_date}]","w") as myFile:
    myFile.write("RAPORT ALGORYTMOW SORTOWANIA\n\n")
    myFile.write("NAZWA -- LICZBA SORTOWANYCH LICZB -- SREDNI CZAS -- ODCHYLENIE\n")
    myFile.write(f"Bubble -- 10000 -- {bubble_sr} -- {b_sd}\n")
    myFile.write(f"Insert -- 10000 -- {insert_sr} -- {i_sd}\n")
    myFile.write(f"Quick -- 10000 -- {quick_sr} -- {q_sd}\n")
    
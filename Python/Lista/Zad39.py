def sredniaMaxMin(list):
    min = 0
    max = 0
    for i in list:
        if(i>max):
            max = i
        if(i<min):
            min = i
    return (min+max)/2

nums = [1,22,4,13,25,15,0]

print(sredniaMaxMin(nums))
def LCG(multiplier,increment,mod,arr):
    result =[]
    for i in arr:
        x =(i*multiplier + increment)%mod
        result.append(x)

    return result

seed = [2173,813571238,12930184,21381990,128743179,127367,745679,128395708,758789,87687]
result = LCG(37,102357127,137,seed)
print(result)
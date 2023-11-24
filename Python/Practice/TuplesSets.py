
#lista = [1,"chuj","trzy","cztery",5]

 
#lista.append("dorime")
#for i in lista:
#    print(i)
#tuple1 = (1,2,"coś")

#set - unordered,unindexed collection without duplicate values

utensils = {"fork","spoon","knife"}
dishes = {"bowl","plate","cup","knife"}
#dinner_table = utensils.union(dishes)
#utensils.add("napkin")
#utensils.remove("fork")
#utensils.clear()
#utensils.update(dishes)
#for x in dinner_table:
#    print(x)

print(utensils.difference(dishes)) 
print(utensils.intersection(dishes))
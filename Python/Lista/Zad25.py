
with open("danezadanie.txt") as file:
    i = int(file.read())

f = open("liczbykonwertowane.txt","a") 
f.write(str(i)+ "\n")
f.write(str(hex(i) + "\n"))
f.write(str(oct(i)+"\n"))

f.close()
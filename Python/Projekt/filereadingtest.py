data = {}
day = -1 

def readDataFromFile(filepath, dict):
    with open(filepath,"r") as myFile:
        for line in myFile:
            if line[0] is "#":
                day = int(line.removeprefix("#"))
                if (day > 0 and day < 32 and day not in dict):
                    dict[day] = []

            elif (day in dict):
                    if line.strip() is not "":
                        dict[day].append(line.strip())

def saveDataToFile(filepath, dict):
     with open(filepath,"w") as myFile:
          for key in dict:
               myFile.write(f"#{key}\n")

               for value in dict[key]:
                    myFile.write(f"{value}\n")

readDataFromFile("C:\\VSCodeProjects\\Python\\Projekt\\testreadfile.txt",data)
saveDataToFile("C:\\VSCodeProjects\\Python\\Projekt\\testwritefile.txt",data)
print(data)
str = ""

for item in data[2]:


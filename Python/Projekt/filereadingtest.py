data = {}


def readDataFromFile(filepath, dict):
    with open(filepath,"r") as myFile:
        for line in myFile:
            if line[0] == "#":
                date = line.removeprefix("#").strip()
                day = int(date[0:2:1])
                if (day > 0 and day < 32 and date not in dict):
                    dict[date] = []

            elif (date in dict):
                    if line.strip() != "":
                        dict[date].append(line.strip())

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




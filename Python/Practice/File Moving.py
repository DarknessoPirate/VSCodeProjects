import os

source = "C:\\VSCodeProjects\\PythonProjects\\Practice\\copy.txt" # where our file is located(we can also move a folder)
destination = "C:\\VSCodeProjects\\PythonProjects\\copy.txt" # where we want to move the file

try:

    if os.path.exists(destination):
        print("There is already a file there!")
    
    else:
        os.replace(source,destination)
        print(source + " was moved")

except FileNotFoundError:
    print(source + "was not found")
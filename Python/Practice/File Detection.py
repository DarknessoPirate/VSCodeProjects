import os ## library for files

path = "C:\\Users\\Darknesso\\Desktop\\text.txt" ## saving the path 

if os.path.exists(path): ## checking if the path exists
    print("That location exists!")
    if os.path.isfile(path):
        print("That is a file!") ## checking if the location is an actual file, if the location is a directory/folder the condition is not met
    elif os.path.isdir(path):     ## checking if the given location is a folder
        print("That is a directory!")
else:
    print("That location doesn't exist")
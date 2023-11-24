
try:
    with open("C:\\VSCodeProjects\\PythonProjects\\Practice\\file.txt") as file:  ## this closes the files automatically 
        print(file.read())

    #print(file.closed) ## Testing if it really closes the file. It prints true so it does.
except FileNotFoundError:
    print("That file was not found!")
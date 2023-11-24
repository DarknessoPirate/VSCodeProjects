text = " A newly added line of text\n Another line of text"

with open("C:\\VSCodeProjects\\PythonProjects\\Practice\\file.txt",'a',) as file: # if we use 'w' to write to a file it overwrites already existing text
    file.write(text)                                                             # we can use 'a' to append text to already existing text
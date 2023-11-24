import shutil  # utility functions for copying and archiving files
# copyfile() - copies contents of a file
# copy() - copyfile() + permission mode + destination can be a directory
# copy2() = copy() + copies metadata(file's creation and modification times)


shutil.copyfile('C:\\VSCodeProjects\\PythonProjects\\Practice\\file.txt','C:\\VSCodeProjects\\PythonProjects\\Practice\\copy.txt') #source,destination*(can rename too)

shutil.copy('C:\\VSCodeProjects\\PythonProjects\\Practice\\file.txt','C:\\VSCodeProjects\\PythonProjects\\Practice\\copy1.txt')
shutil.copy2('C:\\VSCodeProjects\\PythonProjects\\Practice\\file.txt','C:\\VSCodeProjects\\PythonProjects\\Practice\\copy2.txt')
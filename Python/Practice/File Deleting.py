import os 
import shutil
folder_path = "C:\\VSCodeProjects\\PythonProjects\\Practice\\empty_folder" #when we try to delete empty folder we get access denied error
file_path = "C:\\VSCodeProjects\\PythonProjects\\Practice\\copy1.txt"

try:
    #os.remove(folder_path) # doesn't work(access deniec)
    #os.remove(file_path)
    os.rmdir(folder_path) # used to remove empty directories
    shutil.rmtree(folder_path) # used to remove directories containing files and everything within

except FileNotFoundError:
    print("File not found!")
except PermissionError:
    print("Access denied!")
except OSError:
    print("You cannot delete a folder containing files using that function!")

else:
    print("Path was deleted")
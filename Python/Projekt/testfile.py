import os

if not os.path.exists("data.txt"):
    print("Creating file")
    with open("data.txt","w") as file:
        file.write("")
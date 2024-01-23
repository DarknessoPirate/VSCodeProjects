import tkinter as tk
import customtkinter as ctk
import calendar as cal
import math
from datetime import date
import os

####### global variables ##########
current_month = date.today().month#
current_year = date.today().year  #
daysData = {}                     #
###################################

def generate_dict_index(button_number):

    if (button_number > 0 and button_number < 10):
        if(current_month < 10):
            button_index = f"0{button_number}-0{current_month}-{current_year}"
        else:
            button_index = f"0{button_number}-{current_month}-{current_year}"
    else:
        if(current_month < 10):
            button_index = f"{button_number}-0{current_month}-{current_year}"
        else:
            button_index = f"{button_number}-{current_month}-{current_year}"
    
    return button_index
###########################################################################

def saveDataToFile(filepath, data):
    with open(filepath, "w") as myFile:
        for key in data:
            write = False
            for element in data[key]:
                if element.strip() != "" and element != "":
                    write = True
                    break;
            if write==True:
                myFile.write(f"#{key}\n")
                for element in data[key]:
                    if element.strip() != "" and element != "":
                        myFile.write(f"{element}\n")

##########################################################################

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

###########################################################################
                        
def closeTextWindow(element,button_number,data):
    button_index = generate_dict_index(button_number)

    data[button_index] = element.get("1.0",tk.END).split("\n")
    element.destroy()

###########################################################################

def openTaskList(root,button_number, data):
    button_index = generate_dict_index(button_number)

    tasks = ""
    if button_index in data:
        for task in data[button_index]:
            tasks += task + '\n'
    else:
        data[button_index] = {}
    textBox = ctk.CTkTextbox(root, width = 500, height = 500, bg_color="#476c9b")
    textBox.insert(tk.END, tasks)
    textBox.place(x = 256, y = 100)
    closeButton = ctk.CTkButton(textBox, width = 10, height = 10, text = "X", text_color="black", corner_radius=20 ,fg_color="#981722", bg_color="#1d1e1e", command = lambda: closeTextWindow(textBox, button_number, data))
    closeButton.place(relx = 0.96, rely= 0.0)


###########################################################################

def createPage(root, month, year , offsetx, offsety, data):
    dayFrame = ctk.CTkFrame(root, width = 1009, height = 725, fg_color="#94BEDE")
    dayFrame.pack()
    global currentFrameHandle
    currentFrameHandle = dayFrame
    NO_OF_DAYS = cal.monthrange(year, month)[1]
    current_day = 1
    rows = math.ceil(NO_OF_DAYS/7)
    columns = 7
    saved_offsetx = offsetx
    for i in range(rows):
        for j in range(columns):
            if(current_day > NO_OF_DAYS):
                break

            else:
                button = ctk.CTkButton(dayFrame, 
                       width=140, 
                       height=140, 
                       fg_color="#476C9B", 
                       hover_color="#41618B", 
                       border_color="#101419", 
                       border_width=2,
                       text = 7*i+j+1,
                       text_color="#323639",
                       corner_radius=20, 
                       font = ("Roboto Mono",30),
                       command = lambda i = current_day: openTaskList(root, i, data)).grid(column = j, row = i, padx = 2, pady = 2)
                offsetx += 143
                current_day += 1
        offsetx = saved_offsetx
        offsety += 143

###########################################################################

def createNextPage(root, offsetx, offsety, data):
    global current_year
    global current_month
    global currentFrameHandle
    global dateLabel
    if current_month == 12:
        current_year += 1
        current_month = 1
    else:
        current_month += 1
    dateLabel.configure(text=f"{cal.month_name[current_month]} / {current_year}")
    currentFrameHandle.destroy()
    createPage(root, current_month, current_year,offsetx, offsety, data)

###########################################################################

def createPrevPage(root, offsetx, offsety,data):
    global current_year
    global current_month
    global currentFrameHandle
    global dateLabel
    if current_month == 1:
        current_year -= 1
        current_month = 12
    else:
        current_month += -1
    dateLabel.configure(text=f"{cal.month_name[current_month]} / {current_year}")
    currentFrameHandle.destroy()
    createPage(root, current_month, current_year,offsetx, offsety, data)

##############################################################################################################################################################################################
# if config filenot present create an empty one
if not os.path.exists("data.txt"):
    with open("data.txt","w") as file:
        file.write("")

# read data for the first time and save it in a dictionary
readDataFromFile("data.txt", daysData)

# creating root element
window = ctk.CTk(fg_color="#94BEDE")
window.geometry('1009x765')
window.title("Calendar")
window.resizable(width = False, height = False)

# top button frame creation
buttonFrame = ctk.CTkFrame(window,width = 1000, height=50, fg_color="#94BEDE")
buttonFrame.pack(fill=tk.BOTH)

# create first page 
createPage(window, current_month, current_year, 73, 110, daysData)

# button creation
dateLabel = ctk.CTkLabel(buttonFrame, width = 150 ,text=f"{cal.month_name[current_month]} / {current_year}",corner_radius=7, fg_color="#1E2A3A", text_color="#FAFAFF")
nextButton = ctk.CTkButton(buttonFrame, text = "Next month", fg_color="#1E2A3A", hover_color="#2D3D4F", text_color="#FAFAFF", font = ("Roboto Mono",15), corner_radius=20, command = lambda: createNextPage(window,73, 110,daysData))
prevButton = ctk.CTkButton(buttonFrame, text = "Previous month", fg_color="#1E2A3A", text_color="#FAFAFF", font = ("Roboto Mono",15), corner_radius=20, command = lambda: createPrevPage(window,73, 110,daysData))
saveButton = ctk.CTkButton(buttonFrame, text = "Save", fg_color="#1E2A3A", hover_color="#2D3D4F", text_color="#FAFAFF", font = ("Roboto Mono",15), command = lambda:saveDataToFile("data.txt",daysData))

# configuring the button layout
dateLabel.grid(column=1,row=1, padx = 67)
prevButton.grid(column=3,row=1,padx = 3, pady = 7 )
saveButton.grid(column=4,row=1,padx = 3, pady = 7)
nextButton.grid(column=5,row=1,padx = 3, pady = 7)
window.mainloop()
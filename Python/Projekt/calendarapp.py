import tkinter as tk
from tkinter import ttk
import customtkinter as ctk
from PIL import Image, ImageTk
import calendar as cal
import math
from datetime import date

#################################################################################################

def saveDataToFile(filepath, data):
    with open(filepath, "w") as myFile:
        for key in data:
            myFile.write(f"#{key}\n")
            for element in data[key]:
                myFile.write(f"{element}\n")

#################################################################################################

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

###############################################################################################

def closeTextWindow(element,day_number,data):
    data[day_number] = element.get("1.0",tk.END)
    element.destroy()

###############################################################################################

def openTaskList(root,button_number, data):
    tasks = ""
    for task in data[button_number]:
        tasks += task + '\n'
    textBox = ctk.CTkTextbox(dayFrame, width = 500, height = 500)
    textBox.insert(tk.END, tasks)
    textBox.place(x = 256, y = 100)
    closeButton = ctk.CTkButton(textBox, width = 10, height = 10, text = "X", text_color="black", command = lambda: closeTextWindow(textBox, button_number, data))
    closeButton.place(relx = 0.96, rely= 0.0)

def createNewPage(root, month, offsetx, offsety,data):
def createNewPage(root, month, offsetx, offsety,data):
    
    NO_OF_DAYS = cal.monthrange(2023, month)[1]
    current_day = 1
    rows = math.ceil(NO_OF_DAYS/7)
    columns = 7
    saved_offsetx = offsetx
    for i in range(rows):
        for j in range(columns):
            if(current_day > NO_OF_DAYS):
                break

            else:
                button = ctk.CTkButton(root, 
                       width=140, 
                       height=140, 
                       fg_color="#30CA46", 
                       hover_color="#2ab33e", 
                       border_color="#323639", 
                       border_width=2,
                       text = 7*i+j+1,
                       text_color="#323639",
                       corner_radius=20, 
                       font = ("Roboto Mono",15),
                       command = lambda i = current_day: openTaskList(root, i, data)).grid(column = j, row = i, padx = 2, pady = 2)
                #dayHandles.append([button, 7*i + j+1])
                offsetx += 143
                current_day += 1
        offsetx = saved_offsetx
        offsety += 143
'''
def nextPage(direction, selected_month, selected_year):
    if selected_year in fullData:
        if (current_month + direction) in fullData[selected_month]:
            fullData[selected_year][selected_month+direction][0].pack()
        else:
            fullData[selected_year][selected_month][0].pack_forget()
            fullData
            createNewPage()
'''
##############################################################################################################################################################################################
'''


#fullData = {}
#dayHandles = []
daysData = {}
current_month = date.today().month


readDataFromFile("testreadfile.txt", daysData)

# window creation
window = ctk.CTk(fg_color="white")
window.geometry('1009x765')
window.title("Calendar")
window.resizable(width = False, height = False)

# frames creation
buttonFrame = ctk.CTkFrame(window,width = 1009, height=40, fg_color="white")
dayFrame = ctk.CTkFrame(window, width = 1009, height = 725, fg_color="white")
buttonFrame.pack()
dayFrame.pack()

createNewPage(dayFrame,current_month, 73, 110, daysData)
# button creation
nextButton = ctk.CTkButton(buttonFrame, text = "Next month", fg_color="#BB342F", text_color="#323639", font = ("Roboto Mono",15), corner_radius=20, command = lambda: nextPage(1))
prevButton = ctk.CTkButton(buttonFrame, text = "Previous month", fg_color="#BB342F", text_color="#323639", font = ("Roboto Mono",15), corner_radius=20, command = lambda: nextPage(-1))
saveButton = ctk.CTkButton(buttonFrame, text = "Save", fg_color="#BB342F", text_color="#323639", font = ("Roboto Mono",15), command = lambda:saveDataToFile("testwritefile.txt",daysData))
prevButton.pack(side = "left", padx = 3, pady = 3)
nextButton.pack(side = "right",padx = 3, pady = 3)
saveButton.pack(side = "right", padx = 10, pady = 5)
window.mainloop()
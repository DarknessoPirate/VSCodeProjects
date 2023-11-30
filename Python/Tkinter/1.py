import tkinter as tk
#from tkinter import ttk # not needed anymore
import ttkbootstrap as ttk

# Function used by the button
def convert():
    mile_input = entry_int.get()
    km_output = mile_input * 1.61
    output_string.set(km_output)

# creating a window
window = ttk.Window(themename = 'journal') # .Tk() returns a window object
# window customization
window.title('Converter')
window.geometry("300x300")
# Creating label
title_label = ttk.Label(master = window, text = "Miles to kilometers", font = 'Calibri 20 bold')
title_label.pack() # pack renders the widget
# Input field
input_frame = ttk.Frame(master = window) # creating a frame that we will attach things to
# Creating input field and button
entry_int = tk.IntVar() # int for storing data entered in entry field
entry = ttk.Entry(master = input_frame, textvariable = entry_int) # setting up master as the frame above
button = ttk.Button(master = input_frame, text = "Convert",command = convert) # dont pass convert()
# Rendering
entry.pack(side = 'left', padx = 5)
button.pack(side = 'left')
input_frame.pack(pady = 5)

# Output Label
output_string = tk.StringVar()
output_label = ttk.Label(master = window, text = "Output", font = "Calibri 20",textvariable = output_string)
output_label.pack(pady = 5)


## run mainloop
window.mainloop()

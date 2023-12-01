import tkinter as tk
from tkinter import ttk

def button_function():
    entry_text = entry.get()
    #update the label on click
    #label.config(text = "Some other text") # or use label[""] = / label.configure() does the same thing as .config()
    label["text"] = entry_text
    entry['state'] = 'disabled'
    # print(label.config()) ## print config options that are available

#window
window = tk.Tk()
window.title("Getting and setting widgets")
window.geometry("200x100")
#widgets 
label = ttk.Label(master = window, text = "Some text")
label.pack() #render

#entry
entry = ttk.Entry(master = window)
entry.pack()
#button
button = ttk.Button(master = window, text = "Button", command = button_function)
button.pack()
#mainloop
window.mainloop()
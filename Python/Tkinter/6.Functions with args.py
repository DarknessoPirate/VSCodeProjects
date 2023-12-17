import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.title("Buttons, functions and arguments")

entry_string = tk.StringVar(value = "text")
entry = ttk.Entry(window, textvariable=entry_string)
entry.pack()

def button_func(entry_string):
    print("a button was pressed")
    print(entry_string.get())

def outer_func(parameter):
    def inner_func():
        print("A button was pressed")
        print(parameter.get())
    return inner_func

#button = ttk.Button(window, text = "button", command = lambda: button_func(entry_string))
button = ttk.Button(window, text = "button", command = outer_func(entry_string))
button.pack()

window.mainloop()
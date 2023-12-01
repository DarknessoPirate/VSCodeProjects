import tkinter as tk
from tkinter import ttk

#window
window = tk.Tk()
window.title("Buttons")
window.geometry("600x400")

# basic button

def button_func():
    print("a basic button")
button_string = tk.StringVar(value = "A button with string var")
button = ttk.Button(window, text = "A simple button", command = button_func , textvariable = button_string ) # you can pass just the window as first argument instead of master = window
button.pack()

# checkbox 
check = ttk.Checkbutton(window, text = "checkbox1", command = lambda: print("Check button"))
check.pack()

# main loop
window.mainloop()
import tkinter as tk
from tkinter import ttk

#window
window = tk.Tk()
window.title("Buttons")
window.geometry("600x400")

# basic button

def button_func():
    print("a basic button")
    print(radio_var.get())
button_string = tk.StringVar(value = "A button with string var")
button = ttk.Button(window, text = "A simple button", command = button_func , textvariable = button_string ) # you can pass just the window as first argument instead of master = window
button.pack()

# checkbox 
check_var = tk.IntVar() # can also use StringVar or BooleanVar to store the 0 and 1 of the checkbox              #onvalue/offvalue changes what is returned when the button is on/off
check = ttk.Checkbutton(window, text = "Checkbox1", command = lambda: print(check_var.get()), variable=check_var,onvalue=2,offvalue=3) 
check.pack()
check2 = ttk.Checkbutton(window, text = "Checkbox2", command = lambda: check_var.set(5))
check2.pack()
# radio buttons
radio_var = tk.StringVar() # to store the return value of the button state
radio1 = ttk.Radiobutton(window, text = "Radiobutton 1", value = "Radiobutton 1", variable = radio_var, command = lambda: print(radio_var.get())) 
radio2 = ttk.Radiobutton(window, text = "Radiobutton 2", value = 2, variable= radio_var) # if they have the same value they will be checked at the same time
radio1.pack()
radio2.pack()

#exercise
def radio_func():
    print(check_bool.get())

shared_variable = tk.StringVar()
exercise_radio1 = ttk.Radiobutton(window, text = "Radio A", value = "A", variable = shared_variable, command = radio_func)
exercise_radio2 = ttk.Radiobutton(window, text = "Radio B", value = "B", variable = shared_variable, command = radio_func)
exercise_radio1.pack()
exercise_radio2.pack()

check_bool = tk.BooleanVar()
exercise_check = ttk.Checkbutton(window,text = "Exercise check",variable = check_bool,command = lambda:print(shared_variable.get()))
exercise_check.pack()
# main loop
window.mainloop()
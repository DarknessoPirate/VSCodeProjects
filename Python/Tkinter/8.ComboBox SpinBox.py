import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.geometry("600x400")
window.title("Combo and spin")

food_string = tk.StringVar()
items = ["Ice cream", "Pizza", "Burger"]
#Combo Box
combo = ttk.Combobox(window, values = items,textvariable=food_string)
combo.pack()

#combo.bind("<<ComboboxSelected>>", lambda event: print(food_string.get()))
combo.bind("<<ComboboxSelected>>", lambda event: combo_label.config(text = f"Selected value: {food_string.get()}"))

combo_label = ttk.Label(window)
combo_label.pack()

#Spin box
#spin_values = [1,2,3,4,5]
#spin = ttk.Spinbox(window,values = spin_values)
spin_int = tk.IntVar(value = 12)
spin = ttk.Spinbox(window, 
                   from_= 3, 
                   to = 20, 
                   increment=2, 
                   command = lambda: print(spin_int.get()),
                   textvariable = spin_int)
spin.bind("<<Increment>>", lambda event: print("Up"))
spin.bind("<<Decrement>>", lambda event: print("Down"))
spin.pack()

window.mainloop()
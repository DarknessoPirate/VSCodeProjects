import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.geometry("600x500")
window.title("Event binding")

text = tk.Text(window)
text.pack()

entry = ttk.Entry()
entry.pack()

button = ttk.Button(window, text = "A button")
button.pack()

def get_pos(event):
    print(f"x:{event.x}, y:{event.y}")

#window.bind("<modifier-type-detail>", lambda event:print(event))
button.bind("<Alt-KeyPress-a>", lambda event:print("Event happened"))
#text.bind("<Motion>", get_pos)
#window.bind("<KeyPress>", lambda event: print(event.char))
window.bind("<Shift-MouseWheel>", lambda event: print("mousewheel used"))
entry.bind("<FocusIn>", lambda event: print("entry field selected"))
entry.bind("<FocusOut>", lambda event: print("entry field unselected"))

window.mainloop()
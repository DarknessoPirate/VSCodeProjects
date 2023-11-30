import tkinter as tk
from tkinter import ttk

#function used by the button
def button_function():
    print("A button was pressed!") # prints to terminal on button press


# Create a window
window = tk.Tk()
# Modify the window
window.title("Window and widgets")
window.geometry("800x500")

# ttk label
label = ttk.Label(master = window, text = 'Test text')
label.pack()

# tk text
text = tk.Text(master = window) # multi-line textbox
text.pack()

# ttk entry
entry = ttk.Entry(master = window)
entry.pack()

# ttk button
button = ttk.Button(master = window, text = "Button", command = button_function)
button.pack()

button2 = ttk.Button(master = window, text = "Lambda test", command = lambda: print("Lambda function executed!"))
button2.pack()
# Main Loop
window.mainloop()
import tkinter

def calculate(*args):
    try:
        value = float(feet.get())
        meters.set(int(0.3048 * value * 10000.0 + 0.5)/10000.0)
    except ValueError:
        pass

root = tkinter.Tk()
root.title("Converter")

mainframe = tkinter.Frame(root, padx=0)
mainframe.grid(column=0, row=0, sticky=(tkinter.N, tkinter.W, tkinter.E, tkinter.S))

root.columnconfigure(0, weight=1)
root.rowconfigure(0, weight=1)

feet = tkinter.StringVar()
feet_entry = tkinter.Entry(mainframe, width=7, textvariable=feet)
feet_entry.grid(column=2, row=1, sticky=(tkinter.W, tkinter.E))

meters = tkinter.StringVar()
tkinter.Label(mainframe, textvariable=meters).grid(column=2, row=2, sticky=(tkinter.W, tkinter.E))

tkinter.Button(mainframe, text="Calculate", command=calculate).grid(column=3, row=3, sticky=tkinter.W)

tkinter.Label(mainframe, text="feet").grid(column=3, row=1, sticky=tkinter.W)
tkinter.Label(mainframe, text="is equivalent to").grid(column=1, row=2, sticky=tkinter.E)
tkinter.Label(mainframe, text="meters").grid(column=3, row=2, sticky=tkinter.W)

for child in mainframe.winfo_children(): 
    child.grid_configure(padx=5, pady=5)

feet_entry.focus()
root.bind("<Return>", calculate)

root.mainloop()
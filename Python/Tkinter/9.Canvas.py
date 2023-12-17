import tkinter as tk

window = tk.Tk()
window.geometry("600x400")
window.title("Canvas")

canvas = tk.Canvas(window, bg = "white") # by default is invisible
canvas.pack()
canvas.create_rectangle((50,50,100,100),fill = "Blue",width=0) #points on canvas, width refers to outline
canvas.create_line(100,100,200,0,fill = "Red") #(start_x, start_y, end_x, end_y)
canvas.create_oval(10,10,100,200)#(left,top,right,bottom)
canvas.create_arc((200,100,300,200),fill = "Green",start = 45) # start = angle
window.mainloop()
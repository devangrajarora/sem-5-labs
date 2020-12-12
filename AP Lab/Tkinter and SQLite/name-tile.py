from tkinter import *
main_window = Tk() #create parent frame
label1 = Label(main_window, text="Devang", borderwidth = 10)
label2 = Label(main_window, text="Arora", borderwidth = 10)
# grid is used to specify relative position on widget on window
# this must be specified for the widget to be drawn on the screen
label1.grid(row = 0, column = 0)
label2.grid(row = 0, column = 1)
mainloop() # this is where tkinter application enters in event loop
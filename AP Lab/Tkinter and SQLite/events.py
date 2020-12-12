# Tkinter app runs most of it's time in an event loop
# It enters the event loop from mainloop() function

#widget.bind(event, handler) -> bind widget perform handler when event occurs

from tkinter import *

def hello(event):
	print('Single Click')

def quit(event):
	print('Bye Bye')
	import sys
	sys.exit()

widget = Button(None, text='Mouse Click')
widget.pack()

widget.bind('<Button-1>', hello)
widget.bind('<Double-1>', quit)
widget.mainloop()
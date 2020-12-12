from tkinter import *

class Application(Frame):

	def __init__(self, master=None):
		Frame.__init__(self, master)
		self.grid()
		self.counter = 0
		self.create_widgets()

	def create_widgets(self):
		self.labelString = f'Count: {self.counter}'
		self.label = Label(self, text=self.labelString)
		self.label.grid(row = 0, column = 0)
		self.inc_button = Button(self,text="Increment",command=lambda : self.update_counter(1))
		self.inc_button.grid(row = 0, column = 1)
		self.dec_button = Button(self,text="Decrement",command=lambda : self.update_counter(-1))
		self.dec_button.grid(row = 0, column = 2)
		self.quit_button = Button(self,text="Quit",command=self.master.destroy)
		self.quit_button.grid(row = 1, column = 0)

	def update_counter(self, val):
		self.counter = self.counter + val
		self.labelString = f'Count: {self.counter}'
		self.label.configure(text=self.labelString)

app = Application()
app.mainloop()
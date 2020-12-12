from tkinter import *

class Application(Frame):

	def __init__(self, master=None):
		Frame.__init__(self, master)
		self.grid()
		self.counter = 0
		self.labelString = f'Count: {self.counter}'
		self.create_widgets()

	def create_widgets(self):
		self.label = Label(self, text=self.labelString)
		self.label.grid(row = 0, column = 0)
		self.inc_button = Button(self,text="Increment",command=self.inc_counter)
		self.inc_button.grid(row = 0, column = 1)
		self.dec_button = Button(self,text="Decrement",command=self.dec_counter)
		self.dec_button.grid(row = 0, column = 2)
		self.quit_button = Button(self,text="Quit",command=self.master.destroy)
		self.quit_button.grid(row = 1, column = 0)

	def inc_counter(self):
		self.counter = self.counter + 1
		self.labelString = f'Counte: {self.counter}'
		self.label.configure(text=self.labelString)

	def dec_counter(self):
		self.counter = self.counter - 1
		self.labelString = f'Counte: {self.counter}'
		self.label.configure(text=self.labelString)

app = Application()
app.mainloop()
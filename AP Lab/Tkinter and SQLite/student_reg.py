from tkinter import *
import tkinter.messagebox
import sqlite3

def addToDB():
	Name = nameField.get()
	Regno = regnoField.get()
	Age = ageField.get()

	conn.execute(f"INSERT INTO Students VALUES(\'{Regno}\', \'{Name}\', {Age})")
	tkinter.messagebox.showinfo("INFO", "Student details added")

	name.set("")
	age.set("")
	regno.set("")


def getFromDB():
	cursor = conn.execute("SELECT * FROM Students")
	for row in cursor:
		print(row)

conn = sqlite3.connect('Student.db')
print('DB created')

conn.execute('''
	CREATE TABLE IF NOT EXISTS Students(
		regno TEXT PRIMARY KEY,
		name TEXT NOT NULL,
		age INT
	);''')

print('Table created')

window = Tk()
window.title = 'Student Registration Form'

nameLabel = Label(window, text="Name")
nameLabel.grid(row=1,column=1)

name = StringVar()
nameField = Entry(window, textvariable=name)
nameField.grid(row=1,column=2)

regnoLabel = Label(window, text="Reg No")
regnoLabel.grid(row=2,column=1)

regno = StringVar()
regnoField = Entry(window, textvariable=regno)
regnoField.grid(row=2,column=2)

ageLabel = Label(window, text="Age")
ageLabel.grid(row=3,column=1)

age = IntVar()
ageField = Entry(window, textvariable=age)
ageField.grid(row=3,column=2)

addButton = Button(window, text="Add to DB", command=lambda: addToDB())
addButton.grid(row=5,column=2)

getButton = Button(window, text="Show entries", command=lambda: getFromDB())
getButton.grid(row=5,column=3)

window.mainloop()
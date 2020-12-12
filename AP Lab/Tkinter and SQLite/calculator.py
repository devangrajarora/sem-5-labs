from tkinter import *
import sqlite3

express_numion=""
id=0

def write_file(x):
    filepath="output.txt"
    f=open(filepath,'w',encoding='utf-8')
    f.write(x)
    f.flush()
    f.close()

#connect to sqlite
def init_db():
    conn=sqlite3.connect('results.db')
    conn.execute("DROP TABLE IF EXISTS RES")
    conn.execute('''CREATE TABLE RES (ID INTEGER PRIMARY KEY AUTOINCREMENT, EVAL CHAR(50));''')
    conn.close()

def print_to_db(pid,x):
    conn=sqlite3.connect('results.db')
    conn.execute("INSERT INTO RES(ID,EVAL) VALUES("+str(pid)+","+x+");")
    conn.commit()
    conn.close()

def get_from_db():
    conn=sqlite3.connect('results.db')
    res=conn.execute("SELECT * FROM RES")
    for row in res:
        print(row)
    conn.close()

#implement Button 
def press(x):
    global express_numion
    express_numion=express_numion+x
    equation.set(express_numion)

#implement equal Button press_num
def equal_button():
    global express_numion
    result=str(eval(express_numion))
    global id
    id=id+1
    equation.set(result)
    write_file(result)
    print_to_db(id,result)
    get_from_db()
    express_numion=""

#implement clear Button
def on_clear():
    global express_numion
    express_numion=""
    equation.set("")

#create a window
window=Tk()
window.title("Calculator")
init_db()

equation=StringVar() # holds a string variable
# in order to get data written into Entry widget, we have to set it to an instance of StrVar()
expression_field=Entry(window,textvariable=equation)
expression_field.grid(columnspan=4,ipadx=70)

Button1 = Button(window, text=' 1 ', fg='black', command=lambda: press('1'), height=1, width=7) 
Button1.grid(row=2, column=0) 
  
Button2 = Button(window, text=' 2 ', fg='black', command=lambda: press('2'), height=1, width=7) 
Button2.grid(row=2, column=1) 

Button3 = Button(window, text=' 3 ', fg='black', command=lambda: press('3'), height=1, width=7) 
Button3.grid(row=2, column=2) 
  
Button4 = Button(window, text=' 4 ', fg='black', command=lambda: press('4'), height=1, width=7) 
Button4.grid(row=3, column=0) 
  
Button5 = Button(window, text=' 5 ', fg='black', command=lambda: press('5'), height=1, width=7) 
Button5.grid(row=3, column=1) 

Button6 = Button(window, text=' 6 ', fg='black', command=lambda: press('6'), height=1, width=7) 
Button6.grid(row=3, column=2) 

Button7 = Button(window, text=' 7 ', fg='black', command=lambda: press('7'), height=1, width=7) 
Button7.grid(row=4, column=0) 

Button8 = Button(window, text=' 8 ', fg='black', command=lambda: press('8'), height=1, width=7) 
Button8.grid(row=4, column=1) 

Button9 = Button(window, text=' 9 ', fg='black', command=lambda: press('9'), height=1, width=7) 
Button9.grid(row=4, column=2) 

Button0 = Button(window, text=' 0 ', fg='black', command=lambda: press('0'), height=1, width=7) 
Button0.grid(row=5, column=0) 

plus = Button(window, text=' + ', fg='black', command=lambda: press("+"), height=1, width=7) 
plus.grid(row=2, column=3) 

minus = Button(window, text=' - ', fg='black', command=lambda: press("-"), height=1, width=7) 
minus.grid(row=3, column=3) 

multiply = Button(window, text=' * ', fg='black', command=lambda: press("*"), height=1, width=7) 
multiply.grid(row=4, column=3) 

divide = Button(window, text=' / ', fg='black', command=lambda: press("/"), height=1, width=7) 
divide.grid(row=5, column=3) 

equal = Button(window, text=' = ', fg='black', command=equal_button, height=1, width=7) 
equal.grid(row=5, column=2) 

clear = Button(window, text='Clear', fg='black', command=on_clear, height=1, width=7) 
clear.grid(row=5, column='1') 

Decimal= Button(window, text='.', fg='black', command=lambda: press('.'), height=1, width=7) 
Decimal.grid(row=6, column=0) 

window.mainloop()
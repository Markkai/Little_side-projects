
# 步驟一：匯入 tkinter 模組。
from tkinter import*
import tkinter
import tkinter.font as tkfont

# 步驟二：建立主視窗。
win = Tk()

# 視窗標題
win.title("Dec_Bn_Hex")
# 視窗大小
win.geometry("250x500+200+200")
Titlestyle = tkfont.Font(family="微軟正黑體", size=15)
Valstyle = tkfont.Font(family="微軟正黑體", size=14)

# 步驟三：Result labels。
# 建立標籤
DecLabel = Label(text="Input Decimal Num:", font=Titlestyle)
DecLabel.grid(row=0, column=1, padx=5, pady=5)
# 建立Input文字方塊
DecNum = Entry()
DecNum.grid(row=1, column=1, padx=17, pady=5)
DecNum.config(width=30)

# 建立 Hex Bny Oct Labels
HexLabel = Label(text="Hex Number:", font=Titlestyle)
HexLabel.grid(row=3, column=1, padx=5, pady=5, sticky=tkinter.W)
HexShow = Label(text="", bg="SlateGray2", font=Valstyle)
HexShow.grid(row=4, column=1, padx=5, pady=5, sticky=tkinter.W)

BnyLabel = Label(text="Bny Number:", font=Titlestyle)
BnyLabel.grid(row=5, column=1, padx=5, pady=5, sticky=tkinter.W)
BnyShow = Label(text="", bg="SlateGray2", font=Valstyle)
BnyShow.grid(row=6, column=1, padx=5, pady=5, sticky=tkinter.W)

OctLabel = Label(text="Oct Number:", font=Titlestyle)
OctLabel.grid(row=7, column=1, padx=5, pady=5, sticky=tkinter.W)
OctShow = Label(text="", bg="SlateGray2", font=Valstyle)
OctShow.grid(row=8, column=1, padx=5, pady=5, sticky=tkinter.W)


# 按鈕 Click 事件處理函式
def cal():
    Decs = int(DecNum.get())  # Get input value
    h_res = hex(Decs)
    HexShow.config(text=h_res)
    b_res = bin(Decs)
    BnyShow.config(text=b_res)
    o_res = oct(Decs)
    OctShow.config(text=o_res)


# 建立單選按鈕 aBtn ==> addition, sBtn ==> subtraction, mBtn ==> multiplication, dBtn ==> division
ConvBtn = Button(text="Convert", bg="skyblue", command=cal, font=10)
ConvBtn.config(width=7, height=3)
ConvBtn.grid(row=9, column=1)


# 步驟四： 進入事件處理迴圈。
win.mainloop()

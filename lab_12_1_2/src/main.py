from tkinter import *
from tkinter import messagebox
from ctypes import *

#Окно циклического сдвига
def new_window_shift():
    global new_window
    new_window = Toplevel(root)
    new_window.title("Циклический сдвиг")
    new_window.geometry("600x400")
    new_window.configure(bg = "#443848")
 
    global entry
    entry = Entry(new_window, width = 40)
    entry.place(relx = 0.25, rely = 0.20)

    label_1 = Label(new_window, text = "Введите элементы массива через пробел:", bg = "#443848", fg = "#9730db", font = "Arial 15 bold")
    label_1.place(relx = 0.18, rely = 0.10)

    label_2 = Label(new_window, text = "Введите количество сдвигов:", bg = "#443848", fg = "#9730db", font = "Arial 15 bold")
    label_2.place(relx = 0.18, rely = 0.30)

    global entry_1
    entry_1 = Entry(new_window, width = 13)
    entry_1.place(relx = 0.70, rely = 0.30)


    button_3 = Button(new_window, text = "Запуск", 
                        width = 30, height = 2, bg = "#f4a460", 
                        fg = "white", relief = "flat", font = "Arial 10 bold", command = make_shift_array)

    button_3.place(relx = 0.32, rely = 0.60)


#Цикличсекий сдвиг
def make_shift_array():
    tmp = entry.get()
    k = entry_1.get()
    try:
        if (len(tmp) == 0 or not(k.isdigit()) or int(k) < 0):
            messagebox.showerror("Ошибка", "Данные не введены!")
        else:
            tmp = list(map(int ,tmp.split()))
            shift_array(tmp, int(k))
    except ValueError:
        messagebox.showerror("Ошибка", "Данные введены\n         неверно!")
        return


def shift_array(array, k):
    list_len_size_t = c_size_t()
    list_len_size_t.value = k

    k_size_t = c_size_t()
    k_size_t.value = k

    tmp = (c_int * len(array))(*array)
    _shift(tmp, len(array), k)

    tmp = list(tmp)

    label_res = Label(new_window, text = f"Результат: {tmp}", bg = "#443848", fg = "#800000", font = "Arial 12 bold")
    label_res.place(relx = 0.18, rely = 0.4)


#Окно для поиска полных квадратов
def new_window_filter():
    new_window = Toplevel(root)
    new_window.title("Поиск полных квадратов")
    new_window.geometry("600x400")
    new_window.configure(bg = "#443848")

    label_1 = Label(new_window, text = "Введите элементы массива через пробел:", bg = "#443848", fg = "#9730db", font = "Arial 15 bold")
    label_1.place(relx = 0.18, rely = 0.10)

    button_3 = Button(new_window, text = "Оценка макисмального размера", 
                        width = 30, height = 2, bg = "#f4a460", 
                        fg = "white", relief = "flat", font = "Arial 10 bold", command = make_filter_max_memory)

    button_4 = Button(new_window, text = "Двойной вызов функции", 
                        width = 30, height = 2, bg = "#f4a460", 
                        fg = "white", relief = "flat", font = "Arial 10 bold")

    button_3.place(relx = 0.05, rely = 0.60)
    button_4.place(relx = 0.55, rely = 0.60)

    global entry_5
    entry_5 = Entry(new_window, width = 40)
    entry_5.place(relx = 0.25, rely = 0.20)

def make_filter_max_memory():
    tmp = entry_5.get()
    try:
        if (len(tmp) == 0):
            messagebox.showerror("Ошибка", "Данные не введены!")
        else:
            tmp = list(map(int ,tmp.split()))
            filter_array(tmp)
    except ValueError:
        messagebox.showerror("Ошибка", "Данные введены\n         неверно!")
        return

def filter_array(array):
    src = (c_int * len(array))(*array)

    arr_len_size_t = c_size_t()
    arr_len_size_t.value = len(array)

    tmp = (c_int * arr_len_size_t.value)()

    tmp_len_size_t = (arr_len_size_t.value)()

    rc = _filter(src, arr_len_size_t, tmp, tmp_len_size_t)

    print(tmp)
    if rc != 0:
        messagebox.showerror("Ошибка", "Ошибка!")
    else:
        text = "Элемнты не найдены" if len(tmp) == 0 else f"{tmp}"
        label_res = Label(new_window, text = f"Результат: text", bg = "#443848", fg = "#800000", font = "Arial 12 bold")
        label_res.place(relx = 0.18, rely = 0.4)

root = Tk()
root.title("Программа")
root.geometry("600x400")
root.configure(bg = '#443848')

label = Label(text = "Выберите один из\n вариантов:", bg = '#443848', fg = "white", font = "Arial 30 bold")
label.place(relx = 0.22, rely = 0.10)

button_1 = Button(text = "Циклический сдвиг влево", 
                    width = 25, height = 2, bg = "#f4a460", 
                    fg = "white", relief = "flat", font = "Arial 10 bold", command = new_window_shift)

button_2 = Button(text = "Поиск полных квадратов", 
                    width = 25, height = 2, bg = "#f4a460", 
                    fg = "white", relief = "flat", font = "Arial 10 bold", command = new_window_filter)

button_1.place(relx = 0.1, rely = 0.50)
button_2.place(relx = 0.55, rely = 0.50)

libarr = CDLL("libarr.so")

#Подключение библиотеки циклического сдвига
_shift = libarr.shift
_shift.argtypes = (POINTER(c_int), c_size_t, c_size_t)
_shift.restype = None

#подключение библиотеки фильтра(поиск полных квадратов)
_filter = libarr.filter
_filter.argtypes = (POINTER(c_int), c_size_t, POINTER(c_int), POINTER(c_size_t))
_filter.restype = c_int

root.mainloop()



#  array = entry.get()
#     try:
#         if (len(array) == 0):
#             messagebox.showerror("Ошибка", "Данные не введены!")
#         else:
#             array = list(map(int, array.split()))
#             shift_array()
            
#     except ValueError:
#         messagebox.showerror("Ошибка", "Данные введены\n         неверно!")
#         return

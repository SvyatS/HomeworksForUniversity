from random import randint
from time import sleep, time
import os

def gnome(array):
    i, size = 1, N
    while(i < size):
        if(array[i - 1] <= array[i]):
            i += 1
        else:
            array[i - 1], array[i] = array[i], array[i - 1] 
            if(i > 1):
                i -= 1

def insertion(array):
    for i in range(N):
        j = i - 1 
        key = array[i]
        while(array[j] > key and j >= 0):
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
            

def bubble(array):  
    for i in range(N-1):
        for j in range(N-i-1):
            if array[j] > array[j+1]:
                buff = array[j]
                array[j] = array[j+1]
                array[j+1] = buff

N = 10000
a = []
b = []
c = []

for i in range(N):
    a.append(randint(1, 500))
    b.append(a[i])
    c.append(a[i])

startgnome = time()
gnome(a)
endgnome = time()

startbubble = time()
bubble(b)
endbubble = time()

startins = time()
insertion(c)
endins = time()

print("gnome = {0}\nbubble = {1}\ninsertion = {2}\n".format(endgnome - startgnome, endbubble - startbubble, endins - startins))
os.system("PAUSE")


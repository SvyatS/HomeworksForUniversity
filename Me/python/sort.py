import pygame as pg
from random import randint
from time import sleep
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
                sc.fill((10,10,10))
        for k in range(N):
            x0 = k*10
            pg.draw.rect(sc, (2+k*2, 255-k*2, 255), (x0, 700-array[k], 10, 700))
        pg.display.update()


def insertion(array):
    for i in range(N):
        j = i - 1 
        key = array[i]
        while(array[j] > key and j >= 0):
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
        sc.fill((10,10,10))
        for k in range(N):
            x0 = k*10
            pg.draw.rect(sc, (2+k*2, 255-k*2, 255), (x0, 700-array[k], 10, 700))
        pg.display.update()
            

def bubble(array):  
    for i in range(N-1):
        for j in range(N-i-1):
            if array[j] > array[j+1]:
                pg.display.update()
                buff = array[j]
                array[j] = array[j+1]
                array[j+1] = buff
        sc.fill((10,10,10))
        for k in range(N):
            x0 = k*10            
            pg.draw.rect(sc, (2+k*2, 255-k*2, 255), (x0, 700-array[k], 10, 700))
        pg.display.update()

N = 100
a = []
b = []
c = []
for i in range(N):
    a.append(randint(1, 500))
    b.append(randint(1, 500))
    c.append(randint(1, 500))
pg.init()
sc = pg.display.set_mode((1000, 700))
clock = pg.time.Clock()
for i in range(N):
    x = i*10
    pg.draw.rect(sc, (2+i*2, 255-i*2, 255), (x, a[i], 10, 700))
    print(x)
    pg.display.update()
sleep(2)

gnome(a)

sc.fill((10,10,10))
for i in range(N):
    x = i*10
    pg.draw.rect(sc, (2+i*2, 255-i*2, 255), (x, a[i], 10, 700))
    print(x)
    pg.display.update()

sc.fill((10,10,10))
for i in range(N):
    x = i*10
    pg.draw.rect(sc, (2+i*2, 255-i*2, 255), (x, b[i], 10, 700))
    print(x)
    pg.display.update()
sleep(2)

bubble(b)

sc.fill((10,10,10))
for i in range(N):
    x = i*10
    pg.draw.rect(sc, (2+i*2, 255-i*2, 255), (x, b[i], 10, 700))
    print(x)
    pg.display.update()

sc.fill((10,10,10))
for i in range(N):
    x = i*10
    pg.draw.rect(sc, (2+i*2, 255-i*2, 255), (x, c[i], 10, 700))
    print(x)
    pg.display.update()

insertion(c)
sleep(2)

sc.fill((10,10,10))
for i in range(N):
    x = i*10
    pg.draw.rect(sc, (2+i*2, 255-i*2, 255), (x, c[i], 10, 700))
    print(x)
    pg.display.update()
print("all")
os.system("PAUSE")



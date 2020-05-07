from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QLineEdit, QLabel
import sys
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import (NavigationToolbar2QT as NavigationToolbar)
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
import numpy as np
from method import MNK

class Window(QMainWindow):
    def __init__(self):
        super().__init__()

        title = "Метод наименьших квадратов"
        top = 400
        left = 400
        width = 800
        height = 500

        self.setWindowTitle(title)
        self.setGeometry(top, left, width, height)

        self.MyUI()


    def MyUI(self):
        self.labeX = QLabel('X:', self)
        self.labeX.move(25, 10)

        self.labelY = QLabel('Y:', self)
        self.labelY.move(25, 40)

        self.canvas = Canvas(self, width=8, height=4)
        self.canvas.move(0,70)

        button = QPushButton("Применить", self)
        button.move(580, 30)
        button.clicked.connect(self.apply)

        self.lineX = QLineEdit(self)
        self.lineX.move(40, 10)
        self.lineX.resize(500, 25)

        self.lineY = QLineEdit(self)
        self.lineY.move(40, 40)
        self.lineY.resize(500, 25)

    def apply(self):
        strX = self.lineX.text()
        strY = self.lineY.text()
        strX  = strX.split()
        strY  = strY.split()
        x = []
        y = []
        for i in range(len(strX)):
            x.append(int(strX[i]))
            y.append(int(strY[i]))
        y_f, a, b = MNK(x, y)
        self.canvas.axes.clear()
        self.canvas.axes.plot(x, y, color='r', linestyle=' ', marker='o')
        self.canvas.axes.plot(x, y_f)
        function = 'y = '+str(round(a, 3))+'*x+'+str(round(b, 3))
        self.canvas.axes.set_title(function)
        self.canvas.draw()

class Canvas(FigureCanvas):
    def __init__(self, parent = None, width = 5, height = 5, dpi = 100):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)
        self.axes.set_title("function")
        self.axes.set_xlim(0, 10)
        self.axes.set_ylim(0, 10)
        FigureCanvas.__init__(self, fig)
        self.setParent(parent)


app = QApplication(sys.argv)
window = Window()
window.show()

app.exec()

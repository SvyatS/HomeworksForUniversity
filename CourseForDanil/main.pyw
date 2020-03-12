from PySide import QtCore, QtGui
import sys
from GUI import Ui_Form

def f(x, a, b, c):
    return a*x**2+b*x+c

def MPD(f, p, q, a, b, c, eps=1e-5):
    while abs(p - q) > eps:
        x = (p + q) / 2.0
        fx = f(x, a, b, c)
        fa = f(p, a, b, c)
        if (fx < 0 and fa < 0) or (fx > 0 and fa > 0):
            p = x
        else:
            q = x
    return x

app = QtGui.QApplication(sys.argv)

Form = QtGui.QWidget()
ui = Ui_Form()
ui.setupUi(Form)
Form.show()
def Start():
    a = int(ui.lineEdit.text())
    b = int(ui.lineEdit_2.text())
    c = int(ui.lineEdit_3.text())
    p = int(ui.lineEdit_4.text())
    q = int(ui.lineEdit_5.text())
    answer = MPD(f, p, q, a, b, c)
    ui.textBrowser_2.setPlainText("Ответ: \n f(x) = 0 при х = " + str(answer))

ui.pushButton.clicked.connect(Start)

sys.exit(app.exec_())

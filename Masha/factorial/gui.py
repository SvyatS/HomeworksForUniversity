
from PySide2.QtWidgets import QApplication, QWidget
import sys
from myprog import Ui_Form
from alg import factorial

__author__ = "Kytsenko"

class MainWindow(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.ui = Ui_Form()
        self.ui.setupUi(self)
        self.ui.pushButton.clicked.connect(self.rashet)

    def rashet(self):
        self.ui.lineEdit_2.setText(str(factorial(int(self.ui.lineEdit.text()))))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())

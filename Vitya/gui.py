# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'gui.ui'
##
## Created by: Qt User Interface Compiler version 5.14.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QDate, QDateTime, QMetaObject,
    QObject, QPoint, QRect, QSize, QTime, QUrl, Qt)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor, QFont,
    QFontDatabase, QIcon, QKeySequence, QLinearGradient, QPalette, QPainter,
    QPixmap, QRadialGradient)
from PySide2.QtWidgets import *
from alg import *

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(695, 262)
        Form.setMinimumSize(QSize(695, 262))
        Form.setMaximumSize(QSize(695, 262))
        self.label = QLabel(Form)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(10, 0, 651, 21))
        font = QFont()
        font.setPointSize(11)
        self.label.setFont(font)

        self.pushButton = QPushButton(Form)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(20, 200, 121, 51))
        self.pushButton.clicked.connect(self.apply)

        self.textBrowser = QTextBrowser(Form)
        self.textBrowser.setObjectName(u"textBrowser")
        self.textBrowser.setGeometry(QRect(280, 120, 341, 131))
        self.widget = QWidget(Form)
        self.widget.setObjectName(u"widget")
        self.widget.setGeometry(QRect(20, 40, 291, 25))
        self.horizontalLayout = QHBoxLayout(self.widget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.label_2 = QLabel(self.widget)
        self.label_2.setObjectName(u"label_2")
        font1 = QFont()
        font1.setPointSize(14)
        self.label_2.setFont(font1)

        self.horizontalLayout.addWidget(self.label_2)

        self.lineEdit = QLineEdit(self.widget)
        self.lineEdit.setObjectName(u"lineEdit")

        self.horizontalLayout.addWidget(self.lineEdit)

        self.label_3 = QLabel(self.widget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setFont(font1)

        self.horizontalLayout.addWidget(self.label_3)

        self.lineEdit_2 = QLineEdit(self.widget)
        self.lineEdit_2.setObjectName(u"lineEdit_2")

        self.horizontalLayout.addWidget(self.lineEdit_2)

        self.label_4 = QLabel(self.widget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setFont(font1)

        self.horizontalLayout.addWidget(self.label_4)

        self.lineEdit_3 = QLineEdit(self.widget)
        self.lineEdit_3.setObjectName(u"lineEdit_3")

        self.horizontalLayout.addWidget(self.lineEdit_3)

        self.widget1 = QWidget(Form)
        self.widget1.setObjectName(u"widget1")
        self.widget1.setGeometry(QRect(20, 80, 191, 25))
        self.horizontalLayout_2 = QHBoxLayout(self.widget1)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.label_6 = QLabel(self.widget1)
        self.label_6.setObjectName(u"label_6")
        self.label_6.setFont(font1)

        self.horizontalLayout_2.addWidget(self.label_6)

        self.lineEdit_5 = QLineEdit(self.widget1)
        self.lineEdit_5.setObjectName(u"lineEdit_5")

        self.horizontalLayout_2.addWidget(self.lineEdit_5)

        self.label_5 = QLabel(self.widget1)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setFont(font1)

        self.horizontalLayout_2.addWidget(self.label_5)

        self.lineEdit_4 = QLineEdit(self.widget1)
        self.lineEdit_4.setObjectName(u"lineEdit_4")

        self.horizontalLayout_2.addWidget(self.lineEdit_4)

        self.widget2 = QWidget(Form)
        self.widget2.setObjectName(u"widget2")
        self.widget2.setGeometry(QRect(20, 120, 208, 71))
        self.verticalLayout = QVBoxLayout(self.widget2)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.radioButton = QRadioButton(self.widget2)
        self.radioButton.setObjectName(u"radioButton")
        font2 = QFont()
        font2.setPointSize(10)
        self.radioButton.setFont(font2)

        self.verticalLayout.addWidget(self.radioButton)

        self.radioButton_2 = QRadioButton(self.widget2)
        self.radioButton_2.setObjectName(u"radioButton_2")
        self.radioButton_2.setFont(font2)

        self.verticalLayout.addWidget(self.radioButton_2)


        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi
    def apply(self):
        a = int(self.lineEdit.text())
        d = int(self.lineEdit_2.text())
        e = int(self.lineEdit_3.text())
        c = int(self.lineEdit_4.text())
        b = int(self.lineEdit_5.text())
        if(self.radioButton.isChecked()):
            answer = simpson(f, a, d, e, b, c)
        elif(self.radioButton_2.isChecked()):
            answer = LeftRect(f, a, d, e, b, c)
        ans = "Площадь данной функции на данном промежутке = "+ str(round(answer, 4))
        self.textBrowser.setText(ans)

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.label.setText(QCoreApplication.translate("Form", u"\u0444\u0443\u043d\u043a\u0446\u0438\u044f \u0438\u043c\u0435\u0435\u0442 \u0432\u0438\u0434 a*x*x+ d*x + e. \u0412\u0432\u0435\u0434\u0438\u0442\u0435 \u043a\u043e\u044d\u0444\u0444\u0438\u0446\u0438\u0435\u043d\u0442\u044b a, d, e \u0438 \u0442\u0430\u043a\u0436\u0435 \u0433\u0440\u0430\u043d\u0438\u0446\u044b c \u0438 b.", None))
        self.pushButton.setText(QCoreApplication.translate("Form", u"\u0420\u0430\u0441\u0441\u0447\u0438\u0442\u0430\u0442\u044c!", None))
        self.label_2.setText(QCoreApplication.translate("Form", u"a =", None))
        self.label_3.setText(QCoreApplication.translate("Form", u"d =", None))
        self.label_4.setText(QCoreApplication.translate("Form", u"e =", None))
        self.label_6.setText(QCoreApplication.translate("Form", u"b =", None))
        self.label_5.setText(QCoreApplication.translate("Form", u"c = ", None))
        self.radioButton.setText(QCoreApplication.translate("Form", u"\u041c\u0435\u0442\u043e\u0434 \u0421\u0438\u043c\u043f\u0441\u043e\u043d\u0430", None))
        self.radioButton_2.setText(QCoreApplication.translate("Form", u"\u041c\u0435\u0442\u043e\u0434 \u043b\u0435\u0432\u044b\u0445 \u043f\u0440\u044f\u043c\u043e\u0443\u0433\u043e\u043b\u044c\u043d\u0438\u043a\u043e\u0432", None))
    # retranslateUi

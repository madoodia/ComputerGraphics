########################
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
########################

import os
import PySide2
import sys

app = PySide2.QtWidgets.QApplication(sys.argv)

PySide2.QtPushButton = PySide2.QtWidgets.QPushButton()
PySide2.QtPushButton.setText("Hello World")
PySide2.QtPushButton.show()

sys.exit(app.exec_())
# plugins/vaca.py

from registry import registrar

class Vaca:
    def hablar(self):
        print("muuu")

# AUTO-REGISTRO
registrar("vaca", Vaca)
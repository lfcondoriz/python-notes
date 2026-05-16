# plugins/perro.py

from registry import registrar

class Perro:
    def hablar(self):
        print("guau")

# AUTO-REGISTRO
registrar("perro", Perro)
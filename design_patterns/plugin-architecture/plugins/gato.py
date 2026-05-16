# plugins/gato.py

from registry import registrar

class Gato:
    def hablar(self):
        print("miau")

# AUTO-REGISTRO
registrar("gato", Gato)
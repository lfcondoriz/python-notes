# main.py

# IMPORTS
import plugins.perro
import plugins.gato
import plugins.vaca

from registry import ANIMALES

print("Registro:")
print(ANIMALES)

print()

# Crear objetos dinámicamente
PerroClass = ANIMALES["perro"]
GatoClass = ANIMALES["gato"]
VacaClass = ANIMALES["vaca"]

perro = PerroClass()
gato = GatoClass()
vaca = VacaClass()

perro.hablar()
gato.hablar()
vaca.hablar()
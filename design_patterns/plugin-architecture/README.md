# Plugin Architecture en Python

Ejemplo simple de:

- plugin architecture
- auto-registration
- import side effects
- dynamic module loading
- Open/Closed Principle (OCP)

## Idea

Los módulos se registran automáticamente al importarse.

Cada plugin agrega una clase al registry global sin modificar el código principal.

## Estructura

```text
plugin-architecture/
├── main.py
├── registry.py
└── plugins/
    ├── perro.py
    └── gato.py
```

## Ejemplo

```python
# main.py

import pkgutil
import importlib
import plugins

from registry import ANIMALES

# DESCUBRIR E IMPORTAR TODOS LOS PLUGINS
for _, nombre_modulo, _ in pkgutil.iter_modules(plugins.__path__):
    importlib.import_module(f"plugins.{nombre_modulo}")

print("REGISTRO:")
print(ANIMALES)

print()

# USAR LOS PLUGINS DINÁMICAMENTE
for nombre, Clase in ANIMALES.items():
    animal = Clase()

    print(f"{nombre} -> ", end="")
    animal.hablar()
```

## Conceptos importantes

### Import side effects

En Python, importar un módulo ejecuta su código.

Eso permite auto-registro dinámico.

---

### Open/Closed Principle

El sistema puede extenderse agregando nuevos plugins sin modificar el core.

Por ejemplo:

```text
plugins/vaca.py
```

---

### Dynamic discovery

Opcionalmente los plugins pueden descubrirse automáticamente usando:

```python
pkgutil.iter_modules()
importlib.import_module()
```

---

## Tradeoff

Aunque el auto-discovery es flexible, también agrega complejidad y hace el flujo menos explícito.

En sistemas pequeños suele preferirse imports explícitos.

En frameworks y arquitecturas extensibles se usa muchísimo.

````

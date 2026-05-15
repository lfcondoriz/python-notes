# Diseño de Patrones en Python: ¿Cuáles siguen siendo relevantes?

> 🧠 Muchos patrones clásicos de GoF (C++/Java) existen porque esos lenguajes son más rígidos.
> En Python varios se “disuelven” porque el lenguaje ya te da mecanismos más flexibles.

---

# 🧠 1. Singleton → reemplazado por módulos

## C++/Java

* necesitas clase
* `getInstance()`
* control de construcción

## Python

* un módulo ES el singleton

```python
# config.py
value = 10
```

✔ Importado una vez
✔ Estado global natural

---

# 🏭 2. Factory Method → reemplazado por funciones/dicts/clases

## C++

* clases factory
* interfaces
* polimorfismo

## Python

```python
factories = {
    "email": Email,
    "sms": SMS
}

obj = factories["email"]()
```

✔ sin clases adicionales
✔ sin jerarquías obligatorias

---

# 🏗️ 3. Abstract Factory → reemplazado por composición directa

## C++

* familia de factories
* interfaces múltiples
* jerarquías

## Python

```python
def get_ui(os):
    return WindowsButton() if os == "win" else MacButton()
```

✔ selección directa
✔ sin “familias formales”

---

# 🎭 4. Strategy Pattern → reemplazado por funciones

## C++

* interfaz Strategy
* clases concretas

## Python

```python
def fast():
    return "fast"

def slow():
    return "slow"

strategy = fast
strategy()
```

✔ funciones son estrategias
✔ no necesitas clases

---

# 🔁 5. Command Pattern → reemplazado por callables

## C++

* objeto Command con `execute()`

## Python

```python
def command():
    print("acción")

command()
```

o incluso:

```python
commands = [lambda: print("A"), lambda: print("B")]
```

✔ funciones = comandos

---

# 🧱 6. Builder Pattern → reemplazado por objetos + kwargs

## C++

* Builder clase
* pasos de construcción

## Python

```python
obj = User(name="Ana", age=30, city="BA")
```

✔ `kwargs` reemplaza builder
✔ defaults hacen el resto

---

# 🔌 7. Adapter Pattern → muchas veces innecesario

## C++

* clases wrapper

## Python

```python
def adapt(api_response):
    return api_response["data"]
```

✔ función simple
✔ transformación directa

---

# 👀 8. Decorator Pattern → reemplazado por decorators nativos

## C++

* wrapper classes

## Python

```python
def log(func):
    def wrapper(*args, **kwargs):
        print("antes")
        return func(*args, **kwargs)
    return wrapper
```

✔ lenguaje ya lo soporta (`@decorator`)

---

# 🧠 9. Iterator Pattern → ya viene en el lenguaje

## C++

* implementar `begin()/end()`

## Python

```python
for x in lista:
    print(x)
```

✔ iterables nativos
✔ protocolo interno automático

---

# 🔄 10. Observer Pattern → reemplazado por callbacks / eventos

## C++

* interfaces observer
* listas de suscriptores

## Python

```python
callbacks = []

def subscribe(fn):
    callbacks.append(fn)

def notify():
    for fn in callbacks:
        fn()
```

✔ funciones = observadores

---

# ⚡ RESUMEN GENERAL

## 🟦 En C++/Java:

* patrones son NECESARIOS
* compensan limitaciones del lenguaje
* mucha estructura obligatoria

---

## 🐍 En Python:

* muchos patrones se vuelven:

  * funciones
  * módulos
  * diccionarios
  * objetos simples
  * features del lenguaje

---

# 🧠 IDEA MÁS IMPORTANTE

> Los patrones en Python no desaparecen — se vuelven más simples porque el lenguaje ya resuelve el problema base.

---

# 🚀 REGLA PRÁCTICA

✔ Si necesitas una clase para implementar un patrón en Python, pregúntate:

> “¿esto ya lo resuelve una función o un módulo?”

---

# 🔥 CONCLUSIÓN FINAL

Python no elimina patrones, los **absorbe en el lenguaje**:

* Singleton → módulos
* Factory → dicts/funciones
* Strategy → funciones
* Command → callables
* Iterator → built-in
* Decorator → syntax del lenguaje

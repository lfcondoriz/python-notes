# Factory Method
El Factory Method es un patrón donde:

> 🔥 En vez de crear objetos directamente con new, delegás la creación a una “fábrica”.

Esto sirve cuando:
- no querés acoplarte a clases concretas
- querés decidir qué clase crear en runtime
- querés extender sin modificar código existente

- c++
    ```c++
    c++ design_patterns/factory-method/c++.cpp -o main
    ./main
    ```
- python
    ```python
    python design_patterns/factory-method/python.py
    ```
    
# 🟦 Ejemplo en C++ (Factory Method realista)

## 🎯 Caso: sistema de notificaciones

Queremos enviar:

* Email
* SMS
* Push notification

---

## 🔧 Producto base

```cpp id="cpp_product"
class Notification {
public:
    virtual void send(const std::string& msg) = 0;
    virtual ~Notification() = default;
};
```

---

## 📧 Implementaciones concretas

```cpp id="cpp_email"
class EmailNotification : public Notification {
public:
    void send(const std::string& msg) override {
        std::cout << "Email: " << msg << std::endl;
    }
};
```

```cpp id="cpp_sms"
class SMSNotification : public Notification {
public:
    void send(const std::string& msg) override {
        std::cout << "SMS: " << msg << std::endl;
    }
};
```

---

## 🏭 Factory Method

```cpp id="cpp_factory"
class NotificationFactory {
public:
    static Notification* create(const std::string& type) {
        if (type == "email") return new EmailNotification();
        if (type == "sms") return new SMSNotification();
        return nullptr;
    }
};
```

---

## 🧪 Uso

```cpp id="cpp_main"
int main() {
    Notification* n1 = NotificationFactory::create("email");
    Notification* n2 = NotificationFactory::create("sms");

    n1->send("Hola Email");
    n2->send("Hola SMS");

    delete n1;
    delete n2;
}
```

---

# 🧠 Problema que resuelve en C++

✔ evita `new EmailNotification()` por todos lados
✔ desacopla creación del uso
✔ permite agregar tipos nuevos sin cambiar lógica principal

---

# 🐍 2. Python (versión “equivalente C++” con Factory explícito)

```python id="py_factory_explicit"
class EmailNotification:
    def send(self, msg):
        print(f"Email: {msg}")


class SMSNotification:
    def send(self, msg):
        print(f"SMS: {msg}")


class NotificationFactory:
    @staticmethod
    def create(type_):
        if type_ == "email":
            return EmailNotification()
        elif type_ == "sms":
            return SMSNotification()
        else:
            raise ValueError("Tipo desconocido")
```

---

## 🧪 Uso

```python id="py_factory_main"
n1 = NotificationFactory.create("email")
n2 = NotificationFactory.create("sms")

n1.send("Hola Email")
n2.send("Hola SMS")
```

---

# ⚖️ 3. La parte IMPORTANTE: cómo se simplifica en Python

En Python, muchas veces NO necesitas una Factory explícita.

---

## 🐍 Forma pythonica (SIN Factory)

```python id="py_direct_map"
class EmailNotification:
    def send(self, msg):
        print(f"Email: {msg}")


class SMSNotification:
    def send(self, msg):
        print(f"SMS: {msg}")


factory = {
    "email": EmailNotification,
    "sms": SMSNotification
}


def create(type_):
    return factory[type_]()
```

---

## 🧪 Uso

```python id="py_simple_factory"
n = create("email")
n.send("Hola")
```

---

# 🚀 4. Forma MÁS pythonica (sin Factory del todo)

```python id="py_no_factory"
class EmailNotification:
    def send(self, msg):
        print(f"Email: {msg}")


class SMSNotification:
    def send(self, msg):
        print(f"SMS: {msg}")


def send_notification(cls, msg):
    cls().send(msg)


send_notification(EmailNotification, "Hola Email")
```

---

# ⚖️ Comparación clave C++ vs Python

| Concepto             | C++             | Python               |
| -------------------- | --------------- | -------------------- |
| Creación de objetos  | `new` explícito | simple instanciación |
| Factory Method       | muy usado       | opcional             |
| Extensibilidad       | importante      | natural              |
| Flexibilidad runtime | media           | alta                 |
| Código necesario     | alto            | bajo                 |

---

# 🧠 5. Conclusión conceptual (lo más importante)

## 🟦 C++

> Factory Method = herramienta estructural necesaria para desacoplar creación

## 🐍 Python

> Factory Method = a menudo innecesario porque:

* puedes pasar clases como objetos
* puedes usar diccionarios
* el lenguaje es dinámico

---

# 🔥 IDEA CLAVE

> En C++ diseñás cómo se crean los objetos
> En Python muchas veces simplemente los pasás como valores

---

# 🧩 RESUMEN FINAL

✔ Factory Method en C++ = patrón esencial
✔ Factory Method en Python = opcional
✔ Python lo reemplaza con:

* diccionarios
* funciones
* clases como objetos
* instanciación directa


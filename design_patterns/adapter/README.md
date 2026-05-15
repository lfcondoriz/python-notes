# Adapter (Adaptador)
El patrón Adapter (Adaptador) se usa cuando tienes dos interfaces incompatibles y quieres hacerlas trabajar juntas sin modificar su código.

La idea es “traducir” una interfaz a otra.

## Con C++: Ejemplo más real: API de pagos

Imagina:

* Tu app usa `pay(double amount)`
* Una librería externa usa `makePayment(int cents)`

```cpp
class PaymentProcessor {
public:
    virtual void pay(double amount) = 0;
};
```

Librería externa:

```cpp
class LegacyPaymentSystem {
public:
    void makePayment(int cents) {
        cout << "Pagando " << cents << " centavos" << endl;
    }
};
```

Adapter:

```cpp
class PaymentAdapter : public PaymentProcessor {
private:
    LegacyPaymentSystem* legacy;

public:
    PaymentAdapter(LegacyPaymentSystem* l) : legacy(l) {}

    void pay(double amount) override {
        int cents = static_cast<int>(amount * 100);
        legacy->makePayment(cents);
    }
};
```

Uso:

```cpp
LegacyPaymentSystem legacy;
PaymentProcessor* payment = new PaymentAdapter(&legacy);

payment->pay(10.50); // convierte a 1050 centavos
```

---

## 🧠 Resumen mental rápido

Piensa en Adapter como:

> “Un traductor entre dos clases que no se entienden”

## Con python
¿se usa o no se usa en Python?

- ✔ Sí se usa cuando:
    - integras APIs externas incompatibles
    - trabajas con librerías legacy
    - necesitas arquitectura limpia o DDD
    - quieres testabilidad (mocking/adapters ayudan mucho)

- ❌ Se evita cuando:
    - basta una función simple
    - el sistema ya es flexible por duck typing
    - el “overengineering” sería mayor que el beneficio

### 🧠 Ejemplo en Python (versión “clásica” de Adapter)

Tu mismo caso del pago:

```python
class LegacyPaymentSystem:
    def make_payment(self, cents: int):
        print(f"Pagando {cents} centavos")
```

Interfaz esperada por tu sistema:

```python
class PaymentProcessor:
    def pay(self, amount: float):
        raise NotImplementedError
```

Adapter:

```python
class PaymentAdapter(PaymentProcessor):
    def __init__(self, legacy_system: LegacyPaymentSystem):
        self.legacy = legacy_system

    def pay(self, amount: float):
        cents = int(amount * 100)
        self.legacy.make_payment(cents)
```

Uso:

```python
legacy = LegacyPaymentSystem()
payment = PaymentAdapter(legacy)

payment.pay(10.50)
```

✔ Esto es el patrón Adapter “formal”, igual que en C++.

---

### 🐍 Versión Pythonic (sin patrón explícito)

Aquí es donde Python cambia el juego.

#### Opción 1: función wrapper (lo más común)

```python
def make_payment_adapter(legacy_system, amount):
    cents = int(amount * 100)
    legacy_system.make_payment(cents)
```

Uso:

```python
legacy = LegacyPaymentSystem()
make_payment_adapter(legacy, 10.50)
```

👉 Esto muchas veces reemplaza completamente el patrón.

---

#### Opción 2: simplemente “duck typing”

Si el código solo necesita algo que tenga `make_payment`, puedes no adaptar nada:

```python
class NewPaymentSystem:
    def make_payment(self, cents):
        print("Nuevo sistema:", cents)
```

Y el sistema simplemente funciona con ambos.

---

#### Opción 3: composición ligera

```python
class PaymentAdapter:
    def __init__(self, legacy):
        self.legacy = legacy

    def pay(self, amount):
        self.legacy.make_payment(int(amount * 100))
```

Sin interfaces, sin abstracciones obligatorias.

---

## ⚖️ Conclusión clara

> En C++ el Adapter es estructural y necesario
>
> En Python el Adapter es opcional y muchas veces “implícito”


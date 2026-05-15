#include <iostream>
using namespace std;

class PaymentProcessor {
public:
    virtual void pay(double amount) = 0;
};

class LegacyPaymentSystem {
public:
    void makePayment(int cents) {
        cout << "Pagando " << cents << " centavos" << endl;
    }
};

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

int main() {
    LegacyPaymentSystem legacySystem;
    PaymentAdapter adapter(&legacySystem);

    adapter.pay(19.99); // Pagando 1999 centavos

    return 0;
}
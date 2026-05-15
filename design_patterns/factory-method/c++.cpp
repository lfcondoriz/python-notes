#include <iostream>
#include <string>

class Notification {
public:
    virtual void send(const std::string& msg) = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const std::string& msg) override {
        std::cout << "Email: " << msg << std::endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const std::string& msg) override {
        std::cout << "SMS: " << msg << std::endl;
    }
};

class NotificationFactory {
public:
    static Notification* create(const std::string& type) {
        if (type == "email") return new EmailNotification();
        if (type == "sms") return new SMSNotification();
        return nullptr;
    }
};

int main() {
    Notification* n1 = NotificationFactory::create("email");
    Notification* n2 = NotificationFactory::create("sms");

    n1->send("Hola Email");
    n2->send("Hola SMS");

    delete n1;
    delete n2;
}
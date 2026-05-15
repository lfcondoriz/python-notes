# 🐍 Forma pythonica (SIN Factory)
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

# ============================================================================
# DEMOSTRACIÓN
# ============================================================================
if __name__ == "__main__":
    email_notif = create("email")
    sms_notif = create("sms")

    email_notif.send("Hola por email!")
    sms_notif.send("Hola por SMS!")
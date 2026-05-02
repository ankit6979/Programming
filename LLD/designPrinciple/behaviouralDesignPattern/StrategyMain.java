// Without stragegy pattern, the code for processing payments might look like this:
// public class PaymentProcessor {
//     public void processPymanet(String paymentMethod, double amount) {
//         if (paymentMethod.equals("CreditCard")) {
//             // Process credit card payment
//         } else if (paymentMethod.equals("PayPal")) {
//             // Process PayPal payment
//         } else if (paymentMethod.equals("Bitcoin")) {
//             // Process Bitcoin payment
//         }
//     }
// }

// Method2 - with strategy pattern, we can define a common interface for payment processing and implement different strategies for each payment method:
// public interface PaymentStrategy {
//     void processPayment(double amount);
// }

// public class CreditCardPayment implements PaymentStrategy {
//     @Override
//     public void processPayment(double amount) {
//         // Process credit card payment
//     }
// }

// public class PayPalPayment implements PaymentStrategy {
//     @Override
//     public void processPayment(double amount) {
//         // Process PayPal payment
//     }
// }

// public class BitcoinPayment implements PaymentStrategy {
//     @Override
//     public void processPayment(double amount) {
//         // Process Bitcoin payment
//     }
// }

// public class PaymentProcessor {
//     public void processPymanet(String paymentMethod, double amount) {
//         if (paymentMethod.equals("CreditCard")) {
//             // Process credit card payment
//         } else if (paymentMethod.equals("PayPal")) {
//             // Process PayPal payment
//         } else if (paymentMethod.equals("Bitcoin")) {
//             // Process Bitcoin payment
//         }
//     }
// }


// Method3
interface PaymentStrategy {
    void processPayment(double amount);
}

class CreditCardPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        // Process credit card payment
    }
}

class PayPalPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        // Process PayPal payment
    }
}

class BitcoinPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        // Process Bitcoin payment
    }
}

class PaymentProcessor {
    private final PaymentStrategy paymentStrategy;

    public PaymentProcessor(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    public void processPayment(double amount) {
        if (paymentStrategy != null) {
            paymentStrategy.processPayment(amount);
        } else {
            throw new IllegalStateException("Payment strategy not set");
        }
    }
}

public class StrategyMain {
    public static void main(String[] args) {
        PaymentStrategy creditCardPayment = new CreditCardPayment();
        PaymentProcessor paymentProcessor = new PaymentProcessor(creditCardPayment);
        paymentProcessor.processPayment(100.0);

        PaymentStrategy payPalPayment = new PayPalPayment();
        paymentProcessor = new PaymentProcessor(payPalPayment);
        paymentProcessor.processPayment(200.0);

        PaymentStrategy bitcoinPayment = new BitcoinPayment();
        paymentProcessor = new PaymentProcessor(bitcoinPayment);
        paymentProcessor.processPayment(300.0);
    }
}

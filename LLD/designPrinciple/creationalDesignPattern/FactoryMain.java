// Traditional approach
interface Vehicle {
    void start();
    void stop();
}

//car.java
class Car implements Vehicle {
    @Override
    public void start() {
        System.out.println("Car is starting");
    }

    @Override
    public void stop() {
        System.out.println("Car is stopping");
    }
}

//Truck.java
class Truck implements Vehicle {
    @Override
    public void start() {
        System.out.println("Truck is starting");
    }

    @Override
    public void stop() {
        System.out.println("Truck is stopping");
    }
}

// public class Main {
//     public static void main(String[] args) {
//         Vehicle vehicle1 = new Car();
//         vehicle1.start();
//         vehicle1.stop();

//         Vehicle vehicle2 = new Truck();
//         vehicle2.start();
//         vehicle2.stop();
//     }
// }

// Using factory design pattern
// Vehicle factory

class VehicleFactory {
    public static Vehicle getVehicle(String vehicleType) {
        if (vehicleType.equals("Car")) {
            return new Car();
        }
        if (vehicleType.equals("Truck")) {
            return new Truck();
        }
        else {
            throw new IllegalArgumentException("Unkown vehicle type");
        }
    }
}

public class FactoryMain {
    public static void main(String[] args) {
        Vehicle vehicle1 = VehicleFactory.getVehicle("Car");
        vehicle1.start();
        vehicle1.stop();

        Vehicle vehicle2 = VehicleFactory.getVehicle("Truck");
        vehicle2.start();
        vehicle2.stop();
    }
}

/* With extra methods*/
// interface Vehicle {
//     void start();
//     void stop();
// }

// interface Convertible {
//     void openSunroof();
// }

// class Car implements Vehicle, Convertible {
//     @Override
//     public void start() {
//         System.out.println("Car is starting");
//     }

//     @Override
//     public void stop() {
//         System.out.println("Car is stopping");
//     }

//     @Override
//     public void openSunroof() {
//         System.out.println("Car's sunroof is opening");
//     }
// }

// class Truck implements Vehicle {
//     @Override
//     public void start() {
//         System.out.println("Truck is starting");
//     }

//     @Override
//     public void stop() {
//         System.out.println("Truck is stopping");
//     }
// }

// class VehicleFactory {
//     public static Vehicle getVehicle(String vehicleType) {
//         if (vehicleType.equalsIgnoreCase("Car")) {
//             return new Car();
//         } else if (vehicleType.equalsIgnoreCase("Truck")) {
//             return new Truck();
//         } else {
//             throw new IllegalArgumentException("Unknown vehicle type: " + vehicleType);
//         }
//     }
// }

// public class FactoryMain {
//     public static void main(String[] args) {
//         Vehicle vehicle1 = VehicleFactory.getVehicle("Car");
//         vehicle1.start();
//         vehicle1.stop();

//         // If the vehicle supports Convertible features
//         if (vehicle1 instanceof Convertible) {
//             Convertible convertible = (Convertible) vehicle1;
//             convertible.openSunroof();
//         }

//         Vehicle vehicle2 = VehicleFactory.getVehicle("Truck");
//         vehicle2.start();
//         vehicle2.stop();

//         // Truck doesn't implement Convertible, so no casting done here
//     }
// }

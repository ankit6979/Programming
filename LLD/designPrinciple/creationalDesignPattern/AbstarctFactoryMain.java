interface Vehicle {
    public void start();
    public void stop();
}

class Honda implements Vehicle {
    @Override
    public void start() {
        System.out.println("Starting Honda");
    }

    @Override
    public void stop() {
        System.out.println("Stopping Honda");
    }
}

class Toyota implements Vehicle {
    @Override
    public void start() {
        System.out.println("Starting Toyota");
    }

    @Override
    public void stop() {
        System.out.println("Stopping Toyota");
    }
}

class BMW implements Vehicle {
    @Override
    public void start() {
        System.out.println("Starting BMW");
    }

    @Override
    public void stop() {
        System.out.println("Stopping BMW");
    }
}

interface VehicleFactory {
    Vehicle createVehicle();
}


class HondaFactory implements VehicleFactory{
    @Override
    public Vehicle createVehicle() {
        return new Honda();
    }
}

class ToyotaFactory implements VehicleFactory{
    @Override
    public Vehicle createVehicle() {
        return new Toyota();
    }
}

class BMWFactory implements VehicleFactory{
    @Override
    public Vehicle createVehicle() {
        return new BMW();
    }
}

public class AbstarctFactoryMain {
    public static void main(String[] args) {
        VehicleFactory hondaFactory = new HondaFactory();
        Vehicle honda = hondaFactory.createVehicle();
        honda.start();
        honda.stop();

        VehicleFactory ToyoyaFactory = new ToyotaFactory();
        Vehicle toyota = ToyoyaFactory.createVehicle();
        toyota.start();
        toyota.stop();

        VehicleFactory BMWFactory = new BMWFactory();
        Vehicle bmw = BMWFactory.createVehicle();
        bmw.start();
        bmw.stop();
    } 
}

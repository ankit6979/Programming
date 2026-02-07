
class Car {
    private final String engine;
    private final int wheel;
    private final int seat;
    private final String color;
    private final boolean sunroof;
    private final boolean navigationSystem;

    private Car(CarBuilder builder) {
        this.engine = builder.engine;
        this.wheel = builder.wheel;
        this.seat = builder.seat;
        this.color = builder.color;
        this.sunroof = builder.sunroof;
        this.navigationSystem = builder.navigationSystem;
    }

    public String getEngine() {
        return engine;
    }

    public int getWheel() {
        return wheel;
    }

    public int getSeat() {
        return seat;
    }

    public String getColor() {
        return color;
    }

    public boolean getSunroof() {
        return sunroof;
    }

    public boolean getNavigationSystem() {
        return navigationSystem;
    }

    @Override
    public String toString() {
        return "Car [engine = " + engine + ", wheels = " + wheel + ", seats = " + seat + ", color = " + color
                + ", sunroof = " + sunroof + ", navigation system = " + navigationSystem + "]";
    }

    public static class CarBuilder {
        private String engine;
        private int wheel = 4;
        private int seat = 5;
        private String color = "black";
        private boolean sunroof = false;
        private boolean navigationSystem = true;

        public CarBuilder setEngine(String engine) {
            this.engine = engine;
            return this;
        }

        public CarBuilder setWheel(int wheel) {
            this.wheel = wheel;
            return this;
        }

        public CarBuilder setSeat(int seat) {
            this.seat = seat;
            return this;
        }

        public CarBuilder setColor(String color) {
            this.color = color;
            return this;
        }

        public CarBuilder setSunroof(boolean sunroof) {
            this.sunroof = sunroof;
            return this;
        }

        public CarBuilder setNavigationSystem(boolean navigationSystem) {
            this.navigationSystem = navigationSystem;
            return this;
        }

        public Car build() {
            return new Car(this);
        }
    }
}

public class BuilderClassMain {
    public static void main (String [] args) {
        Car.CarBuilder builder = new Car.CarBuilder();
        Car car1 = builder.setEngine("V8")
                    .setColor("blue")
                    .setSeat(8)
                    .setSunroof(true)
                    .setNavigationSystem(false)
                    .build();
        
        System.out.println(car1);

        Car car2 = builder.setEngine("V6")
                    .setColor("red")
                    .setSeat(6)
                    .setSunroof(false)
                    .setNavigationSystem(true)
                    .build();
        
        System.out.println(car2);
    }
     
}
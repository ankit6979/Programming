interface TrafficLightState {
    void next(TrafficLightContext context);
    String getColor();
}

class RedState implements TrafficLightState {
    @Override
    public void next(TrafficLightContext context) {
        context.setState(new GreenState());
    }

    @Override
    public String getColor() {
        return "Red";
    }
}

class GreenState implements TrafficLightState {
    @Override
    public void next(TrafficLightContext context) {
        context.setState(new YellowState());
    }

    @Override
    public String getColor() {
        return "Green";
    }
}

class YellowState implements TrafficLightState {
    @Override
    public void next(TrafficLightContext context) {
        context.setState(new RedState());
    }

    @Override
    public String getColor() {
        return "Yellow";
    }
}

class TrafficLightContext {
    private TrafficLightState state;

    public TrafficLightContext() {
        this.state = new RedState(); // Initial state
    }

    public void setState(TrafficLightState state) {
        this.state = state;
    }

    public void change() {
        state.next(this);
    }

    public String getCurrentColor() {
        return state.getColor();
    }
}

public class StateMain {
    public static void main(String[] args) {
        TrafficLightContext trafficLight = new TrafficLightContext();

        for (int i = 0; i < 6; i++) {
            System.out.println("Current Traffic Light: " + trafficLight.getCurrentColor());
            trafficLight.change();
        }
    }
}

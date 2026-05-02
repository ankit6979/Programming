abstract class Beverage {
    // template method to make sure the steps are followed in order
    final void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    // abstract methods to be implemented by subclasses
    abstract void brew();
    abstract void addCondiments();

    // common methods
    private void boilWater() {
        System.out.println("Boiling water");
    }

    private void pourInCup() {
        System.out.println("Pouring into cup");
    }
}

class Coffee extends Beverage {
    @Override
    void brew() {
        System.out.println("Dripping Coffee through filter");
    }

    @Override
    void addCondiments() {
        System.out.println("Adding Sugar and Milk");
    }
}

class Tea extends Beverage {
    @Override
    void brew() {
        System.out.println("Steeping the tea");
    }

    @Override
    void addCondiments() {
        System.out.println("Adding Lemon");
    }
}

public class TemplateMain {
    public static void main(String[] args) {
        Beverage coffee = new Coffee();
        Beverage tea = new Tea();

        System.out.println("Making Coffee:");
        coffee.prepareRecipe();

        System.out.println("\nMaking Tea:");
        tea.prepareRecipe();
    }
}

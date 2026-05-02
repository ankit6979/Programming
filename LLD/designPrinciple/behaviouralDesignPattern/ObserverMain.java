interface Subscriber {
    void update(String message);
}

class YouTubeSubscriber implements Subscriber {
    private final String name;

    public YouTubeSubscriber(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println(name + " received notification: " + message);
    }
}

class EmailSubscriber implements Subscriber {
    private final String email;

    public EmailSubscriber(String email) {
        this.email = email;
    }

    @Override
    public void update(String message) {
        System.out.println("Email sent to " + email + ": " + message);
    }
}

class PushNotificationSubscriber implements Subscriber {
    private final String deviceId;

    public PushNotificationSubscriber(String deviceId) {
        this.deviceId = deviceId;
    }

    @Override
    public void update(String message) {
        System.out.println("Push notification sent to device " + deviceId + ": " + message);
    }
}

interface YoutubeChannel {
    void subscribe(Subscriber subscriber);
    void unsubscribe(Subscriber subscriber);
    void notifySubscribers(String message);
}

class TechChannel implements YoutubeChannel {
    private List<Subscriber> subscribers = new ArrayList<>();

    @Override
    public void subscribe(Subscriber subscriber) {
        subscribers.add(subscriber);
    }

    @Override
    public void unsubscribe(Subscriber subscriber) {
        subscribers.remove(subscriber);
    }

    @Override
    public void notifySubscribers(String message) {
        for (Subscriber subscriber : subscribers) {
            subscriber.update(message);
        }
    }
}
public class ObserverMain {
    public static void main(String[] args) {
        TechChannel techChannel = new TechChannel();

        Subscriber subscriber1 = new YouTubeSubscriber("Alice");
        Subscriber subscriber2 = new EmailSubscriber("bob@example.com");
        Subscriber subscriber3 = new PushNotificationSubscriber("device123");

        techChannel.subscribe(subscriber1);
        techChannel.subscribe(subscriber2);
        techChannel.subscribe(subscriber3);

        techChannel.notifySubscribers("New video uploaded!");
    }
}

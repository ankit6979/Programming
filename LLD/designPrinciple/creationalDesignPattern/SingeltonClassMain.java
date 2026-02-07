class Logger {
    private static Logger logger = null;
    private Logger () {};

    public static Logger getLogger () {
        if (logger == null) {
            logger = new Logger();
        }

        return logger;
    }

    public void log (String message) {
        System.out.println("Log: " + message);
    }

}

class ThreadSafeLogger {
    private static volatile ThreadSafeLogger logger = null;
    private ThreadSafeLogger () {};

    @SuppressWarnings("DoubleCheckedLocking")
    public static ThreadSafeLogger getLogger () {
        if (logger == null) {
            synchronized (ThreadSafeLogger.class) {
            if (logger == null) {
                ThreadSafeLogger.logger = logger = new ThreadSafeLogger();
            }
            }
            
        }

        return logger;
    }

    public void log (String message) {
        System.out.println("Log: " + message);
    }

}

public class SingeltonClassMain {
    public static void main(String [] args) {
        Logger logger = Logger.getLogger();
        logger.log("Hi there");
    }
}

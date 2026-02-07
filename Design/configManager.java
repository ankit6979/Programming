// Imagine you’re building a Configuration Management System for internal services.

// Different services need access to config values such as feature flags, DB connection limits, or API rate limits.

// Some services want to be notified when a config changes.
// Some services want to be notified immediately when config changes.
// Some services want to be notified no more than X times in a minute. But they definitely want to get the latest value in the next minute.
// Others prefer to fetch the latest values on demand.
// Additionally, certain config values may require extra processing before use -
// for example, a password might need decryption, or a numeric value might need validation or fallback defaults.

// How would you design such a system? Describe the core classes, interactions, and how you’d keep it extensible for future needs.
// Also consider thread safety.

// Example Flow:
// 1. Service A subscribes to "db.password" with immediate push mode.
// 2. Service B subscribes to "search.min_length" with a push mode of 3 updates per minute.
// 3. "db.password" is stored encrypted; which should be decrypted before a service uses it.
// 4. "search.min_length" might be empty and a service should be able to get a default value in that case.

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public abstract class Data {
    Map<String, ConfigurationManager> map = new HashMap<>();   
}

public interface Check {
    public boolean check();
}

public class RangeCheck implements Check {
    public Configuration config;
    public void RangeCheck() {
        //
    }
    
    @Override
    public boolean Check(Configuration config) {
        this.config = config;
        // checks on top of it
        if(true) {
            return true;
        }
        else {
            return false;
        }
    }
}

public interface Transformation {
    public Configuration transformation();
}

public class Transformation2 implements Transformation {
    public void Transformation2 (Transformation currentTransformation) {
        // some other transaformation
    }
}

public class Decrypt implements Transformation {
    public Configuration config;
    public defaultVal = "";
    public void Transformation() {
        this.defaultVal = defaultVal;
        return;
    }
    
    @Override
    public Configuration transformation(Configuration config) {
        this.config = config;
        // do transaformation
        if(defaultVal != "") {
            Transformation2(this);
        }
        return config;
        
    }
}

public interface ConfigurationManager {
    public void readConfig();
    public void updateConfig();
}

public class serviceAConfiguration implements ConfigurationManager{
    public void serviceAConfiguration() {
        //
    }
    
    @Override
    public ConfigurationManager readConfig(Configuration config) {
        Configuration readConfig = Data.map[config.type];
        if (readConfig.check(readConfig)) {
            transformedreadConfig = readConfig.transaformation(readConfig)l
            return transformedreadConfig;
        }
        else {
            System.out.println("Checks failed");
        }
        
    }
    
    @Override
    public void updateConfig(Configuration config) {
        Data.map[config.type] = config;
    }
}

public class Configuration {
    public String configType;
    public String configValue;
    public Transformation transaformation;
    public Check check;
    public ConfigurationManager service;
    
    public void Configuration (String configType, String configValue, Transformation transaformation, Check check, ConfigurationManager service) {
        this.configType = configType;
        this.configValue = configValue;
        this.transaformation = transaformation;
        this.check = check;
        this.service = service;
    }
    
    public ConfigurationManager readConfig() {
        service.readConfig();
    }
    
    public void updateConfig() {
        service.updateConfig();
    }
}


public class Solution {
    Transformation decryptTransformation = new Decrypt();
    Check rangeCheck = new Check();
    Configuration serviceAConfig = new Configuration("serviceA", "password", decryptTransformation, rangeCheck, this);
    

    static int addNumbers(int a, int b) {
        return a+b; 
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a;
        a = in.nextInt();
        int b;
        b = in.nextInt();
        int sum;

        sum = addNumbers(a, b);
        System.out.println(sum);
    }
}

class ScheduledConfigService implements ConfigurationManager {
    private Configuration latestConfig;
    private configreadfrequency;
    private scheduleFrequency;
    private startTime;
    
    public ScheduledConfigService(Configuration config, int configreadfrequency, int scheduleFrequency, int startTime) {
        this.scheduleFrequency = scheduleFrequency;
        this.configreadfrequency = configreadfrequency;
        this.startTime = startTime;
    }
    
    @Override
    public Configuration readConfig (Configuration config) {
        if(configreadfrequency <= scheduleFrequency && (currtime - startTime) <= 60) {
            latestConfig =  config.readConfig();
            return latestConfig;
        }
        else if ((currtime - startTime) >= 60) {
            this.startTime = currtime;
            this.configreadfrequency = 0;
            return latestConfig;
        }
        else {
            latestConfig =  config.readConfig();
        }
    }
} 
// for X notification in minute:
/*
Each service will have a counter to keep track of number of time it has read the config
Every 
*/
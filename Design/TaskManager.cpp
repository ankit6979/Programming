class TaskManager {
public:
    struct Comparator {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> task_priority;
    map<int, int> task_priority_mapping;
    map<int, int> task_user_mapping;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            task_priority.push(make_pair(task[2], task[1]));
            task_priority_mapping[task[1]] = task[2];
            task_user_mapping[task[1]] = task[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_priority.push(make_pair(priority, taskId));
        task_priority_mapping[taskId] = priority;
        task_user_mapping[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        task_priority.push(make_pair(newPriority, taskId));
        task_priority_mapping[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        task_priority_mapping.erase(taskId);
        task_user_mapping.erase(taskId);
    }
    
    int execTop() {
        while(!task_priority.empty()) {
            int curr_task = task_priority.top().second;
            int curr_task_priority = task_priority.top().first;
            task_priority.pop();
            if(task_priority_mapping.find(curr_task) != task_priority_mapping.end() && task_priority_mapping[curr_task] == curr_task_priority) {
                int user_id = task_user_mapping[curr_task];
                task_priority_mapping.erase(curr_task);
                task_user_mapping.erase(curr_task);
                return user_id;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
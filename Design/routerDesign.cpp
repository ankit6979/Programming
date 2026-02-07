class Router {
public:    
    struct Packet {
        int source;
        int destination;
        int timestamp;
        bool operator==(const Packet& other) const {
            return source == other.source &&
                destination == other.destination &&
                timestamp == other.timestamp;
        }
    };

    struct PacketHash {
        size_t operator()(const Packet& p) const {
            return hash<int>()(p.source) ^ (hash<int>()(p.destination) << 1) ^ (hash<int>()(p.timestamp) << 2);
        }
    };

    unordered_set<Packet, PacketHash> memory;
    unordered_map<int, deque<int>> destination_timestamp;
    queue<Packet> fifo;
    int memoryLimit;
    
    void addNode(Packet& new_node) {
        memory.insert(new_node);
        destination_timestamp[new_node.destination].push_back(new_node.timestamp);
        fifo.push(new_node);
    }

    void delNode() {
        Packet packet = fifo.front();
        memory.erase(packet);
        destination_timestamp[packet.destination].pop_front();
        fifo.pop();
    }
    
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet curr_packet;
        curr_packet.source = source;
        curr_packet.destination = destination;
        curr_packet.timestamp = timestamp;
        if (memory.find(curr_packet) == memory.end()) {
            if (fifo.size() < memoryLimit) {
                addNode(curr_packet);
            }
            else {
                delNode();
                addNode(curr_packet);
            }
            return true;
        }
        return false;
    }
    
    vector<int> forwardPacket() {
        if (fifo.size() > 0) {
            Packet top_packet = fifo.front();
            vector<int> res = {top_packet.source, top_packet.destination, top_packet.timestamp};
            delNode();
            return res;
        }
        return {};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& qq=destination_timestamp[destination];
        cout<<qq[2]<<endl;
        auto itL=lower_bound(qq.begin(), qq.end(), startTime);
        auto itR=upper_bound(qq.begin(), qq.end(), endTime);
        return itR-itL;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
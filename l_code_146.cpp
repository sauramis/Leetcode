//inefficient solution but works, slightly complicated but good use of data structures.

class LRUCache {
public:
    unordered_map<int, int> cache_queue;
    deque<int> ordered_queue;
    int size_f_cache;
    LRUCache(int capacity) {
        //cout << "capacity : "<<capacity<<endl;
        cache_queue.reserve(capacity);
        size_f_cache = capacity;
    }
    
    int get(int key) {
        unordered_map<int, int>::iterator finder = cache_queue.find(key);
        int result;
        if(finder == cache_queue.end()){
            return -1;
        }
        else{
            result = finder->second;
            if(key == ordered_queue.back()){
                //cout << "no changes needed" << endl;
            }
            else{
                deque<int>::iterator itr = ordered_queue.begin();
                while(*itr != key){
                    itr++;
                }
                //cout << "itr pointing to key : "  << endl;
                while(itr != (ordered_queue.end()-1)){
                    *itr = *(itr+1);
                    itr++;
                }
                while(itr != (ordered_queue.end()-1)){
                    *itr = *(itr+1);
                    itr++;
                }
                ordered_queue.pop_back();
                ordered_queue.push_back(key);
            }
        }
        return result;
    }
    
    void put(int key, int value) {
        int key_to_replace;
        unordered_map<int, int>::iterator finder = cache_queue.find(key);
        if(cache_queue.size() < size_f_cache){
            if(finder == cache_queue.end()){
                cout << "inserting key : " << key << endl;
                cache_queue.insert(pair<int, int>(key, value));
                ordered_queue.push_back(key);
            }
            else{
                //update the entry in map
                finder->second = value;
                //adjust the deque for key
                deque<int>::iterator itr = ordered_queue.begin();
                while(*itr != key){
                    itr++;
                }
                //cout << "itr pointing to key : " << *itr <<endl;
                while(itr != (ordered_queue.end()-1)){
                    *itr = *(itr+1);
                    itr++;
                }
                ordered_queue.pop_back();
                ordered_queue.push_back(key);
                
            }
        }
        else{
            if(finder == cache_queue.end()){
                key_to_replace = ordered_queue.front();
                ordered_queue.pop_front();
                unordered_map<int, int>::iterator itr = cache_queue.find(key_to_replace);
                cache_queue.erase(itr);
                cache_queue.insert (pair<int,int>(key, value));
                ordered_queue.push_back(key);
            }
            else{
                finder->second = value;
                deque<int>::iterator itr = ordered_queue.begin();
                while(*itr != key){
                    itr++;
                }
                //cout << "itr pointing to key" << endl;
                while(itr != (ordered_queue.end()-1)){
                    *itr = *(itr+1);
                    itr++;
                }
                ordered_queue.pop_back();
                ordered_queue.push_back(key);
            }
        }
        
    }
};



class SmallestInfiniteSet {
private:
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, bool> mp;
    
public:
    SmallestInfiniteSet() {
        x = 1;
        pq.push(x++);
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        
        while(!pq.empty() && smallest == pq.top())
            pq.pop();
                
        pq.push(x++);       
        
        return smallest;
    }
    
    void addBack(int num) {
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
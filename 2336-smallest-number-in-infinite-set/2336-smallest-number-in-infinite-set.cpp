class SmallestInfiniteSet {
private:
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SmallestInfiniteSet() {
        x = 1; // initialize to 1. Because the range can be from 1 to n.
        pq.push(x++); // push 1 to the pq and increment it.
    }
    int popSmallest() {
        int smallest = pq.top(); // store the top most element to return from the pq. which would always be the smallest.
        pq.pop();
        while(!pq.empty() && smallest == pq.top()) // pop the element till we find the duplicate elements that are equal to the smallest. this is to avoid having duplicate values.
            pq.pop();
        pq.push(x++); // push the next value and inc.        
        return smallest;
    }
    void addBack(int num) {
        pq.push(num); // just add the num to pq as usual not caring about the duplicates. As we are handling the dupes above in popSmallest func.
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
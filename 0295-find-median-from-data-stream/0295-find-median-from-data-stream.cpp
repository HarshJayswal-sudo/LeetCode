class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>>l;
    MedianFinder() {  
    }
    
    void addNum(int num) {
        s.push(num);
        l.push(s.top());
        s.pop();


        if(l.size()>s.size()){
            s.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        return s.size()>l.size()? s.top():(s.top()+ l.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
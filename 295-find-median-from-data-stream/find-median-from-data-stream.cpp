class MedianFinder {// here we have to maintain the extra element in the queue so at the time of  the odd we can get the mean easily
public:
    priority_queue<int> left_max_heap;// max heap to sotre thr left siide eleemnts of the array
    priority_queue<int,vector<int>,greater<int>> right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num<left_max_heap.top()){
            left_max_heap.push(num);
        }else{// we have to put it in the right heap
            right_min_heap.push(num);
        }

        // this check is very imp, we have to check if the size of the right heap is grrater then the left one, it means we have to transfer it  to the left one, it is very necssary for the odd numbers

        if(abs((int)left_max_heap.size()-(int)right_min_heap.size())>1){// the left one shouuld be bigger but not  bigger then the right one 
        right_min_heap.push(left_max_heap.top());
        left_max_heap.pop();

        }else if(left_max_heap.size()<right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size()==right_min_heap.size()){// len of the array or the data stream is even
double mean=(left_max_heap.top()+right_min_heap.top())/2.0;

return mean;

        }

        return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
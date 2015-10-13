// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
    public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int a;
    bool flag;
    public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        a = 0;
        flag = false;
        if(Iterator::hasNext()){
            a = Iterator::next();
            flag = true;
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return a;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int b = a;
        if(Iterator::hasNext()){
            a = Iterator::next();
            flag = true;
        }
        else{
            flag = false;
        }
        return b;
    }

    bool hasNext() const {
        return flag;
    }
};

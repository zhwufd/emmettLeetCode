class Stack {
    private:
        deque<int> q;
    public:
        void push(int x) {
            q.push_back(x);
        }

        void pop() {
            q.pop_back();
        }

        int top() {
            return q.back();   
        }

        bool empty() {
            return q.empty();
        }
};

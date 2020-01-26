namespace mlpp {
    template<class T>
    T abs(T x) {
        if(x<0) return -x;
        return x;
    }
}
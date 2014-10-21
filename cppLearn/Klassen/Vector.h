class Vector{
    private:
        int x;  
        int y;
    public:
        Vector(int x, int y);
        void print();
        int getX();
        int getY();
   
        #include "Vector.tpp"
};

inline int Vector::getX(){
    return x;
}

inline int Vector::getY(){
    return y;
}

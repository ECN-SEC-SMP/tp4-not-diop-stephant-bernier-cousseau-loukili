#pragma once

template <typename T>
class Point2D {
    private :
        T x ;
        T y ;
    public :
        Point2D(T x, T y) ;
        Point2D(); 
        Point2D(Point2D<T>& p) ;
        T getX( ) ;
        T getY( ) ;
        void setX(T y) ; 
        void setY(T y) ;
        void translate(T x, T y) ;
};

template <typename T>
Point2D<T>::Point2D(T x, T y) {}

template <typename T>
Point2D<T>::Point2D(Point2D<T>& p) {
    this->x = p->x;
    this->y = p->y;
}


template <typename T>
T Point2D<T>::getX( ) {
    return this->x;
}

template <typename T>
T Point2D<T>::getY( ) {
    return this->y;
}

template <typename T>
void Point2D<T>::setX(T y) {
    this->x = y;
}

template <typename T>
void Point2D<T>::setY(T y) {
    this->y=y;
}

template <typename T>
void Point2D<T>::translate(T x, T y) {
    this->x += x;
    this->y +=y;
}

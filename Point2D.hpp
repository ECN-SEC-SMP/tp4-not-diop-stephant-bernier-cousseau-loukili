#pragma once

template <typename T>
class Point2D {
    private :
        T x ;
        T y ;
    public :
        /**
         * @brief Construct a new Point 2 D object
         * 
         * @param x 
         * @param y 
         */
        Point2D(T x, T y) ;
        /**
         * @brief Construct a new Point 2 D object
         * 
         */
        Point2D();
        /**
         * @brief constructeur 
         * 
         */
        Point2D(Point2D<T>& p) ;
        /**
         * @brief Accesseur pour la coordonnée x
         * @return T 
         */
        T getX( ) ;
        /**
         * @brief Accesseur pour la coordonnée y
         * @return T 
         */
        T getY( ) ;
        /**
         * @brief Mutateur pour la coordonnée x
         * @param y 
         */
        void setX(T y) ; 
        /**
         * @brief Mutateur pour la coordonnée y
         * @param y 
         */
        void setY(T y) ;
        /**
         * @brief Fonction translation sur les 2 coordonnées
         * @param x 
         * @param y 
         */
        void translate(T x, T y) ;
};

template <typename T>
Point2D<T>::Point2D(T x, T y) {}

template <typename T>
Point2D<T>::Point2D(Point2D<T>& p) {
    this->x = p.x;
    this->y = p.y;
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
void Point2D<T>::setX(T x) {
    this->x = x;
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

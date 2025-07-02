# include "Point.hpp"

int main()
{
    //inside
/*     Point a(3.0f,9.0f);
    Point b(4.0f,3.0f);
    Point c(10.0f,8.0f);
    Point pnt(6.0f,7.0f); */

    //outside
    Point a(3.0f,9.0f);
    Point b(4.0f,3.0f);
    Point c(10.0f,8.0f);
    Point pnt(11.0f,7.0f);

    //outside vertex
    /* Point a(3.0f,9.0f);
    Point b(4.0f,3.0f);
    Point c(10.0f,8.0f);
    Point pnt(10.0f,8.0f); */

    //edge
    /* Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);
    Point pnt(2.0f, 0.0f); */


    if(bsp( a, b, c, pnt))
        std::cout << "inside" << std::endl;
    else
        std::cout << "Outside" << std::endl;
    return 0;
}

/*
    How to determine whether two rectangles overlap?

    Algorithm:
        Do NOT consider the condition if these two overlap, two many edge cases.

        Consider the opposite:  the condition if the two do not overlap.
        Two rectangles do not overlap when one is above/below, 
        or to the left/right of the other rectangle. [MUCH EASIER]
 */

#include <iostream>

class Point {
public:
    double x;
    double y;

    Point(int _x, int _y): x(_x), y(_y) { }
};

class Rectangle {
public:
    Point upper_left;
    Point bottom_right;
    
    Rectangle(Point ul, Point br): upper_left(ul), bottom_right(br) { }
};

bool rectangle_overlap(const Rectangle &r1, const Rectangle &r2) 
{
   return  ! (r1.bottom_right.x < r2.upper_left.x   ||
              r2.bottom_right.x < r1.upper_left.x   ||
              r1.bottom_right.y > r2.upper_left.y   ||
              r2.bottom_right.y > r1.upper_left.y);
}

void TEST_rectangle_overlap()
{
    std::cout << "\n *** TEST for rectangle overlap ***\n";
    
    double x, y;

    std::cout << "Rectangle 1:\n";
    
    std::cout << "Enter x for upper left point: \n";
    std::cin  >> x;    
    std::cout << "Enter y for upper left point: \n";
    std::cin  >> y;
    Point upper_left_1(x, y);
    
    std::cout << "Enter x for bottom right point: \n";
    std::cin  >> x;    
    std::cout << "Enter y for bottom right point: \n";
    std::cin  >> y;
    Point bottom_right_1(x, y);

    Rectangle r1(upper_left_1, bottom_right_1);

    std::cout << "\nRectangle 2:\n";
    std::cout << "Enter x for upper left point: \n";
    std::cin  >> x;    
    std::cout << "Enter y for upper left point: \n";
    std::cin  >> y;
    Point upper_left_2(x, y);

    std::cout << "Enter x for bottom right point: \n";
    std::cin  >> x;    
    std::cout << "Enter y for bottom right point: \n";
    std::cin  >> y;
    Point bottom_right_2(x, y);

    Rectangle r2(upper_left_2, bottom_right_2);

    if (rectangle_overlap(r1, r2)) {
        std::cout << "Two rectangles overlap\n";
    } else {
        std::cout << "Two rectangles do NOT overlap\n";
    }
}

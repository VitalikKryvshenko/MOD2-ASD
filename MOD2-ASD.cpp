#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;  
    return (val > 0) ? 1 : 2; 
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);


    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && p1.x >= p2.x && p1.x <= q2.x) return true;
    if (o2 == 0 && q1.x >= p2.x && q1.x <= q2.x) return true;
    if (o3 == 0 && p2.x >= p1.x && p2.x <= q1.x) return true;
    if (o4 == 0 && q2.x >= p1.x && q2.x <= q1.x) return true;

    return false; 
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Point A, B, C, D;

    cout << "Введіть координати точки A (x y): ";
    cin >> A.x >> A.y;
    cout << "Введіть координати точки B (x y): ";
    cin >> B.x >> B.y;
    cout << "Введіть координати точки C (x y): ";
    cin >> C.x >> C.y;
    cout << "Введіть координати точки D (x y): ";
    cin >> D.x >> D.y;

    if (doIntersect(A, B, C, D))
        cout << "Відрізки перетинаються\n";
    else
        cout << "Відрізки не перетинаються\n";

    return 0;
}


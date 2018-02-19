#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <fstream>
#include <ncurses.h>

using namespace std;

class Point {
private:
    float _x;
    float _y;
public:
    Point() = default;
    Point(float x, float y) {
        _x = x;
        _y = y;
    }
    float x(){
        return _x;
    }
    float y(){
        return _y;
    }
    void RotateRelative(Point p, float angle) { //Rotate this point relative to point p
        angle = -angle * M_PI / 180;
        _x = (_x - p.x()) * cos(angle) - (_y - p.y()) * sin(angle) + p.x();
        _y = (_x - p.x()) * sin(angle) + (_y - p.y()) * cos(angle) + p.y();
    }
    void Rotate(float angle) {   // Rotate this point relative to (0, 0)
        RotateRelative(Point(0.0, 0.0), angle);
    }
    void Move(float x, float y) {
        _x += x;
        _y += y;
    }
    void Move(Point p) {
        _x += p.x();
        _y += p.y();
    }
    string toString() {
        return "(" + to_string(_x) + ", " + to_string(_y) + ")";
    }
};

class Rectangle {
private:
    float _width; //Width
    float _height; //Height
    Point _coord;
    float _fi;//Rectangle rotation
    void Init(float x, float y, float fi, float width, float height) { //TODO: Add validation
        SetCoords(x, y);
        _fi = fi;
        try {
            if ((width < 0) || (height < 0)) { throw "Invalid argument: width and height can't be less than zero."; }
        }
        catch (char const* e) {
            cout << e << endl;
            terminate();
        }
        _width = width;
        _height = height;
    }
public:
    string toString() {
        vector<Point> pts = GetPoints();
        string result = "Rectangle(";
        for (Point p : pts) {
            result += p.toString() + " ";
        }
        result += ")";
        return result;
    }
    vector<Point> GetPoints() {
        vector<Point> result;
        Point A = Point(_width/2, _height/2);
        A.Rotate(_fi);
        A.Move(_coord);
        result.emplace_back(A);
        Point B = Point(_width/2, -_height/2);
        B.Rotate(_fi);
        B.Move(_coord);
        result.emplace_back(B);
        Point C = Point(-_width/2, -_height/2);
        C.Rotate(_fi);
        C.Move(_coord);
        result.emplace_back(C);
        Point D = Point(-_width/2, _height/2);
        D.Rotate(_fi);
        D.Move(_coord);
        result.emplace_back(D);
        return result;
    }
    Rectangle() = default;
    Rectangle(float x, float y, float fi, float width, float height) {
        Init(x, y, fi, width, height);
    }
    Rectangle(Point coord, float fi, float width, float height) {
        Init(coord.x(), coord.y(), fi, width, height);
    }
    bool isSquare() {
        return fabs(_width - _height) < numeric_limits<float>::epsilon();
    }
    void Rotate(float angle) {
        _fi += angle*M_PI/180;
    }
    void Move(float x, float y) {
        _coord = Point(_coord.x()+x, _coord.y()+y);
    }
    Point GetCoords() {
        return _coord;
    }

    void SetCoords(float x, float y) {
        _coord = Point(x, y);
    }
    void SetCoords(Point p) {
        _coord = p;
    }
    float GetPerimeter() {
        return (_width + _height)*2;
    }
    float GetArea() {
        return _width * _height;
    }
    vector<Rectangle> SplitToSquares(bool next = false) {
        static vector<Rectangle> m;
        if (!next) {
           m.clear(); //If function is just started, clear list of squares.
        }
        if (isSquare()) {
            m.emplace_back(Rectangle(_coord, _fi, _width, _height));
            return m;
        } else {
            Point coord = _coord;
            float angle = _fi;
            //Move to (0,0) and rotate to normal position.
            Rotate(-angle);
            Move(-_coord.x(), -_coord.y());
            //Define necessary variables
            float side;
            float rect_width;
            float rect_height;
            float sq_center_x;
            float sq_center_y;
            float leftover_center_x;
            float leftover_center_y;
            //Calculate new rectangles
            if (_width > _height) {
                side = _height;
                rect_width = _width - side;
                rect_height = _height;
                sq_center_x = -_width / 2 + side / 2;
                sq_center_y = 0.0;
                leftover_center_x = side / 2;
                leftover_center_y = 0.0;
            } else {
                side = _width;
                rect_width = _width;
                rect_height = _height - side;
                sq_center_x = 0.0;
                sq_center_y = _height / 2 - side / 2;
                leftover_center_x = 0.0;
                leftover_center_y = -side / 2;
            }
            //Rotate and move points back to source position.
            Point sq_center = Point(sq_center_x, sq_center_y);
            sq_center.Rotate(angle);
            sq_center.Move(coord.x(), coord.y());
            Point rect_center = Point(leftover_center_x, leftover_center_y);
            rect_center.Rotate(angle);
            rect_center.Move(coord.x(), coord.y());
            m.emplace_back(Rectangle(sq_center, angle, side, side));
            Rectangle(rect_center, angle, rect_width, rect_height).SplitToSquares(true);
            return m;
        }};


};

int main() {
    ofstream file;
    float x;
    float y;
    float fi;
    float w;
    float h;
    file.open("result.txt");
    cout << "Введите координату X прямоугольника: ";
    cin >> x;
    cout << "Введите координату Y прямоугольника: ";
    cin >> y;
    cout << "Введите угол поворота прямоугольника: ";
    cin >> fi;
    cout << "Введите ширину прямоугольника: ";
    cin >> w;
    cout << "Введите высоту прямоугольника: ";
    cin >> h;
    Rectangle testRect1 = Rectangle(x, y, fi, w, h);
    cout << testRect1.toString() << endl;
    file << testRect1.toString() << endl;
    cout << "Периметр: " << to_string(testRect1.GetPerimeter()) << endl;
    cout << "Площадь: " << to_string(testRect1.GetArea()) << endl;
    vector<Rectangle> sq = testRect1.SplitToSquares();
    for (Rectangle square: sq) {
        file << square.toString() << endl;
    }
    cout << "Координаты точек квадратов, на которые разбит прямоугольник сохранены в results.txt" << endl;
    cout << "Просмотреть квадраты можно с помощью команды 'python3 ./show.py'" << endl;
    file.close();
    return 0;
}
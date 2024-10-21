import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main (String[] args) throws java.lang.Exception {
        Shape circle = new Circle(5);
        System.out.println("Circle Area: " + circle.getArea());

        Shape square = new Square(4);
        System.out.println("Square Area: " + square.getArea());
    }
}

// Define the Shape interface
interface Shape {
    double getArea();
    int nSides();
}

// Abstract class implementing the Shape interface
abstract class AbstractShape implements Shape {
    // AbstractShape can have common methods or fields if needed
}

// Circle class extending AbstractShape
class Circle extends AbstractShape {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }


    public int nSides() {
        return 0; // A circle has no sides
    }


    public double getArea() {
        return Math.PI * radius * radius;
    }
}

// Abstract class for Quadrilateral
abstract class Quadrilateral extends AbstractShape {

    public int nSides() {
        return 4;
    }
}

// Square class extending Quadrilateral
class Square extends Quadrilateral {
    double side;

    public Square(double side) {
        this.side = side;
    }


    public double getArea() {
        return side * side;
    }
}

// Implement other shapes similarly
class Rectangle extends Quadrilateral {
    double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }


    public double getArea() {
        return length * width;
    }
}

class Trapezium extends Quadrilateral {
    double a, b, height;

    public Trapezium(double a, double b, double height) {
        this.a = a;
        this.b = b;
        this.height = height;
    }


    public double getArea() {
        return ((a + b) / 2) * height;
    }
}

// Abstract class for Triangle
abstract class Triangle extends AbstractShape {

    public int nSides() {
        return 3;
    }
}

// Scalene Triangle class extending Triangle
class ScaleneTriangle extends Triangle {
    double base, height;

    public ScaleneTriangle(double base, double height) {
        this.base = base;
        this.height = height;
    }


    public double getArea() {
        return (base * height) / 2;
    }
}

// Isosceles Triangle class extending Triangle
class IsoscelesTriangle extends Triangle {
    double base, height;

    public IsoscelesTriangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double getArea() {
        return (base * height) / 2;
    }
}

// Equilateral Triangle class extending Triangle
class EquilateralTriangle extends Triangle {
    double side;

    public EquilateralTriangle(double side) {
        this.side = side;
    }


    public double getArea() {
        return (Math.sqrt(3) / 4) * side * side;
    }
}

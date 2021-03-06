/*
 * Shape.h
 *
 * (c) 2013 Sofian Audry -- info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <vector>
#include <tr1/memory>
#include <iostream>

/**
 * Point (or vertex) on the 2-D canvas.
 */
struct Point
{
  double x;
  double y;
  Point(double x_, double y_) : x(x_), y(y_) {}
};

/**
 * Series of vertices. (points)
 */
class Shape
{
public:
  typedef std::tr1::shared_ptr<Shape> ptr;
  std::vector<Point> vertices;
  Shape() {}
  Shape(std::vector<Point> vertices_) :
    vertices(vertices_)
  {}
  virtual ~Shape() {}

  virtual void build() {}

  int nVertices() const { return vertices.size(); }

  const Point& getVertex(int i)
  {
    return vertices[i];
  }
  void setVertex(int i, Point v)
  {
    vertices[i] = v;
  }
  void setVertex(int i, double x, double y)
  {
    vertices[i].x = x;
    vertices[i].y = y;
  }

  /** Return true if Shape includes point (x,y), false otherwise
   *  Algorithm should work for all polygons, including non-convex
   *  Found at http://www.cs.tufts.edu/comp/163/notes05/point_inclusion_handout.pdf
   */
  bool includesPoint(int x, int y)
  {
    Point *prev = NULL, *cur;
    int left = 0, right = 0, maxy, miny;
    for (std::vector<Point>::iterator it = vertices.begin() ; it !=
            vertices.end(); it++)
    {
      if (!prev) {
          prev = &vertices.back();
      }
      cur = &(*it);
      miny = std::min(cur->y, prev->y);
      maxy = std::max(cur->y, prev->y);

      if (y > miny && y < maxy) {
        if (prev->x == cur->x) 
        {
          if (x < cur->x)
            right++;
          else left++;
        }
        else
        {
          double slope = (cur->y - prev->y) / (cur->x - prev->x);
          double offset = cur->y - slope * cur->x;
          int xintersect = int((y - offset ) / slope);
          if (x < xintersect)
            right++;
          else left++;
        }
      }
      prev = &(*it);
    }
    if (right % 2 && left % 2)
        return true;
    return false;
  }
  /* Translate all vertices of shape by the vector (x,y) */
  void translate(int x, int y)
  {
    for (std::vector<Point>::iterator it = vertices.begin() ; it !=
            vertices.end(); ++it) 
    {
      it->x += x;
      it->y += y;
    }
  }  

  int nVertices()
  {
    return vertices.size();
  }
};

/**
 * Four-vertex shape.
 */
class Quad : public Shape
{
public:
  Quad() {}
  Quad(Point p1, Point p2, Point p3, Point p4)
  {
    vertices.push_back(p1);
    vertices.push_back(p2);
    vertices.push_back(p3);
    vertices.push_back(p4);
  }
  virtual ~Quad() {}
};

/**
 * Triangle shape.
 */
class Triangle : public Shape
{
public:
  Triangle() {}
  Triangle(Point p1, Point p2, Point p3)
  {
    vertices.push_back(p1);
    vertices.push_back(p2);
    vertices.push_back(p3);
  }
  virtual ~Triangle() {}
};

#endif /* SHAPE_H_ */

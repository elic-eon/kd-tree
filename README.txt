kd-tree

Must include headfile
  #include"kdtree.h"


Tutorial

1.Manually
  -Install
    1. `g++ -c kdtree.cpp -o kdtree.o`
    2. `ar rcs kdtree.a kdtree.o`

  -Usage
    `g++ target.cpp kdtree.a -o out.a`

2.Makefile
  `$ make` to setup libary and create a example or you can only create libary.

  `$ make install` install library than you can use g++ to use that library.
  Example : `g++ test.cpp kdtree.a -o test`

  `$ make example` if you have installed library you can create an example to ensure library was installed correctly.

  if you want to clean lib file
  `$ make clean`


class KDTree
  `KDtree tree1;`
  1. void insert2D(double, double, char *)
    You can insert a pair (x , y) into the 2D-tree
    Example :
      `tree1.insert2D(1, 2, "A")`
    means you insert a point A (1, 2)in 2D space into tree
  2. KDIterator& nearest2D(double, double)
    If you have inserted some points in the 2D-Tree
    You can get the neatest point between whichever point you want
    Example :
      `tree1.insert2D(1, 2, "A");`
      `tree1.insert2D(-1, 3, "B");`
      `KDIterator nearest = tree1.nearest2D(0, 0);`
    It will return a KDIterator point the nearest point
  3. void clear()
    You can use the function to clear all point in the tree
    Example :
      `tree1.clear()`

class KDIterator
  1. void show()
    You can use this function to print a point
    Example :
      `KDIterator nearest = tree.nearest2D(0, 0);`
      `nearest.show();`
    it will pintf A( x, y ) or other depend on your tree

Other function
  1. double dis(double, double, KDIterator&)
    This function can calculate distence between two points
    Example :
      `KDIterator nearest = tree.nearest2D(0, 0);`
      `double distence = dis(0, 0, nearest);`

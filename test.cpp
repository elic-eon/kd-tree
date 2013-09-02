#include<iostream>
#include"kdtree.h"
using namespace std;

int main()
{
  KDTree t1;
  cout << "Insert point A( 1 , 2 )" << endl;
  t1.insert2D(1, 2, "A");
  cout << "Insert point B( 2 , 4 )" << endl;
  t1.insert2D(2, 4, "B");
  cout << "Insert point C( 0 , 1 )" << endl;
  t1.insert2D(0, 1, "C");
  cout << "Insert point D( 3 , 6 )" << endl;
  t1.insert2D(3, 6, "D");
  cout << "Insert point E( -1 , 4 )" << endl;
  t1.insert2D(-1, 4, "E");
  if (1 == 1);
  KDIterator p = t1.nearest2D(0, 0);
  cout << "The nearest point with point ( 0, 0 ) in 2-D Tree is :"<< endl;
  p.show();
  cout << "\tDistence: " << dis(0, 0, p) << endl;

  p = t1.nearest2D(0, 2.1);
  cout << "The nearest point with point ( 0, 2.1 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(0, 2.1, p) << endl;

  p = t1.nearest2D(6, 6);
  cout << "The nearest point with point ( 6, 6 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(6, 6, p) << endl;

  p = t1.nearest2D(2, 5);
  cout << "The nearest point with point ( 2, 5 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(2, 5, p) << endl;

  p = t1.nearest2D(-2, 3);
  cout << "The nearest point with point ( -2, 3 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(-2, 3, p) << endl;

  t1.clear();

  cout << "Insert point A( 1 , 2 )" << endl;
  t1.insert2D(1, 2, "A");
  cout << "Insert point B( 2 , 4 )" << endl;
  t1.insert2D(2, 4, "B");
  cout << "Insert point C( 0 , 1 )" << endl;
  t1.insert2D(0, 1, "C");
  cout << "Insert point D( 3 , 6 )" << endl;
  t1.insert2D(3, 6, "D");
  cout << "Insert point E( -1 , 4 )" << endl;
  t1.insert2D(-1, 4, "E");
  if (1 == 1);
  p = t1.nearest2D(0, 0);
  cout << "The nearest point with point ( 0, 0 ) in 2-D Tree is :"<< endl;
  p.show();
  cout << "\tDistence: " << dis(0, 0, p) << endl;

  p = t1.nearest2D(0, 2.1);
  cout << "The nearest point with point ( 0, 2.1 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(0, 2.1, p) << endl;

  p = t1.nearest2D(6, 6);
  cout << "The nearest point with point ( 6, 6 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(6, 6, p) << endl;

  p = t1.nearest2D(2, 5);
  cout << "The nearest point with point ( 2, 5 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(2, 5, p) << endl;

  p = t1.nearest2D(-2, 3);
  cout << "The nearest point with point ( -2, 3 ) in 2-D Tree is :" << endl;
  p.show();
  cout << "\tDistence: " << dis(-2, 3, p) << endl;
  return 0;
}

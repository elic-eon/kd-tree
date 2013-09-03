#ifndef __DS__KDTREE__
#define __DS__KDTREE__
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<stack>
#include<cmath>
#include<cfloat>
using namespace std;
class KDTree;
class KDIterator;
#define MAX_DIM 3
inline double SQ(double x){ return x * x; }
struct tree{
  struct KDnode *root;
  int dim;
};

struct KDnode{
  double pos[MAX_DIM];
  int dir;
  char *data;
  struct KDnode *left;
  struct KDnode *right;
  struct KDnode *parent;
};
class KDTree{
  private:
    struct tree *tree;
  public:
    friend class KDIterator;
    KDTree(int dim = 2);
    ~KDTree();
    void insert2D(double x, double y, char *data);
    void clear();
    KDIterator& nearest2D(double x, double y);
};
class KDIterator{
  private:
    struct KDnode *it;
    int dim;
  public:
    friend class KDTree;
    KDIterator(struct KDnode* cur = NULL, int d = 1);
    KDIterator(const KDIterator& cp);
    struct KDnode * insertByIt2D(double x, double y, char *data, int dir, struct KDnode *parent);
    struct KDnode * goRight() const;
    struct KDnode * goLeft() const;
    ~KDIterator();
    void show();
    friend double dis(double x, double y, KDIterator& it);
};
#endif

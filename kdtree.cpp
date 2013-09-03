#include"kdtree.h"

void freeTree(struct KDnode* root){
  if (root == NULL)
    return;
  if (root->right != NULL)
    freeTree(root->right);
  if (root->left != NULL)
    freeTree(root->left);
  delete root;
  root = NULL;
}
KDTree::KDTree(int dim){
  tree = new struct tree;
  tree->root = NULL;
  tree->dim = dim;
}
KDTree::~KDTree(){
  freeTree(tree->root);
  delete tree;
  tree = NULL;
}

void KDTree::insert2D(double x, double y, char *data){
  KDIterator it(tree->root, 2);
  tree->root = it.insertByIt2D(x, y, data, 0, NULL);
}
void KDTree::clear()
{
  freeTree(tree->root);
  tree->root = NULL;
}
KDIterator& KDTree::nearest2D(double x, double y){
  KDIterator cur(tree->root, 2);
  if (tree->root == NULL)
    return cur;
  if (tree->root->right == NULL && tree->root->left == NULL)
    return cur;
  stack<KDIterator> nodeStack;
  stack<int> split;
  while (1)
  {
    nodeStack.push(KDIterator(cur.it, 2));
    if (cur.it->dir % cur.dim == 0){
      if (x >= cur.it->pos[0])
      {
        if (cur.goRight() == NULL)
          if (cur.goLeft() == NULL)
            break;
          else
          {
            split.push(2);
            cur.it = cur.goLeft();
          }
        else{
          split.push(1);
          cur.it = cur.goRight();
        }
      }
      else
      {
        if (cur.goLeft() == NULL)
          if (cur.goRight() == NULL)
            break;
          else
          {
            split.push(1);
            cur.it = cur.goRight();
          }
        else{
          split.push(2);
          cur.it = cur.goLeft();
        }
      }
    }
    else if (cur.it->dir % cur.dim == 1){
      if (y >= cur.it->pos[1])
      {
        if (cur.goRight() == NULL)
          if (cur.goLeft() == NULL)
            break;
          else
          {
            split.push(2);
            cur.it = cur.goLeft();
          }
        else{
          split.push(1);
          cur.it = cur.goRight();
        }
      }
      else
      {
        if (cur.goLeft() == NULL)
          if (cur.goRight() == NULL)
            break;
          else
          {
            split.push(1);
            cur.it = cur.goRight();
          }
        else{
          split.push(2);
          cur.it = cur.goLeft();
        }
      }
    }
  }
  KDIterator nearest = nodeStack.top();
  nodeStack.pop();
  KDIterator curNode;
  int dir;
  int s = split.top();
  split.pop();
  while (!nodeStack.empty())
  {
    curNode = nodeStack.top();
    nodeStack.pop();
    dir = curNode.it->dir;
    if (dir%curNode.dim == 0)
    {
      if (dis(x, y, nearest) > abs(x-curNode.it->pos[0]))
      {
        if (s == 2 && curNode.it->right != NULL)
        {
          nodeStack.push(KDIterator(curNode.it->right, 2));
          split.push(1);
        }
        if (s == 1 && curNode.it->left != NULL)
        {
          nodeStack.push(KDIterator(curNode.it->left, 2));
          split.push(2);
        }
        if (dis(x, y, nearest) > dis(x, y, curNode))
          nearest = curNode;
      }
    }
    if (dir%curNode.dim == 1)
    {
      if (dis(x, y, nearest) > abs(y-curNode.it->pos[1]))
      {
        if (s == 2 && curNode.it->right != NULL)
        {
          nodeStack.push(KDIterator(curNode.it->right, 2));
          split.push(1);
        }
        if (s == 1 && curNode.it->left != NULL){
          nodeStack.push(KDIterator(curNode.it->left, 2));
          split.push(2);
        }
        if (dis(x, y, nearest) > dis(x, y, curNode))
          nearest = curNode;
      }
    }
    if (!split.empty())
    {
      s = split.top();
      split.pop();
    }
  }
  return nearest;
}

KDIterator::KDIterator(struct KDnode *cur, int d){
  it = cur;
  dim = d;
}
KDIterator::KDIterator(const KDIterator& cp){
  it = cp.it;
  dim = cp.dim;
}
KDIterator::~KDIterator(){}
struct KDnode * KDIterator::insertByIt2D(double x, double y, char *data, int dir, struct KDnode *parent){
  struct KDnode *ret;
  if (it == NULL)
  {
    ret = new struct KDnode;
    ret->pos[0] = x;
    ret->pos[1] = y;
    ret->parent = parent;
    ret->left = ret->right = NULL;
    ret->dir = dir;
    ret->data = new char[strlen(data)];
    strcpy(ret->data, data);
    return ret;
  }
  else
  {
    ret = it;
    if (dir%dim == 0)
    {
      if (x > it->pos[0]){
        it->right = (*this).goRight();
        it = it->right;
        it = (*this).insertByIt2D(x, y, data, dir+1, ret);
        it->parent->right = it;
      }
      else{
        it->left = (*this).goLeft();
        it = it->left;
        it = (*this).insertByIt2D(x, y, data, dir+1, ret);
        it->parent->left = it;
      }
    }
    else if (dir%dim == 1)
    {
      if (y > it->pos[1]){
        it->right = (*this).goRight();
        it = it->right;
        it = (*this).insertByIt2D(x, y, data, dir+1, ret);
        it->parent->right = it;
      }
      else{
        it->left = (*this).goLeft();
        it = it->left;
        it = (*this).insertByIt2D(x, y, data, dir+1, ret);
        it->parent->left = it;
      }
    }
    return ret;
  }
}
struct KDnode *KDIterator::goRight() const
{
  if (it != NULL)
    return it->right;
}
struct KDnode* KDIterator::goLeft() const
{
  if (it != NULL)
    return it->left;
}
void KDIterator::show()
{
  cout << it->data << "( "<< it->pos[0] << ", " << it->pos[1] << " )" ;
}
double dis(double x, double y, KDIterator& it)
{
  if (it.it == NULL)
    return DBL_MAX;
  else
  {
    double d_x = x - it.it->pos[0];
    double d_y = y - it.it->pos[1];
    return sqrt(SQ(d_x) + SQ(d_y));
  }
}

// Binary Search Tree (TreeSet)
// Code from Liang, C++ Data Structures
//
// changed significantly by W.P. Iverson
// Bellevue College, WA
// Spring 2022
//
//Edited by: Tristan Lea
//Date: 6/16/22
//Description: Program 11 binary tree setup

//Edited by: Tristan Lea
//Date: 6/20/22

//#include <vector>
#include <string>
#include <iostream>

#include <stack>

using namespace std;

// the basic nodes for tree
template<typename T>
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode<T>* left; // Pointer to the left child
  TreeNode<T>* right; // Pointer to the right child

  bool isIterated; // this is used by recusive checker to find the missing treenodes later added

  TreeNode(T element) // Constructor
  {
    this->element = element;
    left = NULL;
    right = NULL;
  }
};

// one way to get a standard forward iterator:
template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
  Iterator(TreeNode<T>* p)
  {
      if (p == NULL)
      {
          current = NULL;
      }
      else
      {
          root = p;
          leftLeaf(p);
      }
  }

  // prefix forward increment
  Iterator& operator++()
  {
      if (current != NULL)
      {
          if (current->right != NULL)
          {
              leftLeaf(current->right);
          }
          else
          {
              if (parentStack.empty())
              {
                  //goes in checks reursively if there have been any new nodes added in
                  //iterator only does one at a time, but this does not break it because it
                  //continues to go through even if there are more than one added
                  current = recursiveChecker(root);
                  if (current != NULL)
                  {
                      current->isIterated = true;
                  }
              }
              else
              {
                  current = parentStack.top();
                  current->isIterated = true;
                  parentStack.pop();
              }
          }
      }
    return *this;
  }

  // dereference
  T &operator*()
  {
      return current->element;
  }
   
  // comparison operators
  bool operator == (const Iterator<T>& Iterator) const
  {
	  return current == Iterator.current;
  }

  bool operator != (const Iterator<T>& Iterator) const
  {
	  return current != Iterator.current;
  }

private:
    TreeNode<T>*  current;  // where we start 
  //vector<T> v;  // used to make a copy of tree
    
    TreeNode<T>* root;

  stack<TreeNode<T>*> parentStack;

  void leftLeaf(TreeNode<T>* p)
  {
      while (p->left != NULL)
      {
          parentStack.push(p);
          p = p->left;
      }
      current = p;
      current->isIterated = true;
  }

  TreeNode<T>* recursiveChecker(TreeNode<T>* root)
  {
      TreeNode<T>* child;

      if (root == NULL || !root->isIterated)
      {
          return root;
      }
      
      child = recursiveChecker(root->left);

      if (child != NULL)
      {
          return child;
      }

      return recursiveChecker(root->right);
  }

  //void treeToVector(TreeNode<T>* p)
  //{
  //  if (p != NULL) // recursion
  //  {
	 // // in order tree traversal
  //    treeToVector(p -> left);
  //    v.push_back(p -> element);
  //    treeToVector(p -> right);
  //  } // base case is do nothing
  //}
};


// HERE starts the actual Binary Search Tree structure
template <typename T>
class TreeSet
{
public:
  TreeSet();
  TreeSet(T elements[], int arraySize);
  TreeSet(TreeSet<T> &tree);
  ~TreeSet();
  bool search(T element) const;
  bool insert(T element);
  bool remove(T element);
  int getSize() const;

  Iterator<T> begin() const
  {
    return Iterator<T>(root);
  };

  Iterator<T> end() const
  {
    return Iterator<T>(NULL);
  };

private:
  int size;
  TreeNode<T>* root;
  TreeNode<T>* createNewNode(T element);
  void copy(TreeNode<T>* root);
};

template <typename T>
TreeSet<T>::TreeSet()
{
  root = NULL;
  size = 0;
}

template <typename T>
TreeSet<T>::TreeSet(T elements[], int arraySize)
{
  root = NULL;
  size = 0;

  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}

/* Copy constructor */
template <typename T>
TreeSet<T>::TreeSet(TreeSet<T> &tree)
{
  root = NULL;
  size = 0;
  copy(tree.root); // Recursively copy nodes to this tree
}

/* Copies the element from the specified tree to this tree */
template <typename T>
void TreeSet<T>::copy(TreeNode<T>* root)
{
  if (root != NULL)
  {
    insert(root->element);
    copy(root->left);
    copy(root->right);
  }
}

/* Destructor */
template <typename T>
TreeSet<T>::~TreeSet()
{
  // Still needs to be done....
}

/* Return true if the element is in the tree */
template <typename T>
bool TreeSet<T>::search(T element) const
{
  TreeNode<T>* current = root; // Start from the root

  while (current != NULL)
    if (element < current->element)
    {
      current = current->left; // Go left
    }
    else if (element > current->element)
    {
      current = current->right; // Go right
    }
    else // Element matches current.element
      return true; // Element is found

  return false; // Element is not in the tree
}

template <typename T>
TreeNode<T>*  TreeSet<T>::createNewNode(T element)
{
  return new TreeNode<T>(element);
}

/* Insert element into the binary tree
 * Return true if the element is inserted successfully
 * Return false if the element is already in the list
 */
template <typename T>
bool TreeSet<T>::insert(T element)
{
  if (root == NULL)
    root = createNewNode(element); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;
    while (current != NULL)
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

    // Create the new node and attach it to the parent node
    if (element < parent->element)
      parent->left = createNewNode(element);
    else
      parent->right = createNewNode(element);
  }

  size++;
  return true; // Element inserted
}


/* Get the number of nodes in the tree */
template <typename T>
int TreeSet<T>::getSize() const
{
  return size;
}

/* Delete an element from the binary tree.
 * Return true if the element is deleted successfully
 * Return false if the element is not in the tree */
template <typename T>
bool TreeSet<T>::remove(T element)
{
  // Locate the node to be deleted and also locate its parent node
  TreeNode<T>* parent = NULL;
  TreeNode<T>* current = root;
  while (current != NULL)
  {
    if (element < current->element)
    {
      parent = current;
      current = current->left;
    }
    else if (element > current->element)
    {
      parent = current;
      current = current->right;
    }
    else
      break; // Element is in the tree pointed by current
  }

  if (current == NULL)
    return false; // Element is not in the tree

  // Case 1: current has no left children
  if (current->left == NULL)
  {
    // Connect the parent with the right child of the current node
    if (parent == NULL)
    {
      root = current->right;
    }
    else
    {
      if (element < parent->element)
        parent->left = current->right;
      else
        parent->right = current->right;
    }

    delete current; // Delete current
  }
  else
  {
    // Case 2: The current node has a left child
    // Locate the rightmost node in the left subtree of
    // the current node and also its parent
    TreeNode<T>* parentOfRightMost = current;
    TreeNode<T>* rightMost = current->left;

    while (rightMost->right != NULL)
    {
      parentOfRightMost = rightMost;
      rightMost = rightMost->right; // Keep going to the right
    }

    // Replace the element in current by the element in rightMost
    current->element = rightMost->element;

    // Eliminate rightmost node
    if (parentOfRightMost->right == rightMost)
      parentOfRightMost->right = rightMost->left;
    else
      // Special case: parentOfRightMost->right == current
      parentOfRightMost->left = rightMost->left;

    delete rightMost; // Delete rightMost
  }

  size--;
  return true; // Element inserted
}

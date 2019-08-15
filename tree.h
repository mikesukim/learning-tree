//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   string Name;
   double Percentage;
   double Count;
   double Rank;
   
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string Name , Node * &Information);
   bool Insert(string Name, double Count, double Percentage, double Rank);
   bool Delete(string Name);
   int Count();
   int Height();
   void Print();

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string Name, Node * Tree, Node *& Information);
   bool InsertHelper(string Name, double Count, double Percentage, double Rank, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string Name, Node * &Tree);
   int CountHelper(Node * Tree);
   int HeightHelper(Node * Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
};

//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//-----------------------------------------------------------
#include "tree.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string Name, Node * Tree, Node *& Information)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree-> Name == Name)
   {   Information = Tree;
       return true;
   }
   // Recursively search for data value
   else if (Tree->Name > Name)
      return (SearchHelper(Name, Tree->Left, Information));
   else 
      return (SearchHelper(Name, Tree->Right, Information));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string Name , Node * &Information)
{
   // Call tree searching function
   return (SearchHelper(Name,Root, Information ));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string Name, double Count, double Percentage, double Rank, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Name = Name;
      Tree->Percentage = Percentage;
      Tree->Count = Count;
      Tree->Rank = Rank;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Name > Name)
      return (InsertHelper(Name,Count,Percentage,Rank,Tree->Left));
   else 
      return (InsertHelper(Name,Count,Percentage,Rank,Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string Name, double Count, double Percentage, double Rank)
{
   // Call tree insertion function
   return InsertHelper(Name,Count,Percentage,Rank, Root);
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->Name = Temp->Name;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string Name, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found and deleted
   else if (Tree->Name == Name)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->Name > Name)
      return (DeleteHelper(Name, Tree->Left));
   else 
      return (DeleteHelper(Name, Tree->Right));
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string Name)
{
   // Call tree deletion function
   return (DeleteHelper(Name, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout <<setw(10)<< Tree->Name
           <<setw(13)<< Tree->Count 
           <<setw(10)<< Tree->Percentage
           <<setw(10)<< Tree->Rank << endl;
      
      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}
int BinaryTree::CountHelper(Node * Tree)
{ 
    if(Tree == NULL)
        return 0;
    else
    {
      int Count = 1;
      Count += CountHelper(Tree->Left);
      Count += CountHelper(Tree->Right);
      return Count;
    }  
}
int BinaryTree::Count()
{
    int Count = (CountHelper(Root));
    cout << "Total Count of Tree = " << Count << endl;
}
int BinaryTree::HeightHelper(Node * Tree) 
{
    if(Tree == NULL)
        return 0;
    else
    {
      int left = HeightHelper(Tree->Left);
      int right = HeightHelper(Tree->Right);
      if(left > right)
      {
          return left + 1;
      }
      else
      {
          return right + 1;
      }
    }
   
}
int BinaryTree::Height()
{
    int Count = (HeightHelper(Root));
    cout << "Height of Tree = "<< Count << endl;
}

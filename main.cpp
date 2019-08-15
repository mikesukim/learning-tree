#include "tree.h"

void Read(string filename, BinaryTree & Tree)
{
    fstream din;
    din.open(filename.c_str());
    if(din.fail())
    {
        cout << " OPENING FILE NAME " << filename << " FAILED. " << endl; 
        exit(EXIT_FAILURE);
    }
    else
        {cout << " OPENING FILE NAME " << filename << " SUCCEEDED. " << endl;}

    string name;
    double count,rank,percentage;
   
    while(din >> name)
    {
        din >> count >> rank >> percentage; 
        
        Tree.Insert(name,count,rank,percentage);
        if(din.eof())
        {break;}
    }   
    din.close();
}
void Search(BinaryTree & Tree, string Name)
{
    Node * information;
    if(Tree.Search(Name,information))
    {
        cout  << Name << " IS FOUND!\n";
        cout << "Count = " << information -> Count << endl;
        cout << "Percentage = " <<information -> Percentage << endl;
        cout << "Rank = " <<information -> Rank << endl;              
    }
    else if(Name == "QUIT")
    {
        Tree.Print();
    }   
    else
    {
        cout << Name << " IS NOT FOUND.\n";
    }
    cout << "\n" << "\n";
}

void Analyzing_Tree(BinaryTree & Tree)
{
    cout << "\n" << "\n";
    cout<<"------------------" << endl;
    Tree.Count();
    Tree.Height();
    cout<<"------------------" << endl;
    cout << "\n" << "\n";
}
void Deletion(BinaryTree & Tree, string Name)
{
    if (Tree.Delete(Name))
	 cout << "Deleting " << Name << " succeeded\n";
    else
	 cout << "Deleting " << Name << " failed\n";  
    
    Analyzing_Tree(Tree);
}

int main() 
{
    BinaryTree Tree;
       
    //----------------- READING----------------------------
    cout << "Type input file name" << endl;
    string filename;
    cin >> filename;   
    Read(filename,Tree);  
    
    //----------------- ANALYZING----------------------------   
    Analyzing_Tree(Tree);
    
    //----------------- SEARCHING--------------------------
    cout << "Type Name for searching(First Letter should be Capital)." 
         <<" Type 'QUIT' for printing all names in alphabetical order." << endl;
    string SearchName;
    cin >> SearchName;
    Search(Tree,SearchName);
    
     //----------------- DELETING--------------------------
    cout << "Type Name for deleting.(First Letter should be Capital)" << endl;
    string DeleteName;
    cin >> DeleteName;
    Deletion(Tree,DeleteName);
    
    return 0;
}


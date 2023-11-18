

#include <iostream>
#include <string>

using namespace std;

class Inventory
{
public:
  string author;
  string title;
  int price;
  string publisher;
  int stock_position;

//this function get inputs from user and Store it to the class data member.
  void getData (string auth, string t, int p, string pub, int stock);


//this function display the array of object data.
 void getDisplay ();

//this function searches the availability of book that user wants from book inventory.
  int book_search (string t, string a);
};


//Here's main function start
int main ()
{
  Inventory books[3];//the area of object
//required variables
  string s_author = "Kuldeep";
  string s_title = "The Titan";
  int copy_num;

  cout << "Available books in inventory ::" << endl;
  //data for book 1
books[0].getData ("Kuldeep", "The Titan", 200, "NCERT", 20);
  books[0].getDisplay ();
  cout << "\n\n";
 
 // Data for book 2
  books[1].getData ("John Doe", "The Adventure", 150, "XYZ Publications", 15);
  books[1].getDisplay ();
  cout << "\n\n";

  // Data for book 3
  books[2].getData ("Jane Smith", "Mystery Unveiled", 180, "ABC Books", 25);
  books[2].getDisplay ();
  
  int found = 0;
//user input that he wants to search in array of object.
cout<<"\n\n Enter title of the book :";
cin>>s_title;
cout<<"\n Enter the author name :";
  cin>>s_author;
  
//loop which searches user input in area of object
  for (int i = 0; i < 3; i++)
    {

      found = books[i].book_search (s_title, s_author);
      if (found == 1)
	{
	  cout << "\n\nbook is found -> " << books[i].
	    title << " by " << books[i].author;

	  cout << "\n\nHow much copies do you need :";
	  cin >> copy_num;
	  if (copy_num <= books[i].stock_position)
	    {
	      cout << "The " << copy_num << " copies of this  book is yours!";
	      books[i].stock_position = books[i].stock_position - copy_num;
	      cout << "\n\n Now available copies of this book  in Inventory  :: ";
	      books[i].getDisplay ();
	    }else{
	        cout<<"\n\nSorry sir! right now We have only "<<books[i].stock_position<<" copies Available.";       
	   }
	  break;
	}
    }
  if (found == 0)
    {
      cout << "\n book not found";
    }
  return 0;
}

//inventory class getData() function definition
void Inventory::getData (string auth, string t, int p, string pub, int stock)
{
  author = auth;
  title = t;
  price = p;
  publisher = pub;
  stock_position = stock;
}

//inventory class getDisplay function definition
void Inventory::getDisplay ()
{
  cout << "\nAuthor: " << author;
  cout << "\nTitle: " << title;
  cout << "\nPrice: " << price;
  cout << "\nPublisher: " << publisher;
  cout << "\nStock: " << stock_position;
};

//inventory class book_search() function definition
int Inventory::book_search (string t, string a)
{
  if (title == t && author == a)
    {
      return 1;
    }
  else
    {
      return 0;
    }
};

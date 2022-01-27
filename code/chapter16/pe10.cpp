// pe10.cpp -- using STL functions and shared_ptr
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>


struct Review{
    std::string title;
    int rating;
    double price;
};
// using name
    using std::cin;
    using std::cout;
    using std::vector;
    using std::for_each;
    using std::shared_ptr;
    using std::sort;
    using std::copy;
    using std::insert_iterator;
// simplify the name
    typedef shared_ptr<Review> SpR;
    typedef vector<SpR>  VSpR;
    typedef insert_iterator<VSpR> insert_ir_VSpR;

bool FillReview(Review & rr);                           // input a book
SpR make_Review(Review & rr);       // return a shared_ptr of a book
void ShowMenu();                                        // display the menu
void ShowReview(const SpR spr);    // show a book
// compare the book of title 
bool operator<(const SpR spr1, const SpR spr2);
// compare the book of rating 
bool compare_rating(const SpR spr1, const SpR spr2);
// compare the book of price
bool compare_price(const SpR spr1, const SpR spr2);
void ShowBooks(const VSpR & vspr);
int main()
{
// input the book to books_spr
    VSpR books_ptr;
    vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books_ptr.push_back(make_Review(temp));
    
    VSpR temp_books_ptr;    // prototype a temp_books_ptr to restore result
// output menu
    ShowMenu();
// display books_list
    char choice;
    while (cin >> choice && choice != 'q')
    {
    // if input other char
        if(!strchr("abcdef",choice))
        {
            cout << "Please enter a a, b, c, d, e, f, q <q to quit>: ";
            continue;
        }
        switch (choice)
        {
            case 'a': cout << "Orignal order:\nRating\tPrice\tBook\n";
                      for_each(books_ptr.begin(), books_ptr.end(), ShowReview);
                      break;
            case 'b': temp_books_ptr.erase(temp_books_ptr.begin(), 
                            temp_books_ptr.end());
                      copy(books_ptr.begin(), books_ptr.end(), 
                            insert_ir_VSpR(temp_books_ptr, temp_books_ptr.begin()));
                      cout << "Letter order:\nRating\tPrice\tBook\n";
                      sort(temp_books_ptr.begin(), temp_books_ptr.end());
                      for_each(temp_books_ptr.begin(), temp_books_ptr.end(), ShowReview);
                      break;
            case 'c': temp_books_ptr.erase(temp_books_ptr.begin(), 
                            temp_books_ptr.end());
                      copy(books_ptr.begin(), books_ptr.end(), 
                            insert_ir_VSpR(temp_books_ptr, temp_books_ptr.begin()));
                      cout << "Rating ascending order:\nRating\tPrice\tBook\n";
                      sort(temp_books_ptr.begin(), temp_books_ptr.end(),compare_rating);
                      for_each(temp_books_ptr.begin(), temp_books_ptr.end(), ShowReview);
                      break;
            case 'd': temp_books_ptr.erase(temp_books_ptr.begin(), 
                            temp_books_ptr.end());
                      copy(books_ptr.begin(), books_ptr.end(), 
                            insert_ir_VSpR(temp_books_ptr, temp_books_ptr.begin()));
                      cout << "Rating decending order:\nRating\tPrice\tBook\n";
                      sort(temp_books_ptr.begin(), temp_books_ptr.end(),compare_rating);
                      for_each(temp_books_ptr.rbegin(), temp_books_ptr.rend(), ShowReview);
                      break;
            case 'e': temp_books_ptr.erase(temp_books_ptr.begin(), 
                            temp_books_ptr.end());
                      copy(books_ptr.begin(), books_ptr.end(), 
                            insert_ir_VSpR(temp_books_ptr, temp_books_ptr.begin()));
                      cout << "Price ascending order:\nRating\tPrice\tBook\n";
                      sort(temp_books_ptr.begin(), temp_books_ptr.end(),compare_price);
                      for_each(temp_books_ptr.begin(), temp_books_ptr.end(), ShowReview);
                      break;
            case 'f': temp_books_ptr.erase(temp_books_ptr.begin(), 
                            temp_books_ptr.end());
                      copy(books_ptr.begin(), books_ptr.end(), 
                            insert_ir_VSpR(temp_books_ptr, temp_books_ptr.begin()));
                      cout << "Price decending order:\nRating\tPrice\tBook\n";
                      sort(temp_books_ptr.begin(), temp_books_ptr.end(),compare_price);
                      for_each(temp_books_ptr.rbegin(), temp_books_ptr.rend(), ShowReview);
                      break;
        }
        ShowMenu();
    }
    cout << "Done";
    return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter the book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

SpR make_Review(Review & rr)
{
    return SpR(new Review(rr));
}
void ShowMenu()
{
    using std::cout;
    using std::endl;
    cout << "Choice the display order <q to quit>:\n";
    cout << "a: orignal order       b: letter order\n";
    cout << "c: rating ascending    d: rating decending\n";
    cout << "e: price ascendding    f: price decending\n";
    cout << "q: quit\n";
}

void ShowReview(const SpR spr)
{
    std::cout << spr->rating << "\t$" << spr->price << "\t" << spr->title << std::endl;
}

bool operator<(const SpR spr1, const SpR spr2)
{
    if (spr1->title < spr2->title)
        return true;
    else if (spr1->title == spr2->title && spr1->rating < spr2->rating)
        return true;
    else if (spr1->title == spr2->title && spr1->rating == spr2->rating
        && spr1->price < spr2->price)
        return true;
    else
        return false;
}

bool compare_rating(const SpR spr1, const SpR spr2)
{
    if (spr1->rating < spr2->rating)
        return true;
    else if (spr1->rating == spr2->rating && spr1->title < spr2->title)
        return true;
    else if (spr1->title == spr2->title && spr1->rating == spr2->rating
        && spr1->price < spr2->price)
        return true;
    else
        return false;
}

bool compare_price(const SpR spr1, const SpR spr2)
{
    if (spr1->price < spr2->price)
        return true;
    else if (spr1->price == spr2->price && spr1->title < spr2->title)
        return true;
    else if (spr1->title == spr2->title && spr1->price == spr2->price
        && spr1->rating < spr2->rating)
        return true;
    else
        return false;
}
    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    class Book{
    private:
        string title;
        string author;
        long long isbn;
        string availabilityStatus;

    public:

        Book(string t, string a, long long uCode, string status) : title(t), author(a), isbn(uCode), availabilityStatus(status) {
            cout << "Book Stored Successfully" << endl;
        }

        string getStatus(){
            return availabilityStatus;
        }

        long long getisbn(){
            return isbn;
        }

        void borrowBook(){
            if(availabilityStatus == "Available"){
                availabilityStatus = "Borrowed";
                cout << "You have successfully borrowed the book: " << title << endl;
            }
            else{
                cout << "Sorry, the book: " << title << " is currently not available." << endl;
            }
        }

        void returnBook(){
            availabilityStatus = "Available";
            cout << "You have successfully returned the book: " << title << endl;
        }

        void displayBookInfo(){
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "Availability Status: " << availabilityStatus << endl;
        }

        void SearchBook(int isbnToSearch){
            if(isbn == isbnToSearch){
                displayBookInfo();
            }
            else{
                cout << "Book with ISBN " << isbnToSearch << " not found." << endl;
            }
        }
    };

    int main(){

        string title, author;
        long long isbn;
        int n, i;
        string status;
        vector <Book> books;
        cout << "Enter Number of Books to Store: ";
        cin >> n;
        cin.ignore();

        for(i = 0; i < n; i++){
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            cout << "Enter Book ISBN: ";
            cin >> isbn;
            cin.ignore();
            cout << "Enter the Status of the Book (Available/Borrowed): ";
            getline(cin, status);

            Book book(title, author, isbn, status);
            books.push_back(book);
        }
        
        for(i =0; i < books.size(); i++){
            cout << "Details for Book " << i + 1 << ":" << endl;
            books[i].displayBookInfo();  
        }   

        int found = 0;
        long long searchIsbn;
        int index;

        cout << "Enter ISBN to search for and change the status: ";
        cin >> searchIsbn;
        while(found == 0){
            for(i = 0; i < books.size(); i++){
                if(books[i].getisbn() == searchIsbn){
                    books[i].SearchBook(searchIsbn);
                    found = 1;
                    index = i;
                    break;
                }
            }
            if(found == 0){
                cout << "Book with ISBN " << searchIsbn << " not found." << endl;
                cout << "Or Invalid ISBN Entered.";
            }
        }

        cout << "Enter the choice to borrow or return the book (1 for borrow, 2 for return): ";
        int choice;
        cin >> choice;

        switch(choice){
            case 1:
                books[index].borrowBook();
                break;
            case 2:
                books[index].returnBook();
                break;
            default:
                cout << "Invalid choice." << endl;
        }   

        for(i =0; i < books.size(); i++){
            cout << "Updated Details for Book " << i + 1 << ":" << endl;
            books[i].displayBookInfo();  
        }
        return 0;
    }
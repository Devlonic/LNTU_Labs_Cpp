#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Student
{
	int id;
	int marks[10];
	int mark_count = 0;
	string name;
};

void fun1() {
	Student db[10] = {
		{0, {1,2,3}, 3, "Vasya Pipko"},
		{1, {6,10,2}, 3, "Ivan Popko"},
	};
	int totalcount = 2;

	for (;;)
	{
		system("cls");
		cout << "1 - Add a student\n2 - Show a student by id\n3 - Add a mark to the student\n4- Print to readable file";
		char s;
		cin >> s;
		switch (s)
		{
		case '1': {
			Student newStudent;
			cout << "Enter name: ";
			cin >> newStudent.name;
			newStudent.id = totalcount++;
			db[totalcount - 1] = newStudent;
			cout << "Added student " << totalcount - 1;
			system("pause");
			break;
		};
		case '2': {
			int search_id;
			cout << "Enter student id: ";
			cin >> search_id;
			for (size_t i = 0; i < totalcount; i++)
			{
				if (db[i].id == search_id) {
					cout << "Student " << db[i].name << endl;
					cout << "marks: ";
					double avg = 0;
					for (size_t j = 0; j < db[i].mark_count; j++)
					{
						cout << db[i].marks[j] << " ";
						avg += db[i].marks[j];
					}
					cout << endl;
					cout << "average mark: " << avg / db[i].mark_count << endl;
					break;
				}
			}
			system("pause");
			break;
		};
		case '3': {
			int search_id;
			cout << "Enter student id: ";
			cin >> search_id;
			for (size_t i = 0; i < totalcount; i++)
			{
				if (db[i].id == search_id) {
					cout << "Enter marks. Enter -1 to exit: ";
					int mark = 0;
					for (; ;)
					{
						cin >> mark;
						if (mark == -1)
							break;
						db[i].marks[db[i].mark_count++] = mark;

					}
					break;
				}
			}
			system("pause");
			break;
		}
		case '4': {
			string s = "";
			ofstream fs("output.txt", ofstream::app);
			for (size_t i = 0; i < totalcount; i++)
			{
				fs << "\n=========================\n";
				fs << "Student " << db[i].name << endl;
				fs << "marks: ";
				double avg = 0;
				for (size_t j = 0; j < db[i].mark_count; j++)
				{
					fs << db[i].marks[j] << " ";
					avg += db[i].marks[j];
				}
				fs << endl;
				if (db[i].mark_count != 0)
					fs << "average mark: " << avg / db[i].mark_count << endl;
				fs << "=========================\n";

			}
			fs.flush();
			fs.close();
			break;

		}
		default:
			break;
		}
	}
}

class Book
{
public:
	string title;
	string author;
	double price;

public:
	Book(string title, string author, double price) {
		this->title = title;
		this->author = author;
		this->price = price;
	}
	void print() {
		cout << "\n========================" << endl;
		cout << "Title:\t" << title << endl;
		cout << "Author:\t" << author << endl;
		cout << "Price:\t" << price << endl;
		cout << "\n========================" << endl;
	}

	void print(int countRepeat) {
		for (size_t i = 0; i < countRepeat; i++)
		{
			print();
		}
	}

	~Book() {
		cout << "Book " << this->title << " was destroyed";
	}
private:

};

class BookStore {
private:
	vector<Book> booksStorage;
public:
	void add(Book book) {
		booksStorage.push_back(book);
	};
	void print_all() {
		for (size_t i = 0; i < booksStorage.size(); i++)
		{
			booksStorage[i].print();
		}
	}
	void print_all(int exclude_price_from_output) {
		for (size_t i = 0; i < booksStorage.size(); i++)
		{
			if (booksStorage[i].price != exclude_price_from_output)
				booksStorage[i].print();
		}
	}
	double total_cost() {
		double total = 0;
		for (size_t i = 0; i < booksStorage.size(); i++)
		{
			total += booksStorage[i].price;
		}
		return total;
	}

	~BookStore() {
		cout << "BookStore " << this->booksStorage.size() << " was destroyed";
	}
};



int main() {
	//fun1();
	BookStore bs;
	bs.add(Book("Book1", "Author1", 10));
	bs.add(Book("Book2", "Author1", 20));
	bs.add(Book("Book3", "Author2", 30));
	bs.add(Book("Book4", "Author3", 40));
	bs.print_all();
	cout << "Total cost: " << bs.total_cost() << endl;
}
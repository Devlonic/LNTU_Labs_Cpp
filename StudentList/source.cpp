#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

class CustomString {
private:
	char* data = nullptr;
	size_t length = 0;

	CustomString(char* allocated, size_t size) {
		cout << "create " << allocated << endl;
		length = size;
		data = allocated;
	}
public:
	CustomString(const char* value) {
		cout << "create " << value << endl;
		length = strnlen_s(value, ULLONG_MAX);

		data = new char[length + 1];
		strcpy_s(data, sizeof(char) * length + 1, value);
	}

	CustomString operator=(const char* s) {
		return CustomString(s);
	}

	CustomString operator+(const CustomString& s) {
		size_t buf_size = this->length + s.length + 1;
		char* new_data = new char[buf_size];
		new_data[0] = '\0';

		strcat_s(new_data, buf_size, this->data);
		strcat_s(new_data, buf_size, "world");

		return CustomString(new_data, buf_size - 1);
	}

	const char* c_str() {
		/*char* buffer = new char[this->length + 1];
		strcpy_s(buffer, this->length + 1, this->data);
		return buffer;*/
		return data;
	}

	CustomString substring(size_t copyFrom) {
		size_t new_length = (this->length + 1) - copyFrom;
		char* buffer = new char[new_length];
		strcpy_s(buffer, new_length, this->data + copyFrom);
		return CustomString(buffer, new_length - 1);
	}

	~CustomString() {
		cout << "destroy " << data << endl;
		delete[] data;
	}
};

int main() {
	CustomString myStr1("hello ");
	CustomString myStr2("world");
	CustomString concated = myStr1 + myStr2;
	cout << (concated.substring(2).c_str()) << endl;

	cout << concated.c_str() << endl;
}
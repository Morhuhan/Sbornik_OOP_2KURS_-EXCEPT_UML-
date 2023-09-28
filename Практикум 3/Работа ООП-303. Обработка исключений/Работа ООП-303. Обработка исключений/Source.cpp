#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <errno.h>


using namespace std;

struct file_error {
	string msg;
	file_error(const char* m) : msg(m) {}
	const char* messege() {
		return msg.c_str();
	}
};

struct fe_no_path : public file_error {
	fe_no_path() : file_error("No such file or directory") {}
};

struct fe_access_denied : public file_error {
	fe_access_denied() : file_error("Access denied") {}
};

struct fe_invalid_arg : public file_error {
	fe_invalid_arg() : file_error("Invalid arguments") {}
};



int open(const char* path, FILE** file) {
	*file = fopen(path, "rt");
	if (*file) return 1;
	if (errno == ENOENT) {
		cout << "No such file or directory" << endl;
	}
	else if (errno == EACCES) {
		cout << "Access denied" << endl;
	}
	else if (errno == EINVAL) {
		cout << "Empty or wrong path" << endl;
	}
	return 0;
}

void openc(const char* path, FILE** file) {
	*file = fopen(path, "rt");
	cout << errno << endl;
	if (errno) {
		throw errno;
	}
}

void opencl(const char* path, FILE** file) {
	*file = fopen(path, "rt");
	cout << errno << endl;
	if (errno == ENOENT) {
		throw fe_no_path();
	}
	else if (errno == EACCES) {
		throw fe_access_denied();
	}
	else if (errno == EINVAL) {
		throw fe_invalid_arg();
	}
}

class gen_err { virtual void foo() {} };
class file_err : public gen_err {};
class file_open_err : public file_err {};
class file_read_err : public file_err {};
class arrey_err : public gen_err {};
class arrat_bound_err : public arrey_err {};
class arrey_overflow_err : public arrey_err {};

struct m_class {

	char* a, * b;
	
	m_class(const char* a, const char* b) {
		//a = new char[20];
		//throw 1;
		__try {
			a = new char[20];
			b = new char[20];
			throw 1;
		}
		__finally {
			cout << "in finally\n";
			delete[] a;
			delete[] b;
		}
	}

	// Деструктор не освобождает память в случае исключения
	//~m_class() {
	//	cout << "in ~m_class()\n";
	//	if (a) delete[] a;
	//}
};

int main(void) {

	//int x = 3;
	//short z = 5;
	//
	//try {
	//	/*throw x;*/
	//	int y = 0;
	//	x = x / y;
	//} 

	//catch (int x) {
	//	cout << "int thrown " << x << endl;
	//}

	//catch (double x) {
	//	cout << "double thrown " << x << endl;
	//}

	//catch (char x) {
	//	cout << "char thrown " << x << endl;
	//}
	//catch (char* x) {
	//	cout << "char* thrown " << x << endl;
	//}

	//catch (...) {
	//	cout << "... thrown" << endl;
	//}

	//////////////////

	//FILE* file = 0;
	//int result = open("1.txt", &file);
	//if (!result) return 0;
	//cout << "Success!" << endl;

	//////////////////

	//FILE* file = 0;
	//
	//try {
	//	openc("1.txt", &file);
	//}

	//catch (int e) {
	//	if (e == ENOENT) {
	//		cout << "No such file or directory" << endl;
	//		return 1;
	//	}
	//	else if (e == EACCES) {
	//		cout << "Access denied" << endl;
	//		return 1;

	//	}
	//	else if (e == EINVAL) {
	//		cout << "Empty or wrong path" << endl;
	//		return 1;

	//	}
	//}
	//cout << "Success!" << endl;

	//////////////////

	//FILE* file = 0;

	//try {
	//	opencl("", &file);
	//}

	//catch (fe_no_path x) {
	//	cout << "fe_no_path" << endl;
	//	return 1;
	//}

	//catch (fe_access_denied x) {
	//	cout << "fe_access_denied" << endl;
	//	return 1;
	//}

	//catch (fe_invalid_arg x) {
	//	cout << "fe_invalid_arg" << endl;
	//	return 1;
	//}
	//cout << "Success!" << endl;

	//////////////////

	//FILE* file = 0;

	//try {
	//	opencl("12.txt", &file);
	//}

	//catch (file_error& e) {
	//	cout << e.messege() << ".\n";
	//}

	//////////////////

	//try {
	//	throw new file_open_err();
	//}

	//catch (arrey_err* e) {
	//	printf("catch 1: %s\n", typeid(*e).name());
	//}

	//catch (file_err* e) {
	//	printf("catch 2: %s\n", typeid(*e).name());
	//}
	//catch (gen_err* e) {
	//	printf("catch 3: %s\n", typeid(*e).name());
	//}
	//catch (...) {
	//	printf("catch all: Exception!\n");
	//}

	//////////////////

	try {
		m_class a("a", "b");
	}

	catch (int) {
		cout << "Excteption!\n";
		return 1;
	}

	cout << "Success!" << endl;

	return 0;
}
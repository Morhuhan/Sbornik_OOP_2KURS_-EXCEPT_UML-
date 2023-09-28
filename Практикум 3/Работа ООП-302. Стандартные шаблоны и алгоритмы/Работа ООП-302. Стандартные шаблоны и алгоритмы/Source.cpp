#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

typedef vector<int> intVector;
typedef list<int> intList;
typedef deque<int> intDeque;
typedef list<int>::iterator lister;

class product {
	string _name;
	int _price;
public:
	product(string name = "", int price = 0) {
		_name = name;
		_price = price;
	}

	int price() {
		return _price;
	}

	string name() {
		return _name;
	}

	friend ostream& operator<<(ostream& os, product p) {
		os << "product " << p.name() << "\tprice" << p.price() << endl;
		return os;
	}
};




// Функция для вывода элементов вектора
void showiv(intVector v) {
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	int j = 0;
	intVector::const_iterator i;
	for (i = v.begin(); i != v.end(); i++) {
		cout << "element" << j++ << " = " << *i << endl;
	}
}

// Функция для вывода элементов вектора
void showil(intList v) {
	cout << "size = " << v.size() << endl;
	int j = 0;
	intList::const_iterator i;
	for (i = v.begin(); i != v.end(); i++) {
		cout << "element" << j++ << " = " << *i << endl;
	}
}

// Предикат
int pred(int i) {
	return (i > 1);
}


// Печать
template <class T>
class Print : public unary_function <T, void> {
public:
	void operator() (T& arg) {
		cout << arg << " ";
	}
};

//template <class T>
//class Greater : public unary_function <T, int> {
//public:
//	int opertaor() (T& arg) {
//		return (arg > 2);
//	}
//};


int main(void) {

	//intVector iv1;
	//intVector iv2(10);
	//intVector iv3(iv2);

	//cout << "iv1 max_size = " << iv1.max_size() << endl;
	//cout << endl;

	//cout << "iv1 capacity = " << iv1.capacity() << endl;
	//cout << "iv2 capacity = " << iv2.capacity() << endl;
	//cout << endl;


	//cout << "iv1 size = " << iv1.size() << endl;
	//cout << "iv2 size = " << iv2.size() << endl;
	//cout << endl;


	//iv1.reserve(10);
	//cout << "iv1 capacity = " << iv1.capacity() << endl;
	//cout << "iv1 size = " << iv1.size() << endl;
	//cout << endl;

	//for (int i = 0; i < (int(iv2.size())); i++) {
	//	iv2[i] = i * 5;
	//}

	//try {
	//	// выбрасывает исключение
	//	int x = iv2.at(100);
	//}
	//catch (out_of_range) {
	//	cout << "Exception!" << endl;
	//	cout << endl;

	//}

	//cout << "iv2 front = " << iv2.front() << endl;
	//cout << "iv2 back = " << iv2.back() << endl;
	//cout << endl;

	//// пример использования прямого итератора
	//int j = 1;
	//intVector::iterator itor;
	//for (itor = iv2.begin(); itor != iv2.end(); itor++) {
	//	*itor = j++;
	//	cout << "element = " << *itor << endl;
	//}
	//cout << endl;

	//// пример использования обратного итератора
	//intVector::const_reverse_iterator rit;
	//for (rit = iv2.rbegin(); rit < iv2.rend(); ++rit) {
	//	cout << "element = " << *rit << endl;
	//}
	//cout << endl;
	//
	//cout << "\nadd one\n\n";
	//itor = iv2.insert(iv2.begin() + 5, 11);
	//cout << "current = " << *itor << endl;
	//showiv(iv2);

	//cout << "\nadd five\n\n";
	//iv2.insert(iv2.begin() + 6,5, 12);
	//showiv(iv2);

	//cout << "\nerase five\n\n";
	//iv2.erase(iv2.begin() + 6, iv2.begin() + 11);
	//showiv(iv2);

	//cout << "\nerase one\n\n";
	//iv2.erase(iv2.begin() + 5);
	//showiv(iv2);

	//cout << "\ninsert from\n\n";
	//intVector iv4(10, 50);
	//iv2.insert(iv2.begin() + 5, iv4.begin(), iv4.begin() + 5);
	//showiv(iv2);

	//cout << "\npush-back\n\n";
	//iv2.push_back(100);
	//showiv(iv2);
	//
	//cout << "\npop-back\n\n";
	//iv2.pop_back();
	//showiv(iv2);

	//cout << "\nclear\n\n";
	//iv2.clear();
	//showiv(iv2);


	/////////////// Операции

	//intVector iv1(5), iv2(5);
	//for (int i = 0; i < 5; i++) {
	//	iv1[i] = iv2[i] = i * 5;
	//}
	//showiv(iv1);
	//cout << endl;
	//showiv(iv2);
	//cout << endl;

	//if (iv1 == iv2) cout << "\nequal\n";

	//iv2.push_back(25);
	//if (iv1 < iv2) cout << "\nv1 < v2\n\n";

	//cout << "swap and compare" << endl;
	//iv1.swap(iv2);
	//iv1[1] = 0;
	//showiv(iv1);
	//cout << endl;
	//showiv(iv2);
	//cout << endl;
	//if (iv1 < iv2) cout << "\nv1 < v2\n";

	/////////////// Контейнер список

	//intList L1(5), L2(5, 1);
	//lister it;
	//int i = 0;
	//for (it = L1.begin(); it != L1.end(); it++) { *it = i++ * 5; }

	//i = 1;
	//for (it = L2.begin(); it != L2.end(); it++) { *it = i++; }

	//showil(L1);
	//cout << endl;

	//showil(L2);
	//cout << endl;

	//cout << "sllice" << endl;
	//L1.splice(++L1.begin(), L2, ++(++L2.begin()), --L2.end());

	//showil(L1);
	//cout << endl;

	//showil(L2);
	//cout << endl;

	//cout << "front add" << endl;

	//L1.pop_front();
	//L1.push_front(1);
	//showil(L1);
	//cout << endl;

	//cout << "merge" << endl;
	//L1.merge(L2);
	//*(++(L1.begin())) = 8;
	//showil(L1);
	//cout << endl;


	//cout << "reverse" << endl;
	//L1.reverse();
	//showil(L1);
	//cout << endl;

	//
	//cout << "sort" << endl;
	//L1.sort();
	//showil(L1);
	//showil(L2);
	//cout << endl;


	//cout << "merge sorted" << endl;
	//i = 0;
	//for (int i = 0; i < 5; i++) { L2.push_back(i); }
	//showil(L1);
	//cout << endl;

	///////////////// удаление элементов

	//intList L1(0);
	//L1.push_back(1);
	//L1.push_back(1);
	//L1.push_back(1);
	//L1.push_back(2);
	//L1.push_back(3);
	//L1.push_back(3);
	//L1.push_back(1);
	//L1.push_back(1);
	//showil(L1);
	//L1.remove(3);
	//showil(L1);
	//L1.unique();
	//showil(L1);
	//cout << endl;

	//cout << "predicate" << endl;

	//L1.remove_if(pred);
	//showil(L1);

	///////////////// контейнер дек
	
	//intDeque id;
	//for (int i = 0; i < 5; i++) {
	//	id.push_front(i);
	//	id.push_back(i);
	//}

	//intDeque::iterator it;
	//for (it = id.begin(); it != id.end(); it++) {
	//	cout << "element = " << "" << *it << endl;
	//}

	//for (int i = 0; i < 5; i++) {
	//	id.pop_front();
	//}

	//cout << endl;

	//for (it = id.begin(); it != id.end(); it++) {
	//	cout << "element = " << "" << *it << endl;
	//}

	///////////////// контейнер карта

	//product pen("pen", 10);
	//product ball("ball", 20);
	//product gum("gum", 15);

	//map<string, product> pmap;

	//pmap[pen.name()] = pen;
	//pmap[ball.name()] = ball;
	//pmap[gum.name()] = gum;

	//cout << "size = " << pmap.size() << endl;
	//cout << "pen price = " << pmap["pen"].price() << endl;

	//map<string, product>::iterator it;
	//for (it = pmap.begin(); it != pmap.end(); it++) {
	//	cout << it->first << "\t" << it->second;
	//}

	//cout << "count pen = " << pmap.count("pen") << endl;
	//cout << "find pen = " << pmap.find("pen")->second << endl;
	//it = pmap.lower_bound("ball");
	//cout << "lower_bound ball = " << it->second;
	//it = pmap.upper_bound("ball");
	//cout << "upper_bound ball = " << it->second;

	//cout << "\n insert" << endl;
	//product table("table", 99);
	//pair<string, product> tab("table", table);
	//pair<map<string, product>::iterator, bool> p = pmap.insert(tab);
	//if (p.second) cout << "added table\n";
	//else cout << "insert failed" << endl;
	//pmap.erase("table");
	
	///////////// алгоритмы

	Print<int> print;
	vector<int> v(5);
	typedef vector<int>::iterator itor;
	for (int i = 0; i < 5; i++) {
		v[i] = i;
	}
	itor first = v.begin();
	itor last = v.end();

	cout << "\nfor-each\n\n";
	for_each(first, last, print);

	//cout << "\n find-if\n\n";
	//Greater<int> preg;
	//itor r = find_if(first, last, preg);
	//if (r != last) cout << "find_if = " << *r << endl;


}
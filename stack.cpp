#include <iostream>
#include <string>
using namespace std;

class Stack{
	int *x1, *x2, n;
public:
	Stack() : n(0), x1(0), x2(0){}
		~Stack(){
		if (x1 != 0) delete[] x1;
		if (x2 != 0) delete[] x2;
		}
	void add(int x){ /** \func äîáàâëåíèå ýëåìåíòà â ñòåê */
		n++;
		if (x1 == 0){
			x1 = new int[n];
			for (int i = 0; i < n - 1; i++) x1[i] = x2[i];
			x1[n - 1] = x;
			x2 = 0;
			return;
		}
		x2 = new int[n];
		for (int i = 0; i < n - 1; i++) x2[i] = x1[i];
		x2[n - 1] = x;
		x1 = 0;
		return;
	}
	void del(){ /** \func óäàëåíèå ýëåìåíòà èç ñòåêà */
		n--;
		if (x1 == 0){
			x1 = new int[n];
			for (int i = 0; i < n; i++) x1[i] = x2[i];
			x2 = 0;
			return;
		}
		x2 = new int[n];
		for (int i = 0; i < n; i++) x2[i] = x1[i];
		x1 = 0;
		return;
	}
	void get(){ /** \func ïîëó÷åíèå âåðõíåãî ýëåìåíòà */
		if (x1 != 0) cout << x1[n - 1]<<endl;
		if (x2 != 0) cout << x2[n - 1]<<endl;
	}
};

void main(){
	int n; Stack A; string s;
	cin>> n;
	while (n){
		getline(cin,s);
		if (!s.find("add")){
			n--;
			s.erase(0, 4);
			int x = atoi(s.c_str());
			A.add(x);
		}
		if (s=="del"){
			n--;
			A.del();
		}
		if (s == "get"){
			n--;
			A.get();
		}
	}
	system("pause");
}

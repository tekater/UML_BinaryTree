#include <iostream>
using namespace std;



class Tree {
	class Element {
		int Data;
		//Element* parent;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			: Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor: \t" << this << endl;
		}
		~Element() {
			cout << "EDestrcutor: \t" << this << endl;
		}
	}*Root;

public:

	Tree() :Root(nullptr) {
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree() {
		cout << "TDestructor:\t" << this << endl;
	}



	/*Element* Search(Element* elem,int key) {

		return elem;
	}

	Element* Min(Element* elem) {

		return elem;
	}

	Element* Max(Element* elem) {

		return elem;
	}

	Element* Next(Element* elem) {

		return elem;
	}

	Element* Back(Element* elem) {

		return elem;
	}*/


};



int main()
{
	setlocale(0, "");




}


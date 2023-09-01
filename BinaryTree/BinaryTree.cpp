#include <iostream>
using namespace std;



class Tree {
protected:
	class Element {
		int Data;
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
		friend class Tree;
		friend class UniqueTree;
	}*Root;

public:
	Element* getRoot() {
		return Root;
	}
	Tree() :Root(nullptr) {
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree() {
		cout << "TDestructor:\t" << this << endl;
	}

	void Insert(int Data,Element* Root) {
		if (this->Root == nullptr) {
			this->Root = new Element(Data);
		}
		if (Root == nullptr) {
			return;
		}
		if (Data < Root->Data) {
			if (Root->pLeft == nullptr) {
				Root->pLeft = new Element(Data);
			}
			else {
				Insert(Data, Root->pLeft);
			}
		}
		else {
			if (Root->pRight == nullptr) {
				Root->pRight = new Element(Data);
			}
			else {
				Insert(Data, Root->pRight);
			}
		}
	}

	void Print(Element* Root) {
		if (Root != nullptr) {
			Print(Root->pLeft);
			cout << Root->Data << " ";
			Print(Root->pRight);
		}
	}

	int Min(Element* Root) {
		if (Root == nullptr) {
			return 0;
		}

		/*if (Root->pLeft == nullptr) {
			return Root->Data;
		}
		else {
			return Min(Root->pLeft);
		}*/

		return Root->pLeft == nullptr ? Root->Data : Min(Root->pLeft);
			
	}

	int Max(Element* Root) {
		if (Root == nullptr) {
			return 0;
		}

		/*if (Root->pRight == nullptr) {
			return Root->Data;
		}
		else {
			return Max(Root->pRight);
		}*/

		return Root->pRight == nullptr ? Root->Data : Max(Root->pRight);
	}

	int Sum(Element* Root,int sum = 0) {
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}

	int Count(Element* Root) {
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

	double Avg() {
		return Root == nullptr ? 0 : (double)Sum(Root) / Count(Root);
	}

	void Del(Element* Root) {
		if (Root != nullptr) {

			if (Root->pLeft != nullptr) {
				Del(Root->pLeft);
			}
			if (Root->pRight != nullptr) {
				Del(Root->pRight);
			}
			
			delete Root;
		}
	}

};

class UniqueTree:public Tree {
public:
	void Insert(int Data, Tree::Element* Root) {

		if (this->Root == nullptr) {
			this->Root = new Element(Data);
		}

		if (Root == nullptr) {
			return;
		}

		if (Data < Root->Data) {
			if (Root->pLeft == nullptr) {
				Root->pLeft = new Element(Data);
			}
			else {
				Insert(Data, Root->pLeft);
			}
		}
		else if (Data > Root->Data) {
			if (Root->pRight == nullptr) {
				Root->pRight = new Element(Data);
			}
			else {
				Insert(Data, Root->pRight);
			}
		}
	}
};

int main()
{
	setlocale(0, "");

	int n;
	Tree tree;

	//cout << "Введите размер дерева: "; cin >> n;
	n = 5;

	for (int i = 0; i < n; i++) {
		tree.Insert(rand() % 100,tree.getRoot());
	}

	cout << "\nPrint: "; 
	tree.Print(tree.getRoot()); 
	cout << endl << endl;

	cout << "Min: " << tree.Min(tree.getRoot()) << endl;
	cout << "Max: " << tree.Max(tree.getRoot()) << endl << endl;

	cout << "Sum: " << tree.Sum(tree.getRoot()) << endl;
	cout << "Counter: " << tree.Count(tree.getRoot()) << endl;

	/*tree.Del(tree.getRoot());

	cout << "\nPrint: ";
	tree.Print(tree.getRoot());
	cout << endl << endl;*/

	cout << "AVG: " << tree.Avg() << endl << endl;;

	
	UniqueTree utree;

	for (int i = 0; i < 200; i++) {
		utree.Insert(rand() % 100, utree.getRoot());
	}

	cout << "\nPrint: ";
	utree.Print(utree.getRoot());
	cout << endl << endl;

	cout << "Min: " << utree.Min(utree.getRoot()) << endl;
	cout << "Max: " << utree.Max(utree.getRoot()) << endl << endl;

	cout << "Sum: " << utree.Sum(utree.getRoot()) << endl;
	cout << "Counter: " << utree.Count(utree.getRoot()) << endl;

	cout << "AVG: " << utree.Avg() << endl << endl;


}

#pragma once
#include <iostream>
#include <ctime>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

int pSum = 0;
int pMax = 0;
int pMin = 0;
int pAvg = 0;
int pCount = 0;
int pDepth = 0;

template<typename T>
class Tree {
protected:
	class Element {
		T Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(T Data, Element* pLeft = nullptr, Element* pRight = nullptr)
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
	Element* getRoot();
	Tree();
	Tree(const std::initializer_list<int>& il);
	~Tree();

	void Insert(int Data) {
		Insert(Data, Root);
	}

	void Print() const {
		cout << "\n\nPrint:\n";
		Print(Root);
		cout << endl << endl;
	}
	void Clear() {
		Clear(Root);
		Root = nullptr;
	}

	int depth()const {
		return depth(Root);
	}

	int Sum()const {
		cout << "Sum:\t";
		return Sum(Root);
	}

	int Min()const {
		cout << "Min:\t";
		return Min(Root);
	}
	int Max()const {
		cout << "Max:\t";
		return Max(Root);
	}
	int Count()const {
		cout << "Count:\t";
		return Count(Root);
	}

	double Avg()const {
		pAvg++;
		cout << "AVG:\t";
		return Root == nullptr ? 0 : (double)Sum(Root) / Count(Root);
	}
	void erase(int Data) {
		erase(Data, Root);
	}
	void depth_print(int depth)const {
		cout << "Depth Print:\n";
		depth_print(Root, depth, 64);
	}
	void tree_Print()const {
		cout << "Tree Print\n";
		tree_Print(Root, 64);
	}
	void balance() {
		balance(Root);
	}
private:

	void Insert(T Data, Element* Root);

	void Print(Element* Root)const;

	int Min(Element* Root)const;

	int Max(Element* Root)const;

	void Clear(Element* Root);

	/*int Depth(Element* Root) {
		if (Root == nullptr) {
			return 0;
		}
		PDEPTH++;
		return Depth(Root->pLeft) + 1 < Depth(Root->pRight) + 1 ?
			Depth(Root->pRight) + 1 : Depth(Root->pLeft) + 1;
	}*/

	int depth(Element* Root)const;

	int Sum(Element* Root, int sum = 0)const;

	int Count(Element* Root)const;

	void erase(T Data, Element*& Root);

	void depth_print(Element* Root, int depth, int width) const;

	void tree_Print(Element* Root, int width, int depth = 0)const;

	void balance(Element* Root);
};


class UniqueTree :public Tree {
public:
	void Insert(int Data) {
		Insert(Data, Root);
	}
private:
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

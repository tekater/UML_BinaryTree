#pragma once
#include <iostream>
#include <ctime>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

//int pSum = 0;
//int pMax = 0;
//int pMin = 0;
//int pAvg = 0;
//int pCount = 0;
//int pDepth = 0;

template<class T> class Tree;
template<typename T> void measure(Tree<T>* tree, T(Tree<T>::* function)());

template<typename T>
class Tree {
protected:
	class Element {
		T Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(T Data, Element* pLeft = nullptr, Element* pRight = nullptr);
		~Element();
		friend class Tree;
		friend class UniqueTree;
	}*Root;

public:
	Element* getRoot();
	Tree();
	Tree(const std::initializer_list<int>& il);
	~Tree();

	void Insert(T Data);

	void Print() const;
	void Clear();

	int depth()const;

	int Sum()const;

	int Min()const;
	int Max()const;
	int Count()const;

	double Avg()const;
	void erase(T Data);
	void depth_print(int depth)const;
	void tree_Print()const;
	void balance();
private:

	void Insert(T Data, Element* Root);

	void Print(Element* Root)const;

	int Min(Element* Root)const;

	int Max(Element* Root)const;

	void Clear(Element* Root);

	int depth(Element* Root)const;

	int Sum(Element* Root, int sum = 0)const;

	int Count(Element* Root)const;

	void erase(T Data, Element*& Root);

	void depth_print(Element* Root, int depth, int width) const;

	void tree_Print(Element* Root, int width, int depth = 0)const;

	void balance(Element* Root);

	friend class Element;
};

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
		depth_print(Root, depth,64);
	}
	void tree_Print()const {
		cout << "Tree Print\n";
		tree_Print(Root,64);
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

template<typename T>
typename Tree<T>::Element* getRoot() {
	return Root;
}
template<typename T>
Tree<T>::Tree() {
	cout << "TConstructor:\t" << this << endl;
}
template<typename T>
Tree<T>::Tree(const std::initializer_list<int>& il) :Tree{
	for (T i : il) {
		Insert(i, Root);
	}
}

template<typename T>
Tree<T>::~Tree() {
	cout << "TDestructor:\t" << this << endl;
	Clear();
}

template<typename T>
void Tree<T>::Insert(T Data) {
	Insert(Data, Root);
}

template<typename T>
void Tree<T>::Print() const {
	cout << "\n\nPrint:\n";
	Print(Root);
	cout << endl << endl;
}
template<typename T>
void Tree<T>::Clear() {
	Clear(Root);
	Root = nullptr;
}

template<typename T>
int Tree<T>::depth()const {
	return depth(Root);
}

template<typename T>
int Tree<T>::Sum()const {
	cout << "Sum:\t";
	return Sum(Root);
}

template<typename T>
int Tree<T>::Min()const {
	cout << "Min:\t";
	return Min(Root);
}
template<typename T>
int Tree<T>::Max()const {
	cout << "Max:\t";
	return Max(Root);
}
template<typename T>
int Tree<T>::Count()const {
	cout << "Count:\t";
	return Count(Root);
}

template<typename T>
double Tree<T>::Avg()const {
	pAvg++;
	cout << "AVG:\t";
	return Root == nullptr ? 0 : (double)Sum(Root) / Count(Root);
}
template<typename T>
void Tree<T>::erase(T Data) {
	erase(Data, Root);
}
template<typename T>
void Tree<T>::depth_print(int depth)const {
	cout << "Depth Print:\n";
	depth_print(Root, depth, 64);
}
template<typename T>
void Tree<T>::tree_Print()const {
	cout << "Tree Print\n";
	tree_Print(Root, 64);
}
template<typename T>
void Tree<T>::balance() {
	balance(Root);
}

template<typename T>
void Tree<T>::Insert(T Data, Element* Root) {
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
			Tree<T>::Insert(Data, Root->pLeft);
		}
	}
	else {
		if (Root->pRight == nullptr) {
			Root->pRight = new Element(Data);
		}
		else {
			Tree<T>::Insert(Data, Root->pRight);
		}
	}
}

template<typename T>
void Tree<T>::Print(Element* Root)const {
	if (Root != nullptr) {
		Tree<T>::Print(Root->pLeft);
		cout << Root->Data << " ";
		Tree<T>::Print(Root->pRight);
	}
}

template<typename T>
int Tree<T>::Min(Element* Root)const {
	if (Root == nullptr) {
		return 0;
	}

	/*if (Root->pLeft == nullptr) {
		return Root->Data;
	}
	else {
		return Min(Root->pLeft);
	}*/

	pMin++;
	return Root->pLeft == nullptr ? Root->Data : Min(Root->pLeft);

}

template<typename T>
int Tree<T>::Max(Element * Root)const {
	if (Root == nullptr) {
		return 0;
	}

	/*if (Root->pRight == nullptr) {
		return Root->Data;
	}
	else {
		return Max(Root->pRight);
	}*/

	pMax++;
	return Root->pRight == nullptr ? Root->Data : Max(Root->pRight);
}

template<typename T>
void Tree<T>::Clear(Element* Root) {
	if (Root == nullptr) {
		return;
	}
	Tree<T>::Clear(Root->pLeft);
	Tree<T>::Clear(Root->pRight);
	delete Root;
}

/*int Depth(Element* Root) {
	if (Root == nullptr) {
		return 0;
	}
	PDEPTH++;
	return Depth(Root->pLeft) + 1 < Depth(Root->pRight) + 1 ?
		Depth(Root->pRight) + 1 : Depth(Root->pLeft) + 1;
}*/

template<typename T>
int Tree<T>::depth(Element* Root)const {
	if (Root == nullptr) {
		return 0;
	}

	//T l_depth = depth(Root->pLeft) + 1;
	//T r_depth = depth(Root->pRight) + 1;
	int l_depth = depth(Root->pLeft) + 1;
	int r_depth = depth(Root->pRight) + 1;
	pDepth++;

	return l_depth < r_depth ? r_depth : l_depth;
}

template<typename T>
int Tree<T>::Sum(Element* Root, int sum)const {
	pSum++;
	return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
}

template<typename T>
int Tree<T>::Count(Element* Root)const {
	pCount++;
	return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
}

template<typename T>
void Tree<T>::erase(T Data, Element*& Root) {
	if (Root == nullptr) {
		return;
	}
	Tree<T>::erase(Data, Root->pLeft);
	Tree<T>::erase(Data, Root->pRight);

	if (Data == Root->Data) {
		if (Root->pLeft == Root->pRight) {
			delete Root;
			Root = nullptr;
		}
		else {
			if (Count(Root->pLeft) > Count(Root->pRight)) {
				Root->Data = Max(Root->pLeft);
				Tree<T>::erase(Max(Root->pLeft), Root->pLeft);
			}
			else {
				Root->Data = Min(Root->pRight);
				Tree<T>::erase(Min(Root->pRight), Root->pRight);
			}
		}
	}
}

template<typename T>
void Tree<T>::depth_print(Element* Root, int depth, int width) const {
	if (Root == nullptr) {
		if (depth == 0) {
			cout.width(width * 2); cout << " ";
		}
		return;
	}

	if (depth == 0) {
		cout.width(width);
		cout << Root->Data;
		cout.width(width); cout << " ";
	}

	depth_print(Root->pLeft, depth - 1, width);
	depth_print(Root->pRight, depth - 1, width);
}

template<typename T>
void Tree<T>::tree_Print(Element* Root, int width, int depth)const {
	if (depth >= this->depth() || Root == nullptr) {
		return;
	}

	depth_print(Root, depth, width);

	cout << endl << endl << endl;

	tree_Print(Root, width / 2, depth + 1);

}

template<typename T>
void Tree<T>::balance(Element* Root) {
	if (Root == nullptr) {
		return;
	}

	if (abs(Count(Root->pLeft) - Count(Root->pRight)) < 2) {
		return;
	}

	if (Count(Root->pLeft) < Count(Root->pRight)) {
		if (Root->pLeft) {
			Tree<T>::Insert(Root->Data, Root->pLeft);
		}
		else {
			Root->pLeft = new Element(Root->Data);
		}
		Root->Data = Min(Root->pRight);
		Tree<T>::erase(Min(Root->pRight), Root->pRight);
	}
	else {
		if (Root->pRight) {
			Tree<T>::Insert(Root->Data, Root->pRight);
		}
		else {
			Root->pRight = new Element(Root->Data);
		}
		Root->Data = Max(Root->pLeft);
		Tree<T>::erase(Max(Root->pLeft), Root->pLeft);
	}
	Tree<T>::balance(Root->pLeft);
	Tree<T>::balance(Root->pRight);
	Tree<T>::balance(Root);
}

class UniqueTree :public Tree {
public:
	void Insert(int Data){
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

template<typename T>
void measure(const Tree& tree, T(Tree::* member_function)()const) {
	clock_t start = clock();
	T value = (tree.*member_function)();
	clock_t end = clock();
	cout << value << "\t" << " выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}

//#define BASE_CHECK
//#define DEPTH_CHECK
//#define Construct
#define BALANCE_CHECK

int main()
{
	setlocale(0, "");

#ifdef BASE_CHECK

	cout << "============================ Tree ============================\n";
	int n;
	Tree tree;

	//cout << "Введите размер дерева: "; cin >> n;
	n = 500;

	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		tree.Insert(rand() % 100);
	}
	clock_t end = clock();
	cout << "\n\nДерево заполнено за " << double(end - start) / CLOCKS_PER_SEC << " сек.\n";

	tree.Print();


#ifdef OLD_PREFORMANCE_CHECKDEBUG
	tree.time();
#endif // OLD_PREFORMANCE_CHECKDEBUG


	//measure("Минимальное значение в дереве: ", tree,&Tree::Min);
	measure(tree, &Tree::Min);
	measure(tree, &Tree::Max);
	measure(tree, &Tree::Sum);
	measure(tree, &Tree::Avg);
	measure(tree, &Tree::Count);
	cout << "Depth:\t"; measure(tree, &Tree::Depth);



	tree.Clear();
	//tree.Print();
	cout << "\n\n";

	cout << "~Счётчик запуска:";
	cout << "\nMAX: " << pMax << "\nMIN: " << pMin;
	cout << "\nCOUNT: " << pCount << "\nSUM: " << pSum;
	cout << "\nAVG: " << pAvg << "\nDEPTH: " << pDepth << "\n\n\n";



	cout << "========================= UniqTree ============================\n";
	UniqueTree utree;

	for (int i = 0; i < n; i++) {
		utree.Insert(rand() % 100);
	}

	utree.Print();

#ifdef OLD_PREFORMANCE_CHECKDEBUG
	utree.time();
#endif // OLD_PREFORMANCE_CHECKDEBUG

#endif // BASE_CHECK



#ifdef DEPTH_CHECK
	cout << "========================= DepthCheckTree ============================\n";

	Tree tree3 = { 50,25,75,16,32,64,90,28,29 };
	tree3.Print();

	//cout << tree3.Depth();
	measure(tree3, &Tree::depth);

	int value = 50;

	//cout << "Введите удаляемое значение: "; cin >> value;
	//tree3.erase(value);

	tree3.Print();
	int d = 0; //cout << "Введите глубину дерева:\n";cin >> d;

	//tree3.depth_print(d);

	tree3.tree_print();
#endif // DEPTH_CHECK

#ifdef BALANCE_CHECK 
	Tree tree = { 89,55,34,21,8,5,3};
	tree.tree_Print();
	tree.balance();
	tree.tree_Print();
#endif // BALANCE_CHECK



}

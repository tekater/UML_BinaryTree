#include "Binary.h"
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
int Tree<T>::Max(Element* Root)const {
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



template<typename T>
void measure(const Tree& tree, T(Tree::* member_function)()const) {
	clock_t start = clock();
	T value = (tree.*member_function)();
	clock_t end = clock();
	cout << value << "\t" << " выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}

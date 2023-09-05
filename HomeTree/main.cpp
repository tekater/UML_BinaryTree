#include <iostream>
#include <ctime>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

int PSUM = 0;
int PMAX = 0;
int PMIN = 0;
int PAVG = 0;
int PCOUNT = 0;
int PDEPTH = 0;

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
			cout << "EC.";
			//cout << "EConstructor: \t" << this << endl;
		}
		~Element() {
			cout << "ED.";
			//cout << "EDestrcutor: \t" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;

public:
	Element* getRoot() {
		return Root;
	}
	Tree() :Root(nullptr) {
		cout << "TC.\n";
		//cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) : Tree() {
		for (int i : il) {
			Insert(i, Root);
		}
	}
	~Tree() {
		cout << "TD.\n";
		//cout << "TDestructor:\t" << this << endl;
		Clear();
	}

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

	int Depth() {
		cout << "Depth: ";
		return Depth(Root);
	}

	int Sum()const {
		cout << "Sum: ";
		return Sum(Root);
	}

	int Min()const {
		cout << "Min: ";
		return Min(Root);
	}
	int Max()const {
		cout << "Max: ";
		return Max(Root);
	}
	int Count()const {
		cout << "Count: ";
		return Count(Root);
	}

	double Avg() {
		PAVG++;
		cout << "AVG: ";
		return Root == nullptr ? 0 : (double)Sum(Root) / Count(Root);
	}
	void time() {
		time(Root);
	}
private:

	void Insert(int Data, Element* Root) {
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

	void Print(Element* Root)const {
		if (Root != nullptr) {
			Print(Root->pLeft);
			cout << Root->Data << " ";
			Print(Root->pRight);
		}
	}

	int Min(Element* Root)const {
		if (Root == nullptr) {
			return 0;
		}

		/*if (Root->pLeft == nullptr) {
			return Root->Data;
		}
		else {
			return Min(Root->pLeft);
		}*/

		PMIN++;
		return Root->pLeft == nullptr ? Root->Data : Min(Root->pLeft);

	}

	int Max(Element* Root)const {
		if (Root == nullptr) {
			return 0;
		}

		/*if (Root->pRight == nullptr) {
			return Root->Data;
		}
		else {
			return Max(Root->pRight);
		}*/

		PMAX++;
		return Root->pRight == nullptr ? Root->Data : Max(Root->pRight);
	}

	void Clear(Element* Root) {
		if (Root == nullptr) {
			return;
		}
		Clear(Root->pLeft);
		Clear(Root->pRight);
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

	int Depth(Element* Root) {
		if (Root == nullptr) {
			return 0;
		}

		int l_depth = Depth(Root->pLeft) + 1;
		int r_depth = Depth(Root->pRight) + 1;

		PDEPTH++;

		return l_depth < r_depth ? r_depth : l_depth;
	}
	
	int Sum(Element* Root, int sum = 0)const {
		PSUM++;
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}

	int Count(Element* Root)const {
		PCOUNT++;
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

	void time(Element* Root) {
		clock_t start = clock();
		clock_t end = clock();
		start = clock();
		int min; int max;
		int depth; int avg;
		int sum; int count;
		cout << "\nТаймер:\n[1] - Min\n[2] - Max\n[3] - Sum\n";
		cout << "[4] - Count\n[5] - Avg\n[6] - Depth\n[7] - All\n";
		int action; cin >> action;
		switch (action) {
		case 1:
			start = clock();
			min = Min();
			end = clock();
			cout << min << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			break;
		case 2:
			start = clock();
			max = Max();
			end = clock();
			cout << max << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			break;
		case 3:
			start = clock();
			sum = Sum();
			end = clock();
			cout << sum << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			break;
		case 4:
			start = clock();
			count = Count();
			end = clock();
			cout << count << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			break;
		case 5:
			start = clock();
			avg = Avg();
			end = clock();
			cout << avg << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			cout << "\n";
			break;
		case 6:
			start = clock();
			depth = Depth();
			end = clock();
			cout << depth << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n\n";
			break;
		default:
			start = clock();
			min = Min();
			end = clock();
			cout << min << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";

			start = clock();
			max = Max();
			end = clock();
			cout << max << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			cout << "\n";

			start = clock();
			sum = Sum();
			end = clock();
			cout << sum << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";

			start = clock();
			count = Count();
			end = clock();
			cout << count <<", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";

			start = clock();
			avg = Avg();
			end = clock();
			cout << avg << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
			cout << "\n";

			start = clock();
			depth = Depth();
			end = clock();
			cout << depth << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n\n";
			break;
		}


		cout << "\n\n";
	}
};

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

#define BASE_CHECK
//#define DEPTH_CHECK

int main()
{
	setlocale(0, "");

#ifdef BASE_CHECK

	int n;
	Tree tree;
	clock_t start = clock();
	//cout << "Введите размер дерева: "; cin >> n;
	n = 500;

	for (int i = 0; i < n; i++) {
		tree.Insert(rand() % 100);
	}
	clock_t end = clock();
	cout << "\n\nДерево заполнено за " << double(end - start) / CLOCKS_PER_SEC << " сек.\n";
	
	//tree.Print();

	
	/*cout << tree.Min() << endl;
	cout << tree.Max() << endl << endl;

	
	cout << tree.Sum() << endl;
	cout << tree.Count() << endl;

	cout << tree.Avg() << endl << endl;;
	cout << tree.Depth() << endl;*/
	tree.time();

	tree.Clear();
	//tree.Print();
	cout << "\n\n";

	cout << "~Счётчик запуска:";
	cout << "\nMAX: " << PMAX << "\nMIN: " << PMIN;
	cout << "\nCOUNT: " << PCOUNT << "\nSUM: " << PSUM;
	cout << "\nAVG: " << PAVG << "\nDEPTH: " << PDEPTH << "\n\n\n";


	cout << "UniqTree:\n";
	UniqueTree utree;

	for (int i = 0; i < n; i++) {
		utree.Insert(rand() % 100);
	}
	
	//utree.Print();

	/*cout << utree.Min() << endl;
	cout << utree.Max() << endl << endl;

	cout << utree.Sum() << endl;
	cout << utree.Count() << endl;

	cout << utree.Avg() << endl << endl;
	cout << utree.Depth() << endl;*/

	utree.time();


	
#endif // BASE_CHECK





#ifdef DEPTH_CHECK

	Tree tree3 = { 50,25,75,16,32,64,90,28 };
	tree3.Print();

	cout << tree3.Depth() << endl;

#endif // DEPTH_CHECK

	

}

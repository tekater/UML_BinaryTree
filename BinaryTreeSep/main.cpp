#include "Binary.h"
#include "Bin.cpp"
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



//	cout << "========================= UniqTree ============================\n";
//	UniqueTree utree;
//
//	for (int i = 0; i < n; i++) {
//		utree.Insert(rand() % 100);
//	}
//
//	utree.Print();
//
//#ifdef OLD_PREFORMANCE_CHECKDEBUG
//	utree.time();
//#endif // OLD_PREFORMANCE_CHECKDEBUG

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
	Tree<int> tree = { 89,55,34,21,8,5,3};
	tree.tree_Print();
	tree.balance();
	tree.tree_Print();
#endif // BALANCE_CHECK



}

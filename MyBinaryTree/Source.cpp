#include <iostream>
#include <ctime>
#include "BTree.h"
using namespace std;
int main() {
	srand(unsigned(time(0)));
	BTree<int> tree1;
	tree1.add(4);
	cout << "Empty: " << tree1.isEmpty() << endl;
	cout << "Size: " << tree1.getSize() << endl;
	size_t amount = 7;
	for (size_t i = 0; i < amount; i++)
	{
		int data = rand() % 100;
		cout << "Add node " << data << endl;
		tree1.add(data);
	}
	tree1.print();
	//tree1.clear();
	cout<<"Max: "<<tree1.max()<<endl;
	cout << "New: " << endl;
	BTree<int> tree2;
	tree2.add(100);
	tree2.add(33);
	tree2.add(200);
	tree2.add(50);
	tree2.add(150);
	tree2.add(250);
	cout << boolalpha << tree2.find(200);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Print bigger" << endl;
	tree2.printBigger(33);
	return 0;
}
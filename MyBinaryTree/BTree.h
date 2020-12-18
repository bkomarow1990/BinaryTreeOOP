#pragma once
#include <iostream>
using namespace std;
template<typename T>
class BTree
{
public:
	BTree() = default;
	void add(const T& data);
	void print()const;
	void clear();

	//~BTree();
	const T& max()const;
	const T& min()const;
	bool find(const T& data)const;
	bool isEmpty()const;
	const size_t getSize()const;
	void printBigger(const T& data)const;
	~BTree();
private:
	
	struct Node {
		T data;
		Node* left,* right,*parent;
		Node(const T& data = T(), Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) 
			:data(data),left(left),right(right),parent(parent)
		{}
	};
	Node* root = nullptr;
	size_t size = 0;
	void printHelper(Node* node)const; // recursive func
	void clearHelper(Node * node);
};

template<typename T>
inline void BTree<T>::add(const T& data)
{
	Node* addNode = new Node(data);
	if (isEmpty())
	{
		root = addNode;
		return;
	}
	bool found = false; //Have in tree elems?
	Node* tmp = root;
	while (!found)
	{
		if (data > tmp->data)
		{
			if (tmp->right == nullptr)
			{
				tmp->right = addNode;
				addNode->parent = tmp;
				found = true;
			}
			else {
				tmp = tmp->right;
			}
		}
		else {
			if (tmp->left == nullptr)
			{
				tmp->left = addNode;
				addNode->parent = tmp;
				found = true;
			}
			else {
				tmp = tmp->left;
			}
		}
		
	}
	++size;
}

template<typename T>
inline void BTree<T>::print() const
{
	cout << "Tree " << endl;
	printHelper(root);
}

template<typename T>
inline void BTree<T>::clear()
{
	if (isEmpty())
	{
		return;
	}
	clearHelper(root);
}

template<typename T>
inline const T& BTree<T>::max() const
{
	if (isEmpty())
	{
		cout << "Empty" << endl;
		return T();
	}
	Node* res = root;
	while (res->right!=nullptr)
	{
		res=res->right;
	}
	return res->data;
}

template<typename T>
inline const T& BTree<T>::min() const
{
	if (isEmpty())
	{
		cout << "Empty" << endl;
		return T();
	}
	Node* res = root;
	while (res->left != nullptr)
	{
		res = res->left;
	}
	return res->data;
}

template<typename T>
inline bool BTree<T>::find(const T& data)const
{
	if (isEmpty())
	{
		return false;
	}
	Node* tmp=root;
	while (tmp!=nullptr)
	{
		if (data==tmp->data)
		{
			return true;
		}
		else if (tmp->data<data)
		{
			tmp = tmp->right;
		}
		else if (tmp->data>data)
		{
			tmp = tmp->left;
		}
	
	}
	return false;
}

template<typename T>
inline bool BTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline const size_t BTree<T>::getSize() const
{
	return size;
}

template<typename T>
inline void BTree<T>::printBigger(const T& data) const
{
	if (isEmpty())
	{
		return;
	}
	Node* temp = root;
	/* while (tmp!=nullptr)
	{
		if (data>tmp->data)
		{
			cout << tmp->data << endl;
		
		}
		tmp = tmp->right;
	
	}
	tmp = root;
	while (tmp != nullptr)
	{
		if (data > tmp->data)
		{
			cout << tmp->data << endl;

		}
		tmp = tmp->left;
	}*/
	//if (node != nullptr)
	//{
	//	printHelper(node->left);
	//	cout << node->data << "\t";
	//	printHelper(node->right);
	//}
	while (temp!=nullptr)
	{
		if (temp->data>data)
		{
			cout << temp->data << endl;
		}
		temp = temp->left;
	}
	//temp = root;
	while (temp != nullptr)
	{
		if (temp->data > data)
		{
			cout << temp->data << endl;
		}
		temp = temp->right;
	}

}

template<typename T>
inline BTree<T>::~BTree()
{
	clear();
}

template<typename T>
inline void BTree<T>::printHelper(BTree<T>::Node* node)const
{
	if (node!=nullptr)
	{
		printHelper(node->left);
		cout << node->data << "\t";
		printHelper(node->right);
	}
}

template<typename T>
inline void BTree<T>::clearHelper(Node* node)
{
	if (node!=nullptr)
	{
		clearHelper(node->left);
		clearHelper(node->right);
		cout << "~~~~ Deleted " << node->data << endl;
		delete node;
	}
}

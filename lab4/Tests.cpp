#include <iostream>
#include "BinaryTree.h"
using namespace std;

void BinTreeTest();

void startAllTests() {
	cout << "Binary Tree:\n";
	BinTreeTest();
}

void check(int flag, string msg) {
	if (flag)
		cout << "\t" << msg << " - OK\n";
	else
		cout << "\t" << msg << " - NO\n";
}

int plusOne_t(int a) {
	return a + 1;
}

int minusOne_t(int a) {
	return a - 1;
}

bool isMoreThan8_t(int a) {
	return a > 8;
}

void BinTreeTest() {
	string s = "9 6 3 1 4 8 7 17 16 12 11 14 20 19 18 21", tmp1 = "16 12 11 14", tpm2 = "10 7 4 2 5 9 8 18 17 13 12 15 21 20 19 22", tmp3 = "9 17 16 12 11 14 20 19 18 21";
	BinaryTree<int> tree(s), tree_tmp1(tmp1), tree_tmp2(tpm2), tree_tmp3(tmp3);
	check(BinaryTree<int>::equals(tree.getSubTree(16).getRoot(), tree_tmp1.getRoot()), "getSubTree");

	int (*pt2Func1)(int) = nullptr;
	pt2Func1 = &plusOne_t;
	tree.map(pt2Func1);
	check(BinaryTree<int>::equals(tree.getRoot(), tree_tmp2.getRoot()), "map");

	int (*pt2Func2)(int) = nullptr;
	pt2Func2 = &minusOne_t;
	tree.map(pt2Func2);

	BinaryTree<int> treeRes_where(9);
	bool (*pt2Func3)(int) = nullptr;
	pt2Func3 = &isMoreThan8_t;
	tree.where(treeRes_where, pt2Func3);
	check(BinaryTree<int>::equals(treeRes_where.getRoot(), tree_tmp3.getRoot()), "where");
	
	check((tree.find(16)) * (!tree.find(35)), "find");

	check(tree.isTreeEntry(tree_tmp1), "isTreeEntry");
}

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <string>
using std::string;

class BinaryTree;

class TreeNode{
public:
	TreeNode * mp_leftChd;
	TreeNode * mp_rightChd;
	TreeNode * mp_parent;
	string m_str;

	TreeNode();  //constructor
	TreeNode(string ss); //constructor overload
	friend class BinaryTree;
};


class BinaryTree{
public:
	TreeNode * mp_root;

	BinaryTree(); //constructor
	BinaryTree(TreeNode *p_node); //constructor overload

	void preOrder(TreeNode *p_cur);	 //VLR
	void inOrder(TreeNode *p_cur);	 //LVR
	void postOrder(TreeNode *p_cur); //LRV
	void levelOrder();	

};


#endif //BINARYTREE_H_
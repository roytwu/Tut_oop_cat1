#include <iostream>
#include "binaryTree.h"
using std::cout;
using std::endl;

int main(){
	cout << "Prorgrams starts here...." << endl;

	//node instantiaiton
	TreeNode *p_nodeA = new TreeNode("A");
	TreeNode *p_nodeB = new TreeNode("B");
	TreeNode *p_nodeC = new TreeNode("C");
	TreeNode *p_nodeD = new TreeNode("D");
	TreeNode *p_nodeE = new TreeNode("E");
	TreeNode *p_nodeF = new TreeNode("F");
	TreeNode *p_nodeG = new TreeNode("G");
	
	//construct binary tree
	p_nodeA->mp_leftChd = p_nodeB;
	p_nodeA->mp_rightChd = p_nodeC;

	p_nodeB->mp_leftChd = p_nodeD;
	p_nodeB->mp_rightChd = p_nodeE;

	p_nodeC->mp_rightChd = p_nodeF;
	p_nodeE->mp_leftChd = p_nodeG;

	/* The binary tree looks like this:
                      A
                    /   \
                   B     C
                  / \     \ 
                 D   E     F
                    /
                   G
	*/

	BinaryTree o_tree(p_nodeA);
	
	o_tree.preOrder(o_tree.mp_root); //V-L-R
	cout << endl;

	o_tree.inOrder(o_tree.mp_root); //L-V-R
	cout << endl;

	o_tree.postOrder(o_tree.mp_root); //L-R-V
	cout << endl;

	return 0 ;
}
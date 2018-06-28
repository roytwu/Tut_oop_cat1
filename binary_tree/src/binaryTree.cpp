#include <iostream>
#include "binaryTree.h"
using std::cout;
using std::endl;

/*----- -----Class TreeNode----- -----*/
TreeNode::TreeNode(){
	mp_leftChd  = nullptr;
	mp_rightChd = nullptr;
	mp_parent   = nullptr;
	m_str       = "";
}


TreeNode::TreeNode(string ss){
	mp_leftChd  = nullptr;
	mp_rightChd = nullptr;
	mp_parent   = nullptr;
	m_str       = ss;
}


/*----- -----Class BinaryTree----- -----*/
BinaryTree::BinaryTree(){ 
	mp_root = nullptr;
}


BinaryTree::BinaryTree(TreeNode *p_node){
	mp_root = p_node;
}

//pre-order: VLR
void BinaryTree::preOrder(TreeNode *p_cur){
	if(p_cur){
		cout << p_cur->m_str << " ";  //V
		preOrder(p_cur->mp_leftChd);  //L
		preOrder(p_cur->mp_rightChd); //R
	}
}	


//in-order: LVR
void BinaryTree::inOrder(TreeNode *p_cur){
	if(p_cur){
		inOrder(p_cur->mp_leftChd);  //L
		cout << p_cur->m_str << " "; //V
		inOrder(p_cur->mp_rightChd); //R
	}
}


//post-order: LRV
void BinaryTree::postOrder(TreeNode *p_cur){
	if(p_cur){
		postOrder(p_cur->mp_leftChd);  //L
		postOrder(p_cur->mp_rightChd); //R
		cout << p_cur->m_str << " ";   //V
		
	}	

}

//level order traversal: from left to right, level by level
void BinaryTree::levelOrder(){

}	



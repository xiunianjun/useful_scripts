#include <string.h>
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
////��һ��˫ָ��DFS�ݹ� 
//bool IsSymmetric(Tree left,Tree right){
//	if(left==NULL){
//		if(right!=NULL)
//			return false;
//		else
//			return true;
//	}
//	if(right==NULL&&left!=NULL)	return false;
//	if(left->val!=right->val)	return false;
//	if(!IsSymmetric(left->left,right->right))	return false;
//	if(!IsSymmetric(left->right,right->left))	return false;
//	return true;
//}
//bool isSymmetric(struct TreeNode* root){
//	return IsSymmetric(root,root);
//}

//������BFS�ǵݹ� 
//public boolean isSymmetric(TreeNode root) {
//    //����
//    Queue<TreeNode> queue = new LinkedList<>();
//    if (root == null)
//        return true;
//    //���ӽڵ�����ӽڵ�ͬʱ���
//    queue.add(root.left);
//    queue.add(root.right);
//    //������в�Ϊ�վͼ���ѭ��
//    while (!queue.isEmpty()) {
//        //ÿ��������
//        TreeNode left = queue.poll(), right = queue.poll();
//        //�����Ϊ�ռ���ѭ��
//        if (left == null && right == null)
//            continue;
//        //���һ��Ϊ��һ����Ϊ�գ�˵�����ǶԳƵģ�ֱ�ӷ���false
//        if (left == null ^ right == null)
//            return false;
//        //���������ֵ����ͬ��Ҳ���ǶԳƵģ�ֱ�ӷ���false
//        if (left.val != right.val)
//            return false;
//        //����Ҫ��ס��ӵ�˳������ÿ���������ĳ��ӡ�
//        //���ӽڵ�����ӽڵ�����ӽڵ�����ӽڵ�ͬʱ
//        //��ӣ���Ϊ������ͬʱ�Ƚϡ�
//        //���ӽڵ�����ӽڵ�����ӽڵ�����ӽڵ�ͬʱ��ӣ�
//        //��Ϊ������ͬʱ�Ƚ�
//        queue.add(left.left);
//        queue.add(right.right);
//        queue.add(left.right);
//        queue.add(right.left);
//    }
//    return true;
//}

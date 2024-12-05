- 动态查找：既查找又插入
#### BST（二叉排序树）：
代码：
- 查找结点：
```C
TreeNode *search(BinarySearchTree *bst,int num){
	TreeNode *cur=bst->root;
	while(cur!=NULL){
		if(cur->value<num){
			cur=cur->right;
		}
		if(cur->value>num){
			cur=cur->left;
		}
		else{
			break;
		}
	}
	return cur;
}
```
- 插入结点：（）注意记录前一个结点
```C
void insert(BinarySearchTree *bst,int num){
	TreeNode *cur=bst->root;
	TreeNode *pre=NULL;
	while(cur!=NULL){
		pre=cur;
		if(cur->value<num){
			cur=cur->right;
		}
		if(cur->value>num){
			cur=cur->left;
		}
		else{
			return; 
		}//找到了重复的，直接返回
	}
	TreeNode *node =newTreeNode(num);
	if(pre->value<num) pre->right=node;
	else pre->left=node;
}
```
- 删除结点：
	- 删除度为0的结点，即叶子节点
		- 可直接删除 (eg：pre.left=None;)
	- 删除度为1的结点
		- 将待删除的结点替换成其子结点(eg：pre.left=cur.right)
	- 删除度为2的结点：
		- 较为复杂
```C
void removeItem(BinarySearchTree *bst, int num{
	if(cur==NULL){
		return;
	}
	if(cur->left==NULL||cur->right==NULL){
		TreeNode *child=cur->left!=NULL?cur->left:cur->right;
		if(pre->left==cur){
			pre->left=child;
		}
		else{
			pre->right=child;
		}
		free(cur);
	}
	//度为2的结点删除
	else{
		TreeNode *temp=cur->right;
		while(tmp->left!=NULL){
			tmp=temp->left;	
		}
		int tmpVal=tmp->value;
		removeItem(bst,temp->value);
		cur->value=tmpVal;
	}
}
```

- ASL= $\log n$

#### AVL（平衡二叉树）：
- 定义：结点的height（即|depth_left-depth_right|<=1）的二叉排序树
- 若在AVL树中插入节点导致失衡，则有以下四种情况：
	-  LL平衡旋转
	- RR平衡旋转
	- LR平衡旋转
	- RL平衡旋转
```CSS
LL旋转：
        5                 3
       /                 / \
      3      ==》        2  5
     /    
    2  
```


```CSS
RR旋转：
        5                 6
         \               / \
          6      ==》    5  7
           \    
            7  
```


```CSS
LR旋转：
        5                 4
       /                 / \
      3       ==》       3  5
       \    
        4  
```


```CSS
RL旋转：
        5                 7
         \               / \
          7      ==》    5  6
         /      
        6  
```


#### 扩展：ASL查找失败的概率

- P(failure)=$\frac{m}{n}$
- 其中m为未查找到的元素数量
- n为需要查找的元素总量
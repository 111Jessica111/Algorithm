1.顺序查找

```C
int Linear_search(SStable ST,Keytype key){
	ST.elem[0].data=key;
	for(int i=ST.length;ST.elem[i].data!=key;i--);
	return i;
}
```

- ASL=$\frac{1+2+···+n}{n}$=$\frac{1+n}{2}$

2.折半查找
	1.需要采用顺序存储结构
	2.需要按关键字递增排序

```C
int binarySearch(int arr[], int size, int target){
	int left=0;
	int right=size-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(target<arr[mid]){
			right=mid-1;
		}
		if(target>arr[mid]){
			left=mid+1;
		}
		else
			return mid;
	}
	return -1;
}
```

ASL=$\frac{1}{n}\sum^{m}_{j=1}j*2^{j-1}$=$\log_{2}n$

3.分块查找：
- 思路：先让数据分块有序，即分成若干子表，要求每个子表中的数据元素值都比后一块中的数值小（但子表内部未必有序）。
- 然后将各子表中的最大关键字构成一个索引表，表中还要包含每个子表的起始地址（即头指针）。
- 样例:
![[Pasted image 20241204133240.png]]
![[Pasted image 20241204133313.png|200]]
- 步骤：
	-  对索引表使用折半查找法（因为索引表是有序表）；
	-  确定了待查关键字所在的子表后，在子表内采用顺序查找法（因为各子表内部是无序表）；
- ASL分析：
	- $ASL_{bc}=\log_{2}(\frac{n}{s}+1)+\frac{s}{2}$     ($\log_{2}n\leq ASL_{bs}\leq\frac{n+1}{2}$)
	- 其中n为表长，s为块状区域的长度，$\frac{n}{s}$为块状区域的个数


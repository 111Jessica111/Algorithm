#### next[j] 特征：

1. next[j]函数表征着模式T中最大相同前缀子串和后缀子串（真子串）的长度。
2. next[j]函数值越大，向右滑动得越慢，比较次数越多；反之，函数值越小，向右滑动得越快，则比较次数越少，时间越快。

#### next[j] 求法：
	J =            1 2 3 4 5 6 7 8 9 0 1 2 3 
	T =            L I U Y U L I U W E N Y U
	next[j] =      0 1 1 1 1 1 2 3 4 1 1 1 1 
	nextval[j] =   0 1 1 1 1 0 1 1 4 1 1 1 1 
	寻找最大字串，其长度加一为next[j]的值

#### next[j] 代码：

```C
void get_next(SString T, int  &next[ ] ){ 
	i=1; j=0; next[1]=0; 
	while(i<T[0]) //T[0]为T串之长度
	 { 
		if(j == 0||T[i] == T[j]){
			++i; 
			++j; 
			next[i]=j;
		} //首次必j=0
	    else j=next[j];
	 }
}
```

改进：

```C
void get_nextval(SString T, int  &nextval[ ] ){
	i=1;  
	nextval[1]=0; j=0;
	while(i<T[0] ){
    if(j= = 0||T[i]= =T[j] ){ 
	    ++i;
		++j;
		if(T[i]!=T[j] ) nextval[i]=j;
		else nextval[i]=nextval[j];
	}
	else j=nextval[j];  }
}
```
#### KMP算法实现Index():

```C
Int Index_KMP(SString S, SString T, int pos) { //见教材P82 
		i=pos; 
		j=1;
	    while ( i<=S[0] && j<=T[0] ) {
	        if (j==0|| S[i] = = T[j] ) {
		        ++i;
		        ++j;
		    }  
		    else j=next[j]
	    if(j>T[0]) return i-T[0];  //子串结束，说明匹配成功
		else return0;
}
```
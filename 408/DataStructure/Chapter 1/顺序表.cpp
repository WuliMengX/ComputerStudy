#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
#define MaxSize 10 
//静态顺序表
typedef struct 
{
  int data[MaxSize];
  int length;
}Sqlist;

//动态顺序表
typedef struct 
{
    int *data;    //数组指针，指示线性表基址
    int Maxsize;  //最大容量
    int length;   //当前长度
}SeqList;

//初始化
void InitList(SeqList &L){
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.Maxsize = InitSize;
}

//增加动态数组的长度 时间开销大
void IncreaseSize(SeqList &L, int len){

  int *p = L.data;

  L.data = (int *)malloc((L.Maxsize + len) * sizeof(int));

  for (int i = 0; i < L.length; i++)
  {
    L.data[i] = p[i];//复制数据到新区域
  }
  
  L.Maxsize = L.Maxsize + len;

  free(p);

}

//插入操作 平均循环次数 n/2

bool ListInsert(Sqlist &L,int i,int e){
  if (i < 1 || i > L.length+1)
    return false;
  if (L.length >= MaxSize)
    return false;
  
  for (int j = L.length; j >= i; j--)
  {
    L.data[j] = L.data[j-1];
  }

  L.data[i-1] = e;

  L.length++;

  return true;
  
}

//删除操作 平均循环次数 (n-1)/2

bool ListDelete(Sqlist &L,int i,int &e){    //此处的e必须是引用变量，涉及局部变量和全局变量
  if (i < 1 || i >L.length)
    return false;

  e = L.data[i-1];
  
  for (int j = i; j < L.length; j++)
  {
    L.data[j-1] = L.data[j];
  }

  L.length--;

  return true;
  
}

//查找操作 平均循环次数 (n+1)/2
//按指查找 结构体数据需要每一个结构变量相等才相等
int LocateElem(SeqList L,int e){
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == e)   
    {
      return i+1;                           //返回位序
    }
  }

  return 0;
}

//P18 综合题1
int smallestDelete(Sqlist &L){
  if (L.length == 0)
  {
    printf("顺序表为空！\n");
    exit(0);
  }

  int p = L.data[0],count = 0;
  for (int i = 1; i < L.length; i++)
  {
    if (p > L.data[i])
    {
      p = L.data[i];
      count = i;
    }
  }

  L.data[count] = L.data[L.length-1];
  return p;
}
//综合题2
void ReverseList(Sqlist &L){
  int temp;
  for (int i = 0; i < L.length/2; i++)
  {
    temp = L.data[i];
    L.data[i] = L.data[L.length-i];
    L.data[L.length-1] = temp;
  }
}
//综合题3
void xDelete(Sqlist &L,int x){
  int k = 0;
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] != x)
    {
      L.data[k] = L.data[i];
      k++;
    }
    L.length = k;
  }
}
//综合题4
bool stDeleteLine(Sqlist &L,int s,int t){
  if (s >= t || L.length == 0)
  {
    return false;
  }

  int i,j;
  for (i = 0; i < L.length && L.data[i] < s; i++);
  if (i>=L.length)
  {
    return false;
  }

  for ( j = i; j < L.length && L.data[j] > t; j++);
  for (; j < L.length; i++,j++)
  {
    L.data[i] = L.data[j];
  }

  L.length = i;

  return true;
}
//综合题5
bool stDelete(Sqlist &L,int s,int t){
  if (s >= t || L.length == 0)
  {
    return false;
  }

  int k = 0;
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] < s || L.data[i] > t)
    {
      L.data[k] = L.data[i];
      k++;
    }
  }
  
  L.length = k;
  return true;
}
//综合题6
bool dupDelete(Sqlist &L){
  if (L.length==0)
  {
    return false;
  }
  
  
  int i,j;
  for (i = 0,j = 1; j < L.length; j++)
  {
    if (L.data[i]!=L.data[j])
    {
      L.data[++i]=L.data[j];
    }
  }
  
  L.length=i+1;
  
  return true;
}
//综合题7  经典方法 牢固掌握 重点题型！
bool Merge(SeqList A,SeqList B,SeqList &C){
  if (A.length+B.length > C.Maxsize)
  {
    return false;
  }
  
  int i=0,j=0,k=0;
  while (i<A.length && j<B.length)
  {
    if (A.data[i]<=B.data[j])
    {
      C.data[k++]=A.data[i];
    }
    else
    {
      C.data[k++]=B.data[j];
    }
  }

  while (i<A.length)
  {
    C.data[k++] = A.data[i++];
  }
  while (j<B.length)
  {
    C.data[k++] = B.data[j++];
  }
  
  C.length=k;
  return true;
}












int main(){

    Sqlist L;
    L.length=0;
    for (int i = 0; i < MaxSize; i++)
    {
      printf("请输入结构体第%d个元素的值： \n",i+1);
      scanf("%d",&L.data[i]);
      L.length++;
    }

    printf("\n您输入的长度为%d的结构体数组列表为：\n",L.length);
    for (int i = 0; i < L.length; i++)
    {
      printf("%d ",L.data[i]);
    }

    printf("\n清除重复数字后的结构体数组列表为：\n");
    dupDelete(L);
    for (int i = 0; i < L.length; i++)
    {
      printf("%d ",L.data[i]);
    }
    
    return 0;
}
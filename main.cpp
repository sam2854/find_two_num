#include <iostream>
using namespace std;

void exchange(int &p,int &q){

    int temp = p;
    p =q;
    q = temp;
}

void heapAdjust(int *a,int i,int size)  
{
    int lchild=2*i;       
    int rchild=2*i+1;     
    int max=i;            
    if(i<=size/2)           
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            exchange(a[i],a[max]);
            heapAdjust(a,max,size);    
        }
    }        
}

void heapBuild(int *a,int size)    
{
    int i;
    for(i=size/2;i>=1;i--)   
    {
        heapAdjust(a,i,size);    
    }    
} 

void heapSort(int *a,int size)    
{
    int i;
    heapBuild(a,size);
    for(i=size;i>=1;i--)
    {
        exchange(a[1],a[i]);                    
        heapAdjust(a,1,i-1);      
    }
} 

void find(int a[],int len,int sum){
	int i = 0, j = len -1;
        while(i < j){
	    if(a[i]+a[j] < sum){
	        i++;
	    }else if(a[i]+a[j] > sum){
                j--;
            }else{
		cout << a[i] << " " << a[j] << endl;
                i++;
            }

       }
}



int main()
{
    int size,value,sum;
 
    cout << "请输入数组元素个数：" << endl;
    cin >> size;
    int *a=new int[size+1];
    cout << "请输入"<<size<<"个整数：" << endl;
    
    int i = 1;
    a[0] = 0;
    while( i <= size){
        cin >> value;
        a[i] = value;
        i++;
    }    
    
    cout << "请输入和:" << endl;
    cin >> sum;

    heapSort(a,size);

    cout << "和为" << sum <<"的两个数::" << endl;
    find(&a[1],size,sum);

    delete []a;

    return 0;
}

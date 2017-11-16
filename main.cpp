#include <iostream>
#include <vector>
 
using namespace std;


void exchange(int &p,int &q){

    int temp = p;
    p =q;
    q = temp;
}

int partition(int a[],int low,int high){

    int key = a[high];
    int i = low-1,j=low;
    for(; j<high; j++){
	if(a[j] <= key){
            i++;
            if(i != j){
                exchange(a[i],a[j]);
            }
        }
    }
    exchange(a[i+1],a[high]);
    return (i+1);
}

void quicksort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int index = partition(a,low,high);
    quicksort(a, low, index-1);
    quicksort(a, index+1, high);
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
    int length,value,sum;
 
    cout << "请输入数组元素个数：" << endl;
    cin >> length;
    int *a=new int[length];
    cout << "请输入"<<length<<"个整数：" << endl;
    
    int i = 0;
    while( i < length){
        cin >> value;
        a[i] = value;
        i++;
    }    
    
    cout << "请输入和:" << endl;
    cin >> sum;

    quicksort(a, 0, length - 1);

    cout << "和为" << sum <<"的两个数::" << endl;
    find(a,length,sum);

    delete []a;

    return 0;
}

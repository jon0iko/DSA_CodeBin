#include<iostream>
using namespace std;

struct Heap
{
    int arr[10000];
    int size = 0;

    void insertMax(int v)
    {
        arr[size] = v;
        size++;

        int current = size - 1;
        while (current > 0 && arr[current] > arr[(current - 1) / 2])
        {

            int temp = arr[current];
            arr[current] = arr[(current - 1) / 2];
            arr[(current - 1) / 2] = temp;

            current = (current - 1) / 2;
        }
    }


    int extract_max(){
        int max=arr[0];
        arr[0]=arr[size-1];
        size--;

       
        int current=0;
        while(current<size){
            int left=current*2+1;
            int right=current*2+2;
            int largest=-1;

            if(left<size) largest = left;
            if(right<size && arr[right]>arr[left]) largest=right;

            if(largest==-1) break;
           if(arr[largest]<arr[current])break;

           int temp=arr[largest];
           arr[largest]=arr[current];
           arr[current]=temp;            
           current=largest;
        }
        return max;
    }
};

int main()
{
    Heap *heap = new Heap();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        heap->insertMax(v);
    }

    for(int i=0;i<n;i++){
        cout<<heap->extract_max()<<endl;
    }
    return 0;
}
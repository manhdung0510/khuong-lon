#include <iostream>
using namespace std;
const int Max = 10000;

struct List{
    int size;
    int arr[Max];

    List(){
        size = 0;
    }

    //Truy cap : O(1)
    int get(int i){
        return arr[i];
    }

    //Chen phan tu vao dau : O(1)
    void addFirst(int data){
        for(int i = size; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = data;
        size++;
    }

    //Chen phan tu vao cuoi : O(1)
    void addLast(int data){
        arr[size] = data;
        size++;
    }

    //Chen vao vi tri i : O(N)
    void addindex(int pos, int data){
        for(int j = size; j > pos; j--){
            arr[j] = arr[j - 1];
        }
        arr[pos] = data;
        size++;
    }

    //Xoa phan tu dau : O(N)
    void removeFirst(){
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    //Xoa phan tu cuoi : O(1)
    void removeLast(){
        size--;
    }

    //Xoa vi tri i : O(N)
    void removeindex(int pos){
        for(int i = pos; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    //Duyet xuoi : O(N)
    void tranverseForward(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    //Duyet nguoc : O(N)
    void tranverseBackward(){
        for(int i = size - 1; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    List myList;
    
cout << "   Chen phan tu vao dau" << endl;
    myList.addFirst(5);
    myList.addFirst(10);
    myList.addFirst(2006);
    myList.tranverseForward();
    // Output : 2006 10 5
cout << "   Chen phan tu vao cuoi" << endl;
    myList.addLast(25);
    myList.addLast(9);
    myList.addLast(2025);
    myList.tranverseForward();
    // Output : 2006 10 5 25 9 2025
cout << "   Chen vao vi tri i" << endl;
    myList.addindex(3, 19);
    myList.tranverseForward();
    // Output : 2006 10 5 19 25 9 2025
cout << "   Xoa phan tu dau" << endl;
    myList.removeFirst();
    myList.tranverseForward();
    // Output : 10 5 19 25 9 2025
cout << "   Xoa phan tu cuoi" << endl;
    myList.removeLast();
    myList.tranverseForward();
    // Output : 10 5 19 25 9
cout << "   Xoa vi tri i" << endl;
    myList.removeindex(2);
    myList.tranverseForward();
    // Output : 10 5 25 9
cout << "   Duyet xuoi" << endl;
    myList.tranverseForward();
    // Output : 10 5 25 9
cout << "   Duyet nguoc" << endl;
    // Output : 9 25 5 10
    myList.tranverseBackward();
    return 0;
}

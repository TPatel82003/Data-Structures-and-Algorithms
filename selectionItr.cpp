
#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
void SelectionSort(vector<int>&Array){
    for(int i = 0 ; i < Array.size() ; i++){
       int Min = Array[i];
       int MinIndex = i;
       for(int j = i + 1 ; j < Array.size() ; j++){
        if(Min > Array[j]){
            MinIndex = j;
        }
       }
       if(MinIndex != i)
        swap(Array[i] , Array[MinIndex]);
    }
}
int main(){
    int Size;
    cout << "Enter Number Of Elements : ";
    cin >> Size;
    vector<int>Array(Size);
    srand(time(0));
       for(int i = 0 ; i < Size ; i++){
            Array[i] = rand()%10000;
        }
    auto start = high_resolution_clock::now();
    SelectionSort(Array);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << fixed << "Time Taken In MilliSecond : " << (double)duration.count()/1000  << setprecision(9) << endl;

}

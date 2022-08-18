#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int minIndex(vector<int>&Array , int i, int j)
{
    if (i == j)
        return i;
    int k = minIndex(Array, i + 1, j);
    return (Array[i] < Array[k])? i : k;
}
void SelectionSort(vector<int>&Array , int Index){
    if (Index == Array.size())
       return;
    int k = minIndex(Array, Index , Array.size());
    if (k != Index)
       swap(Array[k], Array[Index]);
    SelectionSort(Array, Index + 1);
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
    SelectionSort(Array , 0);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << fixed << "Time Taken In MilliSecond : " << (double)duration.count()/1000  << setprecision(9) << endl;
    for(auto i : Array)
    cout << i << " ";
}


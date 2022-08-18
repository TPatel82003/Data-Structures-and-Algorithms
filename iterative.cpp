#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
void InsertionSort(vector<int>&Array){
    for(int i = 1 ; i < Array.size() ; i++){
        int Curr = Array[i];
        int Index = i - 1;
        while(Index >=0 && Array[Index] > Curr ){
            Array[Index + 1] = Array[Index];
            Index -= 1;
        }
        Array[Index + 1] = Curr;
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
    InsertionSort(Array);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken In MilliSecond : "<< duration.count()/1000 << endl;

}

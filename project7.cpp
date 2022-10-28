/*
Ryan St. Mary
CPSC 122 Section 2
10/20/2022
Project 7
Binary search
generates an array of random nums when given size and limit on 
command line. sorts then searches for target also given on command line.
populates a file with the sorted array contents.

command line:
./a.out size limit target file

*/

using namespace std;
#include <fstream>
#include <iostream>
#include <cstdlib>


void bubbleSort(int[], int);
void sink(int[], int);
void shift(int[], int);
int binarySearch(int[], int, int);
void makeArr(int, int, int[]);
void sendArr(int[], int, string);

int main(int argc, char* argv[]){
    int size = atoi(argv[1]);
    int limit = atoi(argv[2]);
    int target = atoi(argv[3]);
    int* arr = new int[size];

    makeArr(size, limit, arr);

    // for (int i = 0; i<size; i++){
    //     cout << arr[i] << endl;
    // }
    bubbleSort(arr, size);
    if (binarySearch(arr, size, target) == -1){
        cout << target << " not found.\n";
    }
    else{
        cout << target << " found at index " << binarySearch(arr, size, target) << endl;
    }
    sendArr(arr, size, argv[4]);
    
    

    return 0;
}

// runs passes of sink on all the nums in the array
void bubbleSort(int arr[], int size)
{
 int pass = 0;
 int bottom = size;

 while(pass < size)
 { 
    sink(arr, bottom);
    bottom--;
    pass++;
 }
}

// checks to see if a num is bigger than all the other nums.
// shifts if it is
void sink(int arr[], int bottom)
{
 int cur = 0;
 while(cur < bottom - 1)
 {
    if (arr[cur] >= arr[cur+1]){
        shift(arr,cur);
    }
  cur++;
 }
}

// switches 2 ints in an array
void shift(int arr[], int cur)
{
 int temp = arr[cur];
 arr[cur] = arr[cur+1];
 arr[cur+1] = temp;
}

// binary search algorith derived from pseudo code
// checks middle of array for num, then divides possible
// range num is in using >< and checks middle again
int binarySearch(int arr[], int size, int target){
    
    
    int top = 0;
    int bottom = size - 1;
 
    while(top <= bottom)
    {
        int m = (top + bottom)/2;
        if (arr[m] == target){
            
            return m;
        }
        if (target < arr[m])
            bottom = m - 1;
        else
            top = m + 1;
        
    }
    
    return -1;

}

// generates random numbers and puts them into an array
void makeArr(int size, int limit, int arr[]){
    unsigned seed = time(NULL);
    srand(seed); 
    for (int i = 0; i < size; i++){
        arr[i] = rand()%limit + 1;
    }
}

// sends contents of an array to a file
void sendArr(int arr[], int size, string file){
    fstream fout;
    fout.open(file);

    for (int i = 0; i < size; i++){
        fout << arr[i] << endl;
    }
}
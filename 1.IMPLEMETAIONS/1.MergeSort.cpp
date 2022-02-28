#include <iostream>
using namespace std;

Time Complexity Analysis: The time complexity of MergeSort is O(n*Log n) in all the 3 cases (worst, average and best)
as the mergesort always divides the array into two halves and takes linear time to merge two halves.
Auxialary Space Complexity : O(n) and not O(nlogn) because at any moment in RAM you will need O(n) space because in recursion
tree the space allocated for one is deallocated and also we have recursion call stack space of log(n).

void merge(int arr[],int l,int m,int r){
    //l = 1, m = 3, r = 6
    int n1 = m - l + 1 , n2 = r - m;
    int arr1[n1];
    int arr2[n2];
    for(int i = 0 ; i < n1 ;i++) arr1[i] = arr[l+i];
    for(int i = 0 ; i < n2 ; i++) arr2[i] = arr[m+1+i];
    int indx = l;
    int i = 0 , j = 0;
    while(i < n1 and j < n2){
        if(arr1[i] < arr2[j]){
            arr[indx++] = arr1[i++];
        }
        else{
            arr[indx++] = arr2[j++];
        }
    }
    while(i < n1) arr[indx++] = arr1[i++];
    while(j < n2) arr[indx++] = arr2[j++];
}
void mergeSort(int arr[],int l,int r){

    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    //Now we have sorted arr from l to m and m+1 to r we just need to merge them.
    merge(arr,l,m,r);
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i = 0 ; i < n ;i++) cout<<arr[i]<<" ";
}

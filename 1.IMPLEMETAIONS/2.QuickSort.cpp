#include<bits/stdc++.h>
using namespace std;


int quickSelect(vector<int>&arr,int k){ // k smallest maal in 0(N)
//kth smallest maal ka indx in sorted array will be k-1.
    int lo = 0 , hi = arr.size()-1;

    while(lo <= hi){
    //Do normal partition with last maal as pivot and compare pi with k if
    //equal then return and if pi > k-1 then go to left and if pi < k-1 then
    //fgo to right side.
        int pivot = arr[hi];
        int pi = partition(arr,pivot,lo,hi);
        if(pi == k-1) return arr[pi];
        else if(pi > k-1) hi = pi-1; //search in left
        else if(pi < k-1) lo = pi+1; //search in right
    }
     
}
void sort012(vector<int>&arr){
    1.In partition //0 to j-1 === <= pivot maal
    //j to i-1 === >pivot maal
    //i to n-1 === Unknown.
    2. Sort 012 //i,j at start and k is at the end.
    //0 to j-1 is 0 maal
    //j to i-1 is 1 maal
    //i to k is unknown maal
    //k+1 to end is 2.
    //3 cases for a[i] when 
    //1. a[i] = 1 just do i++ i.e, just increase the window of 1.
    //2. a[i] = 0 swap a[i],a[j] i++ and j++ same as partition or sort01.
    //3. a[i] = 2 swap a[k],a[i] bcoz k+1 is start of 2 so just swap and do 
    //k--just swap a[k],a[i] and do k-- because k wale spot be guaranteed 
    //2 aagya so it can decrease and not i++ and 2 wla piche se grow krega.

}
T.C Analysis:
1. Best Case : When our pivot is median/mean and we devide the array equally then
at every level we have to do O(N) work for finding pivot and the number of levels
are logN so T.C = O(nlogn).
Auxilary Stack Space : O(logn) since at max logn levels of recursive tree can be 
drawn in best case.

2.Worst Case : When our parition fn divides array such that we have 1 element
on 1 side and n-1 on other side so here basically it will be skew tree and at 
every level again O(n) work for finding partition but level = n so T.C = O(n^2)
Then also it is preferred over MergeSort because it is inplace algo i.e, no need
of extra array saara khel same array me hi hota hai BRO.
Auxilary Stack Space : O(n) since at max n levels of recursive tree can be 
drawn in worst case.

3.Average Case : O(nlogn)

int partition(vector<int>&arr,int pivot,int lo,int hi){
    //0 to j-1 === <= pivot maal or lo to j-1.
    //j to i-1 === >pivot maal  or j to i-1.
    //i to n-1 === Unknown or i to hi.
    int i=lo,j= lo;
    while(i <=  hi){
        if(arr[i] > pivot) i++;
        else if(arr[i] <= pivot){
            swap(arr[j],arr[i]);
            j++;
            i++;
        }
    }
    return j-1;
}

void quickSort(vector<int>&arr,int lo,int hi){
    if(lo >= hi) return; //Base Case when both have 1 maal to return.
    //Just do a partition with last maal as pivot and sort recursively rest.
    //pivot is last maal and partition fn se pivot sahi jagah aajata hai and
    //now we just need to sort [l:p-1] and [p+1:r] and this will do by having
    //faith on recursion.
    int pivot = arr[hi];
    int pi = partition(arr,pivot,lo,hi);
    quickSort(arr,lo,pi-1);
    quickSort(arr,pi+1,hi);
}
int main() {
    int n; cin>>n;
    vector<int>arr(n); for(int i = 0 ; i < n ; i++) cin>>arr[i];
    for(int x: arr) cout<<x<<"  ";
    cout<<endl;
    quickSort(arr,0,n-1);
    for(int x: arr) cout<<x<<"  ";
}

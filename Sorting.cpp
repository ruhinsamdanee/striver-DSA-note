#include <bits/stdc++.h> 
using namespace std;

void print_sorted_array(string name , vector<int> arr){
    cout << name ;
    for (int x : arr) cout << x << " " ;
    cout << endl ;
}
//1.Bubble Sort :
void bubble_sort(vector<int> &arr){
    int n = arr.size() ;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if(arr[i] > arr[j]) swap(arr[i] , arr[j]) ;
        }
    }
    print_sorted_array("Bubble Sort :" ,arr) ;
}

//2.Selection Sort :
void selection_sort(vector<int> &arr){
    for (int i = 0; i < arr.size(); ++i){
        int min = i ;
        for (int j = i+1; j < arr.size(); ++j){
            if(arr[j] < arr[min]) min = j ;
        }
        swap(arr[i] , arr[min]) ;
    }
    print_sorted_array("Selection Sort : " ,arr) ;
}

//3.Insertion Sort :
void insertion_sort(vector<int> &arr){
    for (int i = 0; i < arr.size(); ++i){
        int j = 0 ;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1] , arr[j]) ;
            j-- ;
        }
    }
    print_sorted_array("Insertion Sort : " ,arr) ;
}

//4.Merge Sort :
    void merge(vector<int> &arr , int low , int mid , int high){
        vector<int> temp ;
        int left = low ;
        int right = mid + 1 ;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++ ;
            }
            else{
                temp.push_back(arr[right]) ;
                right++ ;
            }            
        }   
        while(left <= mid){
        temp.push_back(arr[left]) ;
        left++ ;
        }
        while(right <= high){
            temp.push_back(arr[right]) ;
            right ++ ;
        }
        for (int i = low; i <= high; ++i){
            arr[i] = temp[i- low] ;
        }
    }

    void ms(vector<int> &arr , int low , int high){
        if(low >= high) return ;
        int mid = low +(high - low)/2 ;
        ms(arr , low , mid);
        ms(arr , mid + 1 , high) ;
        merge(arr , low , mid , high) ;
    }
void merge_sort(vector<int> &arr , int size){
    if(size <= 0) return ;
    ms(arr , 0 , size-1) ;
    print_sorted_array("Merge Sort : " ,arr) ;
}

//5.Quck Sort :
    int partition(vector<int>&arr , int low , int high){
        int pivot = arr[low] ;
        int i = low ;
        int j = high ;
        while(i < j){
            while(arr[i] <= pivot && i <= high  - 1) i++ ;
            while(arr[j] > pivot && j >= low + 1) j-- ;
            if(i < j) swap(arr[i] , arr[j]);
        }
    }
    void qs(vector<int> &arr , int low , int high){
        if(low < high){
            int p_index = partition(arr, low , high) ;
            qs(arr , low , p_index - 1) ;
            qs(arr ,p_index + 1 , high) ;
        }
    }
void quick_sort(vector<int> arr , int size){
    if(size <= 0) return ;
    qs(arr , 0 , size - 1) ;
    print_sorted_array("Quick Sort : " ,arr) ;
}

int main() {
    vector<int> arr ;
    int n ; 
    while(cin >> n){
        arr.push_back(n) ;
    }
    int size = arr.size() ;

    bubble_sort(arr) ;
    selection_sort(arr);
    insertion_sort(arr) ;
    merge_sort(arr,size) ; 
    quick_sort(arr,size) ;
    return 0; 
}
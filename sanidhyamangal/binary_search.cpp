#include<iostream>
#include<vector>

using namespace std;

int binary_search(vector<int> array, int search_term){
   int low =0, high = array.size();

   while (low <= high)
   {
       int mid = (low + high) / 2;
       if (search_term == array[mid]){
           return mid;
       }
       else if (search_term > array[mid]){
           low = mid +1;
       }
       else{
           high = mid -1;
       }
   }

   return -1;
}

int main(){
    vector<int> temp = vector<int>{2,3,5,6,9};
    cout << binary_search(temp, 6);
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

vector<int> insertion_sort(vector<int> array){
    int key, j;
    for (int i = 1; i < array.size(); i++)
    {
        key = array[i];
        j = i-1;

        while (j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j -=1;
        }

        array[j+1] = key;
        
    }
    return array;
       
}

void print_vector(vector<int> array){
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] <<"\t";
    }
}

int main(){
    vector<int> temp = vector<int>{2,5,3,1};
    print_vector(insertion_sort(temp));

    return 0;
}
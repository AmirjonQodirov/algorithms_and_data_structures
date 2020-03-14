# include <bits/stdc++.h>

using namespace std;
int const length = 9;
int arr[length] = {2, 2, 8, 9, 5, 0, 4, 8, 9};
int counter = 0;

void select_sort() {
    int tmp = 0;
    for (int i = 0; i < length - 1; ++i) {
        counter++;
        int min_id = i;
        for (int j = i; j < length; ++j) {
            counter++;
            if (arr[j] < arr[min_id])
                min_id = j;
        }
        if (min_id != i) {
            tmp = arr[i];
            arr[i] = arr[min_id];
            arr[min_id] = tmp;
        }
    }
}

void insertion_sort() {
    for (int i = 1; i < length; ++i) {
        counter++;
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            counter++;
            arr[j + 1] = arr[j];
            arr[j] = key;
            j--;
        }
    }


}


int main() {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << counter;
}

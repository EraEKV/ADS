#include <iostream>

using namespace std;

int binarySearchDec(int arr[], int l, int r, int x) { 
 while (l <= r) { 
  int mid = l + (r - l) / 2; 

  if (arr[mid] == x) 
   return mid;

  if (arr[mid] > x) 
   l = mid + 1; 
  else
   r = mid - 1; 
 } 

 return -1; 
}

int binarySearchInc(int arr[], int l, int r, int x) { 
 while (l <= r) { 
  int mid = l + (r - l) / 2; 

  if (arr[mid] == x) 
   return mid;

  if (arr[mid] < x) 
   l = mid + 1; 
  else
   r = mid - 1; 
 } 

 return -1; 
}


int main() {
    int n, d, k; cin >> n;
    int find[n];
    for(int i = 0; i < n; i++) {
        cin >> find[i];
    }
    cin >> d >> k;
    int numbers[d][k];
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < k; j++) {
            cin >> numbers[i][j];
        }
    }
    int y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d; j++) {
            if(j % 2 == 0) {
                y = binarySearchDec(numbers[j], 0, k - 1, find[i]);
            } else {
                y = binarySearchInc(numbers[j], 0, k - 1, find[i]);
            }

            if(y != -1) {
                cout << j << " " << y << endl;
                break;
            }
        }
        if(y == -1) {
            cout << -1 << endl;
        }
    }

    return 0;
}
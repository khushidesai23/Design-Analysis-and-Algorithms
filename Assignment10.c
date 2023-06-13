//Khushi Desai
//21BCP264

#include <stdio.h>

int find_peak(int A[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] < A[mid + 1]) {  // peak lies to the right
            left = mid + 1;
        } else {  // peak lies to the left or at mid
            right = mid;
        }
    }
    return left;  // or right, both are the peak element
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // int n = sizeof(A) / sizeof(A[0]);
    int peak = find_peak(A, n);
    printf("The peak element is %d at index %d\n", A[peak], peak);
    return 0;
}
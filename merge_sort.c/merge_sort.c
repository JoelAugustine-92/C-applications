#include <stdio.h>

void sort(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1], r[n2];

    for (i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        r[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        sort(arr, left, mid, right);
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void readme(int arr[], int size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

int main() {
    int arr[100];
    int size;
    printf("Enter the array size : ");
    scanf("%d", &size);
    printf("Enter the array elements: \n");
    readme(arr, size);
    printf("sorting..........\n");
    mergesort(arr, 0, size - 1);
    printf("The sorted array is : \n");
    display(arr, size);
    return 0;
}


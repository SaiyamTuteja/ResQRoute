// #include <stdio.h>
// void merge(int arr[], int left, int mid, int end)
// {
//     int n1 = mid - left + 1;
//     int n2 = end - mid;
//     int l[n1], r[n2];
//     for (int i = 0; i < n1; i++)
//     {
//         l[i] = arr[left + i];
//     }
//     for (int j = 0; j < n2; j++)
//     {
//         r[j] = arr[mid + 1 + j];
//     }
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2)
//     {
//         if (l[i] < r[j])
//         {
//             arr[k] = l[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = r[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1)
//     {
//         arr[k] = l[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         arr[k] = r[j];
//         j++;
//         k++;
//     }
// }
// void mergeSort(int arr[], int start, int end)
// {
//     if (start < end)
//     {
//         int mid = start + (end - start) / 2;
//         mergeSort(arr, start, mid);
//         mergeSort(arr, mid + 1, end);
//         merge(arr, start, mid, end);
//     }
// }
// void printArray(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf(" %d ", arr[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int arr[] = {38, 27, 43, 3, 9, 82, 10};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     printf("Original array: ");
//     printArray(arr, size);

//     mergeSort(arr, 0, size - 1);

//     printf("Sorted array: ");
//     printArray(arr, size);
//     return 0;
// }

// #include <stdio.h>
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }
// void QuickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
//         QuickSort(arr, low, pi - 1);
//         QuickSort(arr, pi + 1, high);
//     }
// }
// void printArr(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf(" %d ", arr[i]);
//     }
//     printf("\n");
// }
// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     printf("Original array: ");
//     printArr(arr, size);

//     QuickSort(arr, 0, size - 1);

//     printf("Sorted array: ");
//     printArr(arr, size);

//     return 0;
// }

// #include <stdio.h>

// void swap(char *a, char *b)
// {
//     char temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void permuteWithoutRepetition(char str[], int l, int r)
// {
//     if (l == r)
//     {
//         printf("%s\n", str);
//         return;
//     }
//     for (int i = l; i <= r; i++)
//     {
//         swap(&str[l], &str[i]);
//         permuteWithoutRepetition(str, l + 1, r);
//         swap(&str[l], &str[i]); // backtrack
//     }
// }

// int main()
// {
//     char str[] = "ABC";
//     int n = 3;

//     printf("Permutations without repetition:\n");
//     permuteWithoutRepetition(str, 0, n - 1);

//     return 0;
// }




// #include <stdio.h>

// void permuteWithRepetition(char set[], int n, char result[], int r, int depth) {
//     if (depth == r) {
//         result[depth] = '\0';   // null terminate
//         printf("%s\n", result);
//         return;
//     }
//     for (int i = 0; i < n; i++) {
//         result[depth] = set[i];
//         permuteWithRepetition(set, n, result, r, depth + 1);
//     }
// }

// int main() {
//     char set[] = {'A', 'B', 'C'};
//     int n = 3;
//     int r = 2;   // length of permutation
//     char result[r + 1];

//     printf("Permutations with repetition:\n");
//     permuteWithRepetition(set, n, result, r, 0);

//     return 0;
// }





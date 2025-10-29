#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  
}

void generate_sorted_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;  // Generate sorted array: 0, 10, 20, 30, ...
    }
}

int main() {
    FILE *output_file;
    clock_t start, end;
    double cpu_time_used;
    
    int input_sizes[] = {1000, 5000, 10000, 50000, 100000, 300000, 500000, 600000, 700000, 800000};
    int num_sizes = sizeof(input_sizes) / sizeof(input_sizes[0]);
    
    output_file = fopen("results.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not create binary_search_results.txt\n");
        return 1;
    }
    fprintf(output_file, "Array_Size,Time_Taken(seconds)\n");
    srand(time(NULL));
    
    printf("Binary Search Analysis\n");
    printf("======================\n");
    for (int i = 0; i < num_sizes; i++) {
        int array_size = input_sizes[i];
        printf("Processing array of size: %d\n", array_size);
        
        // Allocate memory for array
        int *arr = (int*)malloc(array_size * sizeof(int));
        if (arr == NULL) {
            printf("Error: Memory allocation failed for size %d\n", array_size);
            continue;
        }
        generate_sorted_array(arr, array_size);
        int target = -1;  // This ensures worst-case scenario

        // Measure time for binary search
        start = clock();
        int iterations = 10000000;  
        for (int j = 0; j < iterations; j++) {
            int result = binary_search(arr, array_size, target);
        }
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC / (double)iterations;  
        printf("Time taken: %.9f seconds\n", cpu_time_used);  

        // Write result to file (with more precision)
        fprintf(output_file, "%d,%.9f\n", array_size, cpu_time_used);
        free(arr);
    }
    fclose(output_file);
    printf("\nAnalysis completed. Results saved to results.txt\n");
    return 0;
}

        
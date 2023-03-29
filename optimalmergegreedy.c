#include <stdio.h>
#include <stdlib.h>

// Function to calculate the optimal merge pattern
int optimal_merge_pattern(int files[], int n) {
    // Sort the files in ascending order of their sizes
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (files[i] > files[j]) {
                int temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Initialize the total cost to 0
    int total_cost = 0;

    // Continue merging until there is only one file left
    while (n > 1) {
        // Get the two smallest files
        int smallest_file1 = files[0];
        int smallest_file2 = files[1];

        // Calculate the cost of merging the two smallest files
        int cost = smallest_file1 + smallest_file2;
        printf("the merging of %d and %d is %d\n",smallest_file1 ,smallest_file2,cost);
        // Add the cost to the total cost
        total_cost += cost;

        // Replace the two smallest files with the merged file
        files[0] = cost;
        for (int i = 1; i < n - 1; i++) {
            files[i] = files[i + 1];
        }
        n--;
    }

    return total_cost;
}

// Main function
int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    int files[n];
    printf("Enter the sizes of the files: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int total_cost = optimal_merge_pattern(files, n);
    printf("The optimal merge cost is %d\n", total_cost);

}


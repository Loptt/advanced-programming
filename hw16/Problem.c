#include <stdio.h>
#include <stdlib.h>

int solveProblem(int *arr, int size) {
    int biggest = 0;
    int res;

    for (int i = 0; i < size; i++) {
        if (arr[i] > biggest) {
            for (int j = i+1; j < size; j++) {
                res = arr[i] & arr[j];
                if (res > biggest) {
                    biggest = res;
                }
            }
        }
    }

    return biggest;
} 

void mainProblem() {
    int *nums;
    int size;

    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    fscanf(in, "%d", &size);

    nums = (int*) malloc(sizeof(int)*size);

    for (int i = 0; i < size; i++) {
        fscanf(in, "%d", &nums[i]);
    }

    fprintf(out, "%d\n", solveProblem(nums, size));

    free(nums);

    fclose(in);
    fclose(out);
}
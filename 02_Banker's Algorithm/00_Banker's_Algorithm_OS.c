#include <stdio.h>

// প্রসেস এবং রিসোর্সের সংখ্যা
#define P 5 // প্রসেস সংখ্যা
#define R 3 // রিসোর্স সংখ্যা

// সেইফ স্টেট চেক করার ফাংশন
int isSafe(int available[R], int max[P][R], int allocation[P][R]) {
    int need[P][R];
    int finish[P] = {0};
    int work[R];
    int safeSeq[P];
    int count = 0;

    // Work ভেক্টর ইনিশিয়ালাইজ করা
    for (int i = 0; i < R; i++)
        work[i] = available[i];

    // Need ম্যাট্রিক্স ক্যালকুলেট করা
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    // সেইফ সিকোয়েন্স খোঁজা
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    // সেইফ স্টেটে আছে
    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

    return 1;
}

int main() {
    // ইনিশিয়াল রিসোর্স অ্যালোকেশন এবং ম্যাক্সিমাম ডিমান্ড
    int available[R] = {3, 3, 2}; // অ্যাভেইলেবল রিসোর্স
    int max[P][R] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} }; // ম্যাক্সিমাম ডিমান্ড
    int allocation[P][R] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} }; // অ্যালোকেশন

    // সেইফ স্টেট চেক করা
    isSafe(available, max, allocation);

    return 0;
}
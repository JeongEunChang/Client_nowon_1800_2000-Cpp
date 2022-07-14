#include <iostream>
#include <stdio.h>

using namespace std;
long long ay[1000001];
long long N;
long long M;

int replay(int left, int right);

int main()
{
    int best = 0;
    int end = 0;
    int left = 0;
    int right = 0;
    long long result = 0;
    int pivot = 0;
    long long count = 0;

    
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        scanf_s("%d", &ay[i]);

     
        if (ay[i] > best)
            best = ay[i];
    }

    right = best;
    left = 0;


    while (left <= right)
    {
        count = 0;

        pivot = (left + right) / 2;

        for (int i = 0; i < N; i++) {
            int tmp = ay[i];
            int tmp2 = 0;

            if ((tmp - pivot <= 0))
                tmp2 = 0;
            else
                tmp2 = tmp - pivot;


            count = count + tmp2;
        }

        if (count == M)
        {
            result = pivot;
            break;
        }
        if (count < M) {
            right = pivot - 1;
        }
        else if (count > M) {
            left = pivot + 1;
        }
     }

    if (count < M)
        result = pivot - 1;
    else if (count > M)
        result = pivot;

    printf("%d\n", result);

    return 0;
}

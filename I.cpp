#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ll long long

void merge(ll int *one, ll int **result, ll int current, int end){
    int iu = 0, iv = 0;
    while (iu < end || iv < end){
        if (iu >= end){
            (*result)[iu + iv] = one[iv] + current;
            iv += 1;
        }
        else if (iv >= end){
            (*result)[iu + iv] = one[iu];
            iu += 1;
        }
        else{
            if (one[iu] < one[iv] + current){
                (*result)[iu + iv] = one[iu];
                iu += 1;
            }
            else{
                (*result)[iu + iv] = one[iv] + current;
                iv += 1;
            }
        }
    }
}

void sums(int start, int end, ll int *a, ll int **sm){
    (*sm)[0] = 0;
    ll int *tmp = malloc((1 << 20) * sizeof(ll int));
    for (int i = start; i <= end; i++){
        for (int p = 0; p <= 1 << (i - start); p++) tmp[p] = (*sm)[p];
        merge(tmp, sm, a[i], 1 << (i - start));
    }
    free(tmp);
}


int main(){
    bool done;
    int iter_u, iter_v, n, t, c, g, size_u, size_v, cMax = 54;
    ll int s;
    ll int a[45];
    ll int C[cMax + 1][cMax + 1];
    ll int *u = calloc(1 << 20, sizeof(ll int));
    ll int *v = calloc(1 << 20, sizeof(ll int));

    for (int j = 0; j <= cMax; j++){
        C[0][j] = 1;
        C[j][j] = 1;
    }
    for (int i = 1; i <= cMax; i++)
        for (int j = i + 1; j <= cMax; j++)
            C[i][j] = C[i][j - 1] + C[i - 1][j - 1];

    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++){
        scanf("%d %lld", &n, &s);
        size_u = 1 << (n / 2);
        size_v = 1 << (n - n / 2);
        memset(a, 0, n * sizeof(ll int));
        memset(u, 0, size_u * sizeof(ll int));
        memset(v, 0, size_v * sizeof(ll int));
        for (int i = 0; i < n; i++){
            scanf("%d %d", &c, &g);
            a[i] = C[g][c];
        }

        sums(0, n / 2 - 1, a, &u);
        sums(n / 2, n - 1, a, &v);

        iter_u = size_u - 1;
        iter_v = 0;
        done = false;
        while (iter_u >= 0 && iter_v < size_v){
            if (u[iter_u] + v[iter_v] > s) iter_u--;
            else if (u[iter_u] + v[iter_v] < s) iter_v++;
            else{
                printf("done\n");
                done = true;
                break;
            }
        }
        if (!done) printf("deal with it\n");
    }
    free(u); free(v);
}

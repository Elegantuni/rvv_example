#include <stdio.h>
#include <math.h>
#include <time.h>

struct pt {
  float x;
  float y;
  float z;
};

void vec_len_rvv(float *r, struct pt *v, int n);

void vec_len(float *r, struct pt *v, int n){
  for (int i=0; i<n; ++i){
    struct pt p = v[i];
    r[i] = sqrtf(p.x*p.x + p.y*p.y + p.z*p.z);
  }
}

#define N 6
struct pt v[N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

int main(){
  float lens[N], lens_rvv[N];
  clock_t time1, time2, time3, time4;

  time1 = clock();  
  vec_len(lens, v, N);
  time2 = clock();

  time3 = clock();
  vec_len_rvv(lens_rvv, v, N);
  time4 = clock();

  for (int i=0; i<N; ++i){
    printf("%f %f\n", lens[i], lens_rvv[i]);
  }

  printf("The C time completed is %f\n", ((double)(time2 - time1))/CLOCKS_PER_SEC);
  printf("The Asm time completed is %f\n", ((double)(time4 - time3))/CLOCKS_PER_SEC);
    
  return 0;
}

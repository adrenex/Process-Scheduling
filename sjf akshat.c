#include<stdio.h>
#include<limits.h>
typedef struct
{
    int id;
    int burst_time;
    int arr_time;

}process;
int main() {

  int time,smallest, n, i;
  int sumt = 0, sumw = 0;

  printf("enter the no of processes : ");
  scanf("%d", & n);
  process p[n+1];

  for (i = 0; i < n; i++) {
    printf("the arrival time, burst time for process P%d : ", i + 1);
    scanf("%d", &p[i].arr_time);
    scanf("%d", &p[i].burst_time);
    p[i].id =i;
  }

  p[n].burst_time = INT_MAX;
  int count=0;

  printf("Process\t||\tStarting Time\t||\tCompletion time\n");
  for (time = 0; count<n;) {

    smallest = n;

    for (i = 0; i < n; i++) {
      if (p[i].arr_time <= time && p[i].burst_time > 0 && p[i].burst_time < p[smallest].burst_time)
        smallest = i;
    }
    
    printf("P[%d]\t||\t%d\t\t||\t%d\n", smallest + 1,time,time+p[smallest].burst_time );
    sumt += time + p[smallest].burst_time - p[smallest].arr_time;
    sumw += time - p[smallest].arr_time;
    time += p[smallest].burst_time;
    p[smallest].burst_time = 0;
    count++;
  }
  printf("\naverage waiting time = %f", sumw * 1.0 / n);
  printf("\naverage turnaround time = %f", sumt * 1.0 / n);
  return 0;
}

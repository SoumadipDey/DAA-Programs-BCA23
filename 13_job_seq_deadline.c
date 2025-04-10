#include <stdio.h>
struct Job{
    int jId;
    int jProfit;
    int jDeadline;
};
void swap(struct Job* a, struct Job* b){
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}
void jobSort(struct Job jobs[], int n){
    int max;
	for(int i = 0; i < n - 1; i++){
		max = i;
		for(int j = i + 1; j < n; j++){
			if(jobs[j].jProfit > jobs[max].jProfit){
				max = j;	
			}
		}
        swap(&jobs[i],&jobs[max]);
	}
}
int sequenceJobs(struct Job jobs[], int timeslots[], int n, int k){
    int totalProfit = 0;
    // Iterate through the sorted list of jobs
    for (int i = 0; i < n; i++){
        //Find if there is a timeslot available before the deadline.
        int deadline = jobs[i].jDeadline;
        for (int j = deadline - 1; j >= 0 ; j--){
            if(j < k && timeslots[j] == -1){
                totalProfit += jobs[i].jProfit;
                timeslots[j] = jobs[i].jId;
                break;
            }   
        }
    }
    return totalProfit;
}
int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    printf("Enter Profit, and Deadline for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].jProfit, &jobs[i].jDeadline);
        jobs[i].jId = i + 1;
    }
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].jDeadline > maxDeadline)
            maxDeadline = jobs[i].jDeadline;
    }
    int timeslots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        timeslots[i] = -1;
    }
    jobSort(jobs, n);
    int maxProfit = sequenceJobs(jobs, timeslots, n, maxDeadline);
    printf("Scheduled Jobs: ");
    for (int i = 0; i <= maxDeadline; i++) {
        if (timeslots[i] != -1) {
            printf("J%d ", timeslots[i]);
        }
    }
    printf("\nTotal Profit: %d\n", maxProfit);
    return 0;
}
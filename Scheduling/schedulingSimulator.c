#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void fcfs(struct Process *p, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time; 
        }
        p[i].waiting_time = current_time - p[i].arrival_time;
        current_time += p[i].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        p[i].response_time = p[i].waiting_time;
    }
}

int compare(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    return p1->arrival_time - p2->arrival_time;
}

void printGanttChart(struct Process *p, int n, const char* algorithm) {
    printf("\n=== %s ===\nGantt Chart: |", algorithm);
    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[i].pid);
    }
    printf("\n");
    int total_time = 0;
    printf("          ");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", total_time);
        }
        total_time += p[i].burst_time;
        printf(" %d ", total_time);
    }
    printf("\n\n");

    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, 
               p[i].arrival_time, 
               p[i].burst_time,
               p[i].waiting_time, 
               p[i].turnaround_time, 
               p[i].response_time);
    }
}

void sjf (struct Process *p, int n){
	int completed =0;
 	int current = 0;
	int is_completed[n];

	for(int i =0; i< n; i++){
		is_completed[i]=0;
	}	


	while (completed != n) {
		int shortest = -1;
		for( int i =0; i< n ; i++){
			if (p[i].arrival_time <= current && !is_completed[i]) {
				if (shortest ==-1 || p[i].burst_time< p[shortest].burst_time){
					shortest = i;
				}
			
			}
		}
	
        if(shortest ==-1) {
		current++;
	} else {
		current += p[shortest].burst_time;
            	p[shortest].waiting_time = current - p[shortest].arrival_time - p[shortest].burst_time;
            	p[shortest].waiting_time = p[shortest].waiting_time < 0 ? 0 : p[shortest].waiting_time;
            	is_completed[shortest] = 1;
            	completed++;
	}
	for (int i = 0; i < n; i++) {
        	p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        	p[i].response_time = p[i].waiting_time;
    }
	}
}

void avarageTimes( struct Process *p, int n, const char* algorithm) {
    int total_wt = 0, total_tat = 0, total_rt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt += p[i].response_time;
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Response Time: %.2f\n", (float)total_rt / n);

}


int main() {
    int n;
    printf("Number of processes: \n");
    scanf("%d", &n);
    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time and burst time for process %d: \n", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    // FCFS
    qsort(p, n, sizeof(struct Process), compare);
    fcfs(p, n);
    printGanttChart(p, n, "First Come First Served (FCFS)");
    avarageTimes(p, n, "FCFS");


    // SJF
    sjf(p,n);
    printGanttChart(p, n, "Shortest Job First (SJF)");
    avarageTimes(p, n, "SJF");    

    return 0;
}



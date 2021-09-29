

First In First Served:

5
0 1
0 2
0 4
1 5
1 7

P#	AT	BT	CT	TAT	WT

P0	0	  1	  1	  1	  0
P1	0	  2	  3	  3	  1
P2	0	  4	  7	  7	  3
P3	1	  5 	12	11	6
P4	1 	7	  19	18	11

Average Turnaround Time: 8.000000
Average Waiting Time: 4.200000






Shortest Job First:

5 
0 3
0 1
0 2
1 5
1 7

P#	AT	BT	CT	TAT	WT

P0	0 	3 	6 	6 	3
P1	0	  1	  1	  1	  0
P2	0	  2	  3	  3	  1
P3	1	  5	  11	10	5
P4	1	  7	  18	17	10

Average Turnaround Time: 7.400000
Average Waiting Time: 3.800000


Round Robin: 

5 2
0 3
0 2
0 1
1 5
1 7

P#	AT	BT	CT	TAT	WT

P0	0	  3	  10	10	7
P1	0	  2	  3	  3	  1
P2	0	  1	  4	  4	  3
P3	1	  5	  15	14	9
P4	1	  7	  18	17	10

Average Turnaround Time: 9.600000
Average Waiting Time: 6.000000

**Summary**: SJN algorithm tends to work faster and changes its behaviour depending on the order of input, while FIFS algorithm are independent from the order. However, Round Robin algorithm shows long turnaround time for small quantums due to process stopping, and also shows long turnaround time for large quantums due to process waiting. 

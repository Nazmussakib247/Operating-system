def sjf(processes, burst_times):
    n = len(processes)  # Number of processes
    waiting_time = [0] * n  # Initialize waiting time list with zeros
    turnaround_time = [0] * n  # Initialize turnaround time list with zeros

    # Sorting processes by burst time
    sorted_processes = sorted(zip(processes, burst_times), key=lambda x: x[1])
    processes, burst_times = zip(*sorted_processes)

    # Calculate waiting time for each process
    for i in range(1, n):
        waiting_time[i] = waiting_time[i - 1] + burst_times[i - 1]
    
    # Calculate turnaround time for each process
    for i in range(n):
        turnaround_time[i] = waiting_time[i] + burst_times[i]
    
    # Calculate average waiting time and average turnaround time
    avg_waiting_time = sum(waiting_time) / n
    avg_turnaround_time = sum(turnaround_time) / n
    
    return waiting_time, turnaround_time, avg_waiting_time, avg_turnaround_time

# Process list and corresponding burst times
processes = [1, 2, 3, 4]
burst_times = [7, 3, 10, 5]

# Calling the SJF function
wt, tat, avg_wt, avg_tat = sjf(processes, burst_times)

# Printing the results
print("Waiting Time:", wt)
print("Turnaround Time:", tat)
print("Average Waiting Time:", avg_wt)
print("Average Turnaround Time:", avg_tat)

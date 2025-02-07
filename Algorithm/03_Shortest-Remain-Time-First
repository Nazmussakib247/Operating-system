def srft(processes, burst_times):
    remaining_burst_times = burst_times[:]  # Copy burst times for remaining time tracking
    n = len(processes)
    waiting_time = [0] * n
    turnaround_time = [0] * n
    completed = [False] * n  # Track completed processes

    time = 0
    while not all(completed):
        # Select process with the shortest remaining time
        idx = -1
        min_time = float('inf')
        for i in range(n):
            if not completed[i] and remaining_burst_times[i] < min_time:
                min_time = remaining_burst_times[i]
                idx = i
        
        # Process execution
        time += remaining_burst_times[idx]
        remaining_burst_times[idx] = 0
        completed[idx] = True
        
        # Calculate waiting and turnaround times
        waiting_time[idx] = time - burst_times[idx]
        turnaround_time[idx] = waiting_time[idx] + burst_times[idx]

    avg_waiting_time = sum(waiting_time) / n
    avg_turnaround_time = sum(turnaround_time) / n

    return waiting_time, turnaround_time, avg_waiting_time, avg_turnaround_time

# Process list and corresponding burst times
processes = [1, 2, 3, 4]
burst_times = [7, 3, 10, 5]

# Calling the SRFT function
wt, tat, avg_wt, avg_tat = srft(processes, burst_times)

# Printing the results
print("Waiting Time:", wt)
print("Turnaround Time:", tat)
print("Average Waiting Time:", avg_wt)
print("Average Turnaround Time:", avg_tat)

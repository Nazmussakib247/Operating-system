def rr(processes, burst_times, time_quantum):
    n = len(processes)
    waiting_time = [0] * n
    turnaround_time = [0] * n
    remaining_burst_times = burst_times[:]
    time = 0
    queue = processes[:]
    
    while queue:
        current_process = queue.pop(0)
        if remaining_burst_times[current_process - 1] > time_quantum:
            remaining_burst_times[current_process - 1] -= time_quantum
            time += time_quantum
            queue.append(current_process)
        else:
            time += remaining_burst_times[current_process - 1]
            waiting_time[current_process - 1] = time - burst_times[current_process - 1]
            turnaround_time[current_process - 1] = waiting_time[current_process - 1] + burst_times[current_process - 1]
            remaining_burst_times[current_process - 1] = 0

    avg_waiting_time = sum(waiting_time) / n
    avg_turnaround_time = sum(turnaround_time) / n

    return waiting_time, turnaround_time, avg_waiting_time, avg_turnaround_time

# Process list and corresponding burst times
processes = [1, 2, 3, 4]
burst_times = [7, 3, 10, 5]
time_quantum = 4

# Calling the RR function
wt, tat, avg_wt, avg_tat = rr(processes, burst_times, time_quantum)

# Printing the results
print("Waiting Time:", wt)
print("Turnaround Time:", tat)
print("Average Waiting Time:", avg_wt)
print("Average Turnaround Time:", avg_tat)

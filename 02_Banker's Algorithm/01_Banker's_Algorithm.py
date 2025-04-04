# Banker's Algorithm in Python

# Number of processes
P = 5

# Number of resources
R = 3

# Function to find the system is in safe state or not
def isSafe(processes, avail, maxm, allot):
    # Initialize work and finish arrays
    work = [i for i in avail]
    finish = [False] * P
    safe_sequence = [0] * P
    count = 0

    # While all processes are not finished
    # or system is not in safe state.
    while count < P:
        # Find a process which is not finish and
        # whose needs can be satisfied with current
        # work[] resources.
        found = False
        for p in range(P):
            if finish[p] == False:
                # Check if for all resources of
                # current P, needs are less than work
                for j in range(R):
                    if maxm[p][j] - allot[p][j] > work[j]:
                        break
                # If all needs of p were satisfied.
                if j == R - 1:
                    # Add the allocated resources of
                    # current P to the available/work
                    # resources i.e.free the resources
                    for k in range(R):
                        work[k] += allot[p][k]

                    # Add this process to safe sequence.
                    safe_sequence[count] = p
                    count += 1

                    # Mark this p as finished
                    finish[p] = True

                    found = True

        # If we could not find a next process in safe
        # sequence.
        if found == False:
            print("System is not in safe state")
            return False

    # If system is in safe state then
    # safe sequence will be as below
    print("System is in safe state.\nSafe sequence is: ", end=" ")
    print(*safe_sequence)
    return True

# Driver code
if __name__ == "__main__":
    # Available instances of resources
    avail = [3, 3, 2]

    # Maximum R that can be allocated
    # to processes
    maxm = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]

    # Resources allocated to processes
    allot = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]

    # Check system is in safe state or not
    isSafe(P, avail, maxm, allot)
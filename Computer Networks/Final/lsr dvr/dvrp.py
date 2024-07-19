nV = 8
INF = 999
# Algorithm implementation
def floyd_warshall (G):
    distance = list (map(lambda i: list(map(lambda j: j, i)), G))
    # Adding vertices individually
    for k in range(nV):
        for i in range(nV):
            for j in range(nV):
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
    print_solution(distance)

# Printing the solution
def print_solution(distance):
    print(" 0 1 2 3 4 5 6 7")
    for i in range(nV):
        print(str(i) + " ")
        for j in range(nV):
            if(distance[i][j]== INF):
                print("INF", end="")
            else:
                print(distance[i][j], end="")
        print(" ")

G = [[0, 3, 2, 999, 999, 999, 999, 999], [3, 0, 999, 1, 2, 999, 999, 999], [2, 999, 0,1, 999, 999, 4, 999], 
    [999, 1, 1, 0, 999, 4, 999, 5], [999, 2, 999, 999, 0, 1, 999, 999], [999, 999, 999, 4, 1, 0, 999, 999], 
    [999, 999, 4, 999, 999, 999, 0, 3], [999,999, 999, 5, 999, 999, 3, 0]]
floyd_warshall (G)
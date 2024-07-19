import java.util.Scanner;

public class DVR {
  int dist[] = new int[10];
  int from[] = new int[10];

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    DVR rt[] = new DVR[10];
    for (int i = 0; i < 10; i++) {
      rt[i] = new DVR();
    }
    int costmat[][] = new int[20][20];
    int nodes, i, j, k, count = 0;
    System.out.println("\nEnter the number of nodes : ");
    nodes = in.nextInt();
    System.out.println("\nEnter the cost matrix :");
    for (i = 0; i < nodes; i++) {
      for (j = 0; j < nodes; j++) {
        costmat[i][j] = in.nextInt();
        if (costmat[i][j] == 0)
          costmat[i][j] = 999;
        rt[i].dist[j] = costmat[i][j];
        rt[i].from[j] = j;
      }
    }
    do {
      count = 0;
      for (i = 0; i < nodes; i++)
        for (j = 0; j < nodes; j++)
          for (k = 0; k < nodes; k++)
            if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
              rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
              rt[i].from[j] = k;
              count++;
            }
    } while (count != 0);
    for (i = 0; i < nodes; i++) {
      System.out.println("\n For router " + (i + 1) + "\n");
      for (j = 0; j < nodes; j++) {
        System.out.println("\t\nnode :" + (j + 1) + " from " +
            (rt[i].from[j] + 1) + " Distance " + (rt[i].dist[j]));
      }
      System.out.println("\n\n");
    }
  }
}
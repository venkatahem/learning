#include <iostream>
#include <stdlib.h>

using namespace std;

int s;

void printGraph(int ver[], int **edge, int s) {
  int i, j;
  cout << "   ";
  for (i = 0; i < s; i++) {
    cout << ver[i] << " ";
  }
  cout << "\n";
  cout << "   ";
  for (i = 0; i < s; i++) {
    cout << "_"
         << " ";
  }
  cout << "\n";
  for (i = 0; i < s; i++) {
    cout << ver[i] << " |";
    for (j = 0; j < s; j++) {
      cout << edge[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int i, j, k;
  int **edge;
  cout << "No.of vertices: ";
  cin >> s;
  int ver[s];
  edge = (int **)malloc(s * sizeof(int *));
  for (i = 0; i < s; i++) {
    edge[i] = (int *)malloc(sizeof(int) * (s));
  }
  cout << "Enter vertex:" << endl;
  for (i = 0; i < s; i++) {
    cout << "Vertex - " << i + 1 << " :";
    cin >> ver[i];
  }
  k = 0;
  for (i = 0; i < s; i++) {
    for (j = 0; j < s; j++) {
      edge[i][j] = k;
    }
    k++;
  }

  printGraph(ver, edge, s);

  return 7;
}

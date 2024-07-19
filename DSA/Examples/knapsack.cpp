#include <iostream>

using namespace std;

void knapsack(int size, float capacity, float weight[], float profit[])
{
  float ratio[size], insack[size];
  int i, j, k, temp;
  float x = capacity;
  float tot_pro = 0;
  for (i = 0; i < size; i++)
  {
    ratio[i] = profit[i] / weight[i];
  }
  for (i = 0; i < size; i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if (ratio[j] > ratio[i])
      {
        temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;

        temp = weight[j];
        weight[j] = weight[i];
        weight[i] = temp;

        temp = profit[j];
        profit[j] = profit[i];
        profit[i] = temp;
      }
    }
  }
  for (i = 0; i < size; i++)
  {
    insack[i] = 0;
  }
  for (i = 0; i < size; i++)
  {
    if (weight[i] > x)
    {
      break;
    }
    else
    {
      insack[i] = 1;
      x = x - weight[i];
      tot_pro = tot_pro + profit[i];
    }
  }
  if (i < size)
  {
    insack[i] = x / weight[i];
    tot_pro = tot_pro + (insack[i] * profit[i]);
  }

  for (i = 0; i < size; i++)
  {
    cout << "\nItem weight: " << weight[i] << "\nProfit: " << profit[i] << "\nFraction selected: " << insack[i] << endl;
  }
  cout << "\nTotal profit: " << tot_pro << endl;
}

int main()
{
  float weight[] = {3, 6, 2, 3, 5, 7};
  float profit[] = {100, 180, 120, 80, 100, 50};
  float capacity;
  int size = sizeof(weight) / sizeof(int);
  // int pro_wei[size];
  float total;
  int i;
  total = 0;
  for (i = 0; i < size; i++)
  {
    total = total + weight[i];
  }
  cout << "No.of items = " << size - 1 << " & Total weight of items = " << total
       << endl;
  cout << "Knapsack capacity: ";
  cin >> capacity;

  knapsack(size, capacity, weight, profit);
}
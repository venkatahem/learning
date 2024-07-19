#include <iostream>
#include <vector>

using namespace std;
void lcp(char seq1[], char seq2[], int s1, int s2)
{
    int i, j, k, dig = 0, up = 0;
    vector<char> lcs;
    int arr[s1 + 1][s2 + 1];
    for (i = 0; i < s1 + 1; i++)
    {
        for (j = 0; j < s2 + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (i = 1; i < s1 + 1; i++)
    {
        for (j = 1; j < s2 + 1; j++)
        {
            if (seq1[i - 1] == seq2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
    }
    cout << "    0  ";
    for (i = 0; i < s2; i++)
    {
        cout << seq2[i] << "  ";
    }
    cout << "\n\n";
    for (i = 0; i < s1 + 1; i++)
    {
        if (i == 0)
        {
            cout << "0   ";
        }
        else
        {
            cout << seq1[i - 1] << "   ";
        }
        for (j = 0; j < s2 + 1; j++)
        {

            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }

    i = s1;
    j = s2;
    while ((i > 0) && (j > 0))
    {
        if (arr[i][j - 1] == arr[i][j])
        {
            j--;
            // up++;
        }
        if (arr[i - 1][j] == arr[i][j])
        {
            i--;
            up++;
        }
        if (arr[i - 1][j] == arr[i][j - 1])
        {
            if (arr[i][j - 1] == arr[i][j])
            {
                j--;
            }
            else
            {
                lcs.push_back(seq2[j - 1]);
                dig++;
                i--;
                j--;
            }
        }
    }
    cout << "\n\nLongest common sequence: ";
    for (i = lcs.size() - 1; i >= 0; i--)
    {
        cout << lcs[i] << " ";
    }
    cout << "\n\nLength: " << arr[s1][s2];
    cout << "\n\nUp: " << up << " Dig: " << dig;
}
int main()
{
    char seq1[15] = "ABACBCDEAB";
    char seq2[15] = "ACBDACEDA";

    int s1 = 0, s2 = 0;
    int i, j, k;

    for (i = 0; seq1[i] != '\0'; i++)
    {
        s1++;
    }
    for (i = 0; seq2[i] != '\0'; i++)
    {
        s2++;
    }

    lcp(seq1, seq2, s1, s2);
}
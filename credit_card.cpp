#include <bits/stdc++.h>
using namespace std;

#define MAXN 11
long long NUM = 1;
#define ver 2

int cukooHashTable[ver][MAXN];

int pos[ver];

void initialTable()
{
    for (int j = 0; j < MAXN; j++)
        for (int i = 0; i < ver; i++)
            cukooHashTable[i][j] = INT_MIN;
}

int hashedKeys(int function, int key)
{
    switch (function)
    {
    case 1:
        return key % MAXN;
    case 2:
        return (key / MAXN) % MAXN;
    }
}

void place(int key, int tableID, int cnt, int n)
{
    if (cnt == n)
    {
        printf("%d unpositioned\n", key);
        printf("Cycle present. REHASH.\n");
        return;
    }

    for (int i = 0; i < ver; i++)
    {
        pos[i] = hashedKeys(i + 1, key);
        if (cukooHashTable[i][pos[i]] == key)
            return;
    }

    if (cukooHashTable[tableID][pos[tableID]] != INT_MIN)
    {
        int dis = cukooHashTable[tableID][pos[tableID]];
        cukooHashTable[tableID][pos[tableID]] = key;
        place(dis, (tableID + 1) % ver, cnt + 1, n);
    }
    else
        cukooHashTable[tableID][pos[tableID]] = key;
}

void printHashTable()
{
    printf("Final hash tables:\n");

    for (int i = 0; i < ver; i++, printf("\n"))
        for (int j = 0; j < MAXN; j++)
        {
            if (cukooHashTable[i][j] != INT_MIN)
            {
                printf("%d ", cukooHashTable[i][j]);
                NUM *= cukooHashTable[i][j];
            }
        }

    printf("\n");
}

void cuckooFunction(int keys[], int n)
{
    initialTable();

    for (int i = 0, cnt = 0; i < n; i++, cnt = 0)
        place(keys[i], 0, cnt, n);

    printHashTable();
}

int main()
{
    int n;
    cout << "Please enter the size of the Input Array\n"<< endl;
    cin >> n;

    int keys_1[n];
    for (int i = 0; i < n; i++)
    {
        keys_1[i] = rand() % 99;
    }

    cout << "Generated Array is \n\n"<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << keys_1[i] << " ";
    }
    cout << endl;

    cuckooFunction(keys_1, n);

    int m;
    cout << "Please enter the size of the Input Array\n"<< endl;
    cin >> m;

    int keys_2[m];
    for (int i = 0; i < n; i++)
    {
        keys_2[i] = rand() % 99;
    }

    cout << "Generated Array is \n\n"<< endl;
    for (int i = 0; i < m; i++)
    {
        cout << keys_2[i] << " ";
    }
    cout << endl;

    cuckooFunction(keys_2, m);

    string s = to_string(NUM);

    vector<string> vs;
    string demo;

    for (auto i : s)
    {
        if (demo.size() == 4)
        {
            vs.push_back(demo);
            demo = i;
        }
        else
        {
            demo += i;
        }
    }

    vector<int> vnum;
    cout << "Random Credit Card Number Generated is : ";
    for (auto i : vs)
    {
        cout << i << " ";
    }
}

# Kush Munot

### Semester 05

### [My Website](https://kushmunot.netlify.app/)

### Roll Num - 47

### Section A

# Cukoo Hashing and its Applications

There are basic three operations that must be supported by a Hash Table 

1. Lookup(key) which helps you to find the key into the hash table and returns true if the key is found else. It returns false. 
2. Insert(key) which helps you to insert a new key. 
3. Delete(key) which helps you to delete the previous existing key.

Collisions are very likely even if we have a big table to store keys. There are various methods of Hashing linke Open Adressing and Closed Adressing but the above solutions provide expected lookup cost as O(1), the expected worst-case cost of a lookup in Open Addressing (with linear probing) is Ω(log n) and Θ(log n / log log n) in simple chaining.

**Cuckoo hashing** applies the idea of multiple-choice and relocation together and guarantees O(1) worst case lookup time!

### **Illustration**

**Input:**

```
{30, 52, 57, 71, 101, 77, 115, 14, 45, 59}
```

**Hash Functions:**

```
h1(key) = key%11
h2(key) = (key/11)%11
```

![Untitled](https://i.imgur.com/dwXp5Bb.jpg)

## Credit Card or Debit Card number Generator using Cukoo Hashing

In the main function we are taking Input, creating a random array using rand( ), printing that array for convinience and calling the Cukoo( ) Hashig function. The sequence is then stored in a long long NUM named variable. I have converted it into a string and divided the output in a bucket of 4 numbers each. I print this Bucket after the execution is over.

```cpp
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

    cuckoo(keys_1, n);

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

    cuckoo(keys_2, m);

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
```

For Card PIN i do the same thing but after i get NUM i try to split it into 4 parts, add thode four parts and do modulo 10000 to get last 4 digits as pin.

```cpp
int main()
{
    int n;
    cout << "Please enter the size of the Input Array\n"
         << endl;
    cin >> n;
    int keys_1[n];
    for (int i = 0; i < n; i++)
    {
        keys_1[i] = rand() % 99;
    }
    cout << "Generated Array is \n\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << keys_1[i] << " ";
    }
    cout << endl;

    cuckoo(keys_1, n);

    int m;
    cout << "Please enter the size of the Input Array\n"
         << endl;
    cin >> m;

    int keys_2[m];
    for (int i = 0; i < n; i++)
    {
        keys_2[i] = rand() % 99;
    }
    cout << "Generated Array is \n\n"
         << endl;
    for (int i = 0; i < m; i++)
    {
        cout << keys_2[i] << " ";
    }
    cout << endl;

    cuckoo(keys_2, m);

    string s = to_string(NUM);

    cout << NUM << endl;

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

    for (auto i : vs)
    {
        int num = (i[0] - '0') * 1000;
        num += (i[1] - '0') * 100;
        num += (i[2] - '0') * 10;
        num += (i[3] - '0');
        vnum.push_back(num);
    }
    cout << endl;
    long long ans;
    for (auto i : vnum)
    {
        ans += i;
    }

    if (ans % 10000 == ans % 1000)
        cout << "The ATM Pin generated is - 0" << ans % 10000 << endl;
    else
        cout << "The ATM Pin generated is - " << ans % 10000 << endl;

    return 0;
}
```

## Outputs

![Untitled](https://i.imgur.com/BVvAvvS.jpg)

![Untitled](https://i.imgur.com/USPEHwn.jpg)
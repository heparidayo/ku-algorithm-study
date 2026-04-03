int[] arr = new int[26];

string s = Console.ReadLine();
foreach (char c in s)
    arr[c - 'a']++;

foreach (int i in arr)
    Console.Write(i + " ");
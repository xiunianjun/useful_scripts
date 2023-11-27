using System;
using System.Collections.Generic;

namespace ConsoleAppPractice
{
    class Program
    {
        static void Main()
        {
            int[] a = new int[] { 4, -3, 5, -2, -1, 2, 6, -2 };
            int result = FindMinSon(a);
            Console.WriteLine(result);
        }

        public static int FindMinSon(int[] a)
        {
            int len = a.Length;
            List<Node> b = new List<Node>();
            for (int i = 0; i < len+1; i++)
            {
                b.Add(new Node());
            }
            for (int i = 0; i < len; i++)
            {
                b[i + 1].sum = b[i].sum + a[i];
                b[i + 1].index = i + 1;
            }
            int minSum = 3000;
            int sum = 0;
            Sort(b, len);
            foreach (var item in b)
            {
                Console.WriteLine("{0} : {1}",item.index,item.sum);
            }
            for (int i = 1; i < len; i++)
            {
                sum = b[i+1].sum = b[i].sum;
                if (sum > 0 && sum < minSum && b[i+1].index > b[i].index)
                {
                    minSum = sum;
                }
            }
            return minSum;
        }

        public static void Sort(List<Node> b,int len)
        {
            for (int i = len; i >= 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    if (b[j].sum > b[j+1].sum)
                    {
                        Node temp = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp;
                    }
                }
            }
        }
    }

    class Node
    {
        public int sum { get; set; }
        public int index { get; set; }
    }
}
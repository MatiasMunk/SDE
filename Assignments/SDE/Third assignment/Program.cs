using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Third_assignment
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MulTable();
            Console.WriteLine("The biggest number in [190, 291, 145, 209, 280, 200] is " + BiggestNumber(new int[] { 190, 291, 145, 209, 280, 200 }));
            Console.WriteLine("Given the row of numbers [8, 2, 5, 7, 9, 0, 7, 7, 3, 1], the number 7 is adjacent to another 7 " + AdjacentNumCount(new int[] { 8, 2, 5, 7, 9, 0, 7, 7, 3, 1 }) + " times");
            Console.WriteLine("given the row of numbers [45, 23, 44, 68, 65, 70, 80, 81, 82], are there three adjacent numbers that increase by 1 from left to right? " + ThreeIncreasingAdjacent(new int[] { 45, 23, 44, 68, 65, 70, 80, 81, 82 }));
            Console.Write("Prime numbers of 30 are ");
            foreach(var i in PrimeNumbers(30))
            {
                Console.Write(i + " ");
            }

            Console.WriteLine("Text between ##'s of string \"++##--##++\" is " + ExtractString("++##--##++"));
            Console.WriteLine("Alphabet between d & s is " + AlphabetBetween("ds"));
            float[] SumAvg = { SumAndAverage(11, 66)[0], SumAndAverage(11, 66)[1] };
            Console.WriteLine("Sum of numbers 11 to 66: " + SumAvg[0] + ", Avg. of numbers 11 to 66: " + SumAvg[1]);

            DrawTriangle();

            Console.ReadLine();
        }

        private static void MulTable()
        {
            for(int i = 1; i < 11; i++)
            {
                for(int y = 1; y < 11; y++)
                {
                    Console.Write(y * i + " ");
                }
                Console.WriteLine();
            }
        }

        private static int BiggestNumber(int[] _arr)
        {
            if (_arr.Length < 1) return _arr[0];

            int temp_num = 0;
            for(int i = 0; i < _arr.Length; i++)
            {
                if (temp_num < _arr[i]) temp_num = _arr[i];
            }

            return temp_num;
        }

        private static int AdjacentNumCount(int[] _arr)
        {
            if(_arr.Length< 1) return 0;

            int adjacent_count = 0;
            int prev_num = -1337;
            for(int i = 0; i < _arr.Length; i++)
            {
                if (prev_num == _arr[i]) adjacent_count++;
                prev_num = _arr[i];
            }

            return adjacent_count;
        }

        private static bool ThreeIncreasingAdjacent(int[] _arr)
        {
            if (_arr.Length < 3) return false;

            int adjacent_count = 0;
            int prev_num = -1337;
            for (int i = 0; i < _arr.Length; i++)
            {
                if (prev_num == _arr[i] - 1) adjacent_count++;
                else adjacent_count = 0;

                prev_num = _arr[i];
            }

            if (adjacent_count < 2) return false;

            return true;
        }

        private static List<int> PrimeNumbers(int _num)
        {
            List<int> prime_numbers = new List<int> { };

            for (int i = 2; i <= _num; ++i)
            {
                int is_prime = 1;

                for (int j = 2; j <= Math.Sqrt(i); ++j)
                {
                    if (i % j == 0)
                    {
                        is_prime = 0;
                    }
                }

                if (is_prime == 1)
                {
                    prime_numbers.Add(i);
                }
            }

            return prime_numbers;
        }

        private static string ExtractString(string _text)
        {
            int first = _text.IndexOf("##") + 2;
            int second = _text.IndexOf("##", first);

            if (second - first == 0) return "empty string";

            return _text.Substring(first, second - first);
        }

        private static string AlphabetBetween(string _text)
        {
            if (_text[0] >= _text[1])
                return "";

            string alphabet_between = "";

            for (int i = _text[0]; i <= _text[1]; i++)
            {
                alphabet_between += Convert.ToString(Convert.ToChar(i));
            }

            return alphabet_between;
        }

        private static float[] SumAndAverage(int _num1, int _num2)
        {
            int sum = 0;
            float avg = 0;
            int prev_num = _num1;
            for(int i = _num1; i <= _num2; i++)
            {
                prev_num = i;
                sum += prev_num;
            }

            avg = sum / ((float)_num2 + 1 - (float)_num1);

            return new float[] { sum, avg };
        }
        private static void DrawTriangle()
        {
            string stars = "         *";

            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(stars);
                stars = stars.Remove(0, 1);
                stars += "**";
            }
        }
    }
}

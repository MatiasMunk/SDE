using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Second_assignment
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Absolute of 582,22 = " + Abs((float)582.22));
            Console.WriteLine("2 + 90 = " + DivBy2or3(2, 90));
            Console.WriteLine("\"xyz\" consists of all capitalized letters? " + AllCaps("DOG"));
            Console.WriteLine("2+7 or 2*7 > 12? " + SumMulGreaterThanThird(new int[] { 2, 7, 12 }));
            Console.WriteLine("721 is even? " + IsEven(721));
            Console.WriteLine("3, 7, 10 is in an ascending order? " + IsAscending(new int[] { 74, 62, 99 }));
            Console.WriteLine("5,24 is " + PositiveNegativeOrZero((float)5.24));
            Console.WriteLine("2016 is leap year? " + IsLeapYear(2016));

            Console.ReadLine();
        }

        private static float Abs(float _num)
        {
            return Math.Abs((float)_num);
        }

        private static int DivBy2or3(int _num1, int _num2)
        {
            bool divisable = false;
            divisable = _num1 % 2 == 0 && (_num2 % 2 == 0 ? true : false);
            if(divisable) divisable = _num2 % 3 == 0 && (_num2 % 3 == 0 ? true : false);
            return divisable ? _num1 * _num2 : _num1 + _num2;
        }

        private static bool AllCaps(string _text)
        {
            return _text.All(c => char.IsUpper(c));
        }

        private static bool SumMulGreaterThanThird(int[] _arr)
        {
            if (_arr.Length < 3)
                return false;

            bool SumMul = (_arr[0] + _arr[1]) > _arr[2] ? true : (_arr[0] * _arr[1]) > _arr[2] ? true : false;

            return SumMul;
        }

        private static bool IsEven(int _num)
        {
            return _num % 2 == 0;
        }

        private static bool IsAscending(int[] _arr)
        {
            int j = _arr.Length - 1;
            if (j < 1) return true;
            int ai = _arr[0], i = 1;
            while (i <= j && ai <= (ai = _arr[i])) i++;
            return i > j;
        }

        private static string PositiveNegativeOrZero(float _num)
        {
            if (_num == 0)
                return "zero";

            return _num < 0 ? "Negative" : "Positive";
        }

        private static bool IsLeapYear(int _year)
        {
            return _year % 4 == 0;
        }
    }
}

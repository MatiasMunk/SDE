using System;

namespace First__Assignment
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("(2 + 4) * 5 is = " + AddAndMultiply(2, 4, 5));

            if (CtoF((float)-271.15) == -1337) Console.WriteLine("Temperature below absolute zero!");
            else Console.WriteLine("-271.15 Celsius = " + CtoF((float)-271.15) + " Fahrenheit.");

            if (IsEqual(2 + 2, 2 * 2)) Console.WriteLine("2+2 & 2*2 = True");
            else Console.WriteLine("2+2 & 2*2 = False");

            Console.WriteLine("8 mod 5 mod 2 = " + ModuloOperations(8, 5, 2));

            Console.WriteLine("Cube of 2 = " + CubeOf(2));

            SwapInts(87, 45);

            Console.Read();
        }

        private static int AddAndMultiply(int _num1, int _num2, int _num3)
        {
            return (_num1 + _num2) * _num3;
        }

        private static float CtoF(float _degrees)
        {
            return _degrees < -271.15 ? -1337 : (float)(_degrees * 1.8) + 32;
        }

        private static bool IsEqual(int _num1, int _num2)
        {
            return _num1 == _num2;
        }
        private static int ModuloOperations(int _num1, int _num2, int _num3)
        {
            return _num1 % _num2 % _num3;
        }

        private static float CubeOf(int _num)
        {
            return (float)Math.Pow(_num, 3);
        }

        private static void SwapInts(int _num1, int _num2)
        {
            Console.WriteLine("Before: a = " + _num1 + " b = " + _num2);
            /*int temp_swap = _num1;
            _num1 = _num2;
            _num2 = temp_swap;*/
            _num1 = _num2 ^ _num1; //a = a + b;
            _num2 = _num2 ^ _num1; //b = a - b;
            _num1 = _num1 ^ _num2; //a = a - b;
            Console.WriteLine("After: a = " + _num1 + " b = " + _num2);
        }
    }
}
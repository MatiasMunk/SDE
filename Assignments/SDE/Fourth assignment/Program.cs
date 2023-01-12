using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fourth_assignment
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("ABCD character-separated with separator ^ is " + AddSeparator("ABCD", "^"));
            Console.WriteLine("Eye is eye reversed? " + IsPalindrome(""));
            Console.WriteLine("Lenght of 'computer' -> " + StrLen("computer"));
            Console.WriteLine("'qwerty' reversed is -> " + StrReverse("qwerty"));
            Console.WriteLine("Number of words in the sentence \"This is a simple sentence\" -> " + WordCount("This is a simpel sentence"));
            Console.WriteLine("John Doe. -> " + RevertWordsOrder("John Doe."));
            Console.WriteLine("'do' is in the string \"do it now\" " + HowManyOccurrences("do it now", "do") + " times");

            List<char> sorted = new List<char>();
            sorted = SortCharactersDescending("onomatopoeia");
            Console.Write("\"onomatopoeia\" sorted -> ");
            for(int i = 0; i < sorted.Count; i++)
            {
                Console.Write(sorted[i]);
            }
            Console.WriteLine();

            Console.WriteLine("\"kkkktttrrrrrrrrrr\" compressed -> " + CompressString("kkkktttrrrrrrrrrr"));

            Console.ReadLine();
        }

        private static string AddSeparator(string _text, string _separator)
        {
            for(int i = 1; i < _text.Length + 1; i+=2)
            {
                _text = _text.Insert(i, _separator);
            }

            return _text;
        }

        private static bool IsPalindrome(string _text)
        {
            if(string.IsNullOrEmpty(_text)) return true;

            char[] chars = _text.ToCharArray();
            Array.Reverse(chars);
            return _text.ToLower() == new string(chars).ToLower();
        }

        private static int StrLen(string _text)
        {
            return _text.Length > 0 ? _text.Length : 0;
        }
        
        private static string StrReverse(string _text)
        {
            char[] reversed = _text.ToCharArray();
            Array.Reverse(reversed);
            return new string(reversed);
        }
        private static int WordCount(string _text)
        {
            List<string> exploded = new List<string>(_text.Split(' '));
            return exploded.Count;
        }
        
        private static string RevertWordsOrder(string _text)
        {
            List<string> exploded = new List<string>(_text.Remove(_text.Length - 1, 1).Split(' '));
            _text = "";
            exploded.Reverse();

            for (int i = 0; i < exploded.Count; i++)
            {
                if (i == exploded.Count - 1)
                    _text += exploded[i] + ".";
                else
                    _text += exploded[i] + " ";
            }

            return _text;
        }

        private static int HowManyOccurrences(string _text, string _search)
        {
            List<string> exploded = new List<string>(_text.Split(' '));
            int count = 0;
            for (int i = 0; i < exploded.Count; i++)
            {
                if (exploded[i] == _search) count++;
            }

            return count;
        }
        private static List<char> SortCharactersDescending(string _text)
        {
            List<char> exploded = new List<char>(_text.ToList());

            exploded.Sort();
            exploded.Reverse();

            return exploded;
        }
        private static string CompressString(string _text)
        {
            if (_text.Length < 1)
                return "";

            string compressed_string = "";
            char prev_char;
            prev_char = _text[0];
            int count = 0;
            for (int i = 0; i < _text.Length; i++)
            {
                if (_text.ElementAt(i).ToString() != prev_char.ToString())
                {
                    compressed_string += prev_char;
                    compressed_string += count.ToString();
                    count = 0;
                }

                prev_char = _text[i];
                
                count++;
            }

            compressed_string += prev_char;
            compressed_string += count.ToString();
            return compressed_string;
        }
    }
}

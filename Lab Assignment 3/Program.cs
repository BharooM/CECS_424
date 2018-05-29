using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3._1
{
    class Program
    {
        struct Person
        {
            public string name;
            public int age;
        }

        // Print elements in array (int, float, char, string)
        static void printArray<T>(IList<T> arr)
        {
            foreach (T item in arr)
                System.Console.Write(item + " ");
        }

        // Print elements in array (struct)
        static void printStruct(Person[]arr)
        {
            foreach (Person item in arr)
                System.Console.Write(item.name + "-" + item.age + " ");
        }

        // Compare function for passing in to built-in function 'Array.Sort'
        static int cmpfunc(Person a, Person b)
        {
            // Sort by name first then age
            if (a.name.CompareTo(b.name) == 0)
                return a.age.CompareTo(b.age);

            return a.name.CompareTo(b.name);

            /*
            // Sort by age first then name
            if (a.age.CompareTo(b.age) == 0)
                return a.name.CompareTo(b.name);

            return a.age.CompareTo(b.age);
            */
        }

        static void Main(string[] args)
        {
            // Sorting array of integers
            int[] arr_int = { 4, 65, 2, -31, 0, 99, 2, 83, 782 };
            Array.Sort(arr_int);
            printArray<int>(arr_int);
            System.Console.Write("\n\n");

            // Sorting array of floating point values
            float[] arr_float = { 645.32f, 37.40f, 76.30f, 5.40f, -34.23f, 1.11f, -34.94f, 23.37f, 635.46f, -876.22f, 467.73f, 62.26f };
            Array.Sort(arr_float);
            printArray<float>(arr_float);
            System.Console.Write("\n\n");

            // Sorting array of characters
            char[] arr_char = { 'z', 'y', 'a', 't', 'p', 'q', 'l', 'k' };
            Array.Sort(arr_char);
            printArray<char>(arr_char);
            System.Console.Write("\n\n");

            // Sorting array of strings
            string[] arr_string = { "apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant" };
            Array.Sort(arr_string);
            printArray<string>(arr_string);
            System.Console.Write("\n\n");

            // Sorting array of structures
            Person[] arr_struct = { new Person() { name = "Hal", age = 20 },
                                    new Person() { name = "Susann", age = 31},
                                    new Person() { name = "Dwight", age = 19},
                                    new Person() { name = "Kassandra",age = 21},
                                    new Person() { name = "Lawrence", age = 25},
                                    new Person() { name = "Cindy", age = 22},
                                    new Person() { name = "Cory", age = 27},
                                    new Person() { name = "Mac", age = 19},
                                    new Person() { name = "Romana", age = 27},
                                    new Person() { name = "Doretha", age = 32},
                                    new Person() { name = "Danna", age = 20},
                                    new Person() { name = "Zara", age = 23},
                                    new Person() { name = "Rosalyn", age = 26},
                                    new Person() { name = "Risa", age = 24},
                                    new Person() { name = "Benny", age = 28},
                                    new Person() { name = "Juan", age = 33},
                                    new Person() { name = "Natalie", age = 25} };
            Array.Sort<Person>(arr_struct, cmpfunc);
            printStruct(arr_struct);
            System.Console.Write("\n\n");
        }
    }
}

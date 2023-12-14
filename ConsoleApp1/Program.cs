public class Program
{
    public static void Main(string[] args)
    {
        var sr = new StreamReader("D:\\c#_files\\ConsoleApp1\\laba.txt");
        var blocks = GetBlocks(sr); // block is (profession name + profession description)
        var dict = GetFilledDict(blocks);
        PrintMenu(dict);
    }

    private static List<string> GetBlocks(StreamReader sr)
    {
        string text = sr.ReadToEnd();
        var professionBlocks = text.Split('*', StringSplitOptions.RemoveEmptyEntries).ToList();
        return professionBlocks;
    }

    private static Dictionary<int, string[]> GetFilledDict(List<string> blocks)
    {
        var dict = new Dictionary<int, string[]>();
        for (int i = 0; i < blocks.Count; i++)
        {
            string[] pair = blocks[i].Split('^');
            dict[i + 1] = pair;
        }
        return dict;
    }

    private static void PrintMenu(Dictionary<int, string[]> dict)
    {
        while (true)
        {
            foreach (var pair in dict)
                Console.WriteLine($"{pair.Key}. {pair.Value[0].Trim()}");
            Console.WriteLine("0. Выйти");
            Console.WriteLine();

            var value = int.Parse(Console.ReadLine());
            if (value == 0 || !dict.ContainsKey(value)) return;
            Console.WriteLine(dict[value][1]);
        }
    }
}




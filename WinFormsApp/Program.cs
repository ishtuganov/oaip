using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows.Forms;

public class MainForm : Form
{
    private TextBox outputTextBox;
    private Button showMenuButton;

    private List<string> blocks;
    private Dictionary<int, string[]> dict;

    public MainForm()
    {
        InitializeComponent();
        LoadData();
    }

    private void InitializeComponent()
    {
        outputTextBox = new TextBox();
        showMenuButton = new Button();

        outputTextBox.Location = new System.Drawing.Point(10, 10);
        outputTextBox.Size = new System.Drawing.Size(400, 200);
        outputTextBox.Multiline = true;
        outputTextBox.ScrollBars = ScrollBars.Vertical;
        outputTextBox.ReadOnly = true;

        showMenuButton.Location = new System.Drawing.Point(10, 220);
        showMenuButton.Size = new System.Drawing.Size(150, 30);
        showMenuButton.Text = "Показать меню";
        showMenuButton.Click += ShowMenuButton_Click;

        Controls.Add(outputTextBox);
        Controls.Add(showMenuButton);
    }

    private void LoadData()
    {
        try
        {
            using (StreamReader sr = new StreamReader("D:\\c#_files\\ConsoleApp1\\laba.txt"))
            {
                blocks = GetBlocks(sr);
                dict = GetFilledDict(blocks);
            }
        }
        catch (Exception ex)
        {
            MessageBox.Show($"Ошибка при загрузке данных: {ex.Message}");
        }
    }

    private List<string> GetBlocks(StreamReader sr)
    {
        string text = sr.ReadToEnd();
        var professionBlocks = text.Split('*', StringSplitOptions.RemoveEmptyEntries).ToList();
        return professionBlocks;
    }

    private Dictionary<int, string[]> GetFilledDict(List<string> blocks)
    {
        var dict = new Dictionary<int, string[]>();
        for (int i = 0; i < blocks.Count; i++)
        {
            string[] pair = blocks[i].Split('^');
            dict[i + 1] = pair;
        }
        return dict;
    }

    private void ShowMenuButton_Click(object sender, EventArgs e)
    {
        try
        {
            int value = PromptForNumber();
            if (value == 0 || !dict.ContainsKey(value))
            {
                MessageBox.Show("Введено некорректное число.");
                return;
            }

            outputTextBox.Text = dict[value][1];
        }
        catch (FormatException)
        {
            MessageBox.Show("Введите числовое значение.");
        }
    }

    private int PromptForNumber()
    {
        string input = Microsoft.VisualBasic.Interaction.InputBox("Введите число:", "Ввод", "", -1, -1);
        return int.TryParse(input, out int result) ? result : 0;
    }

    [STAThread]
    public static void Main()
    {
        Application.EnableVisualStyles();
        Application.Run(new MainForm());
    }
}

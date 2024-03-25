using MotorBoat.CollectionGenericObjects;
using MotorBoat.Drawnings;

namespace MotorBoat;

/// <summary>
/// Форма работы с компанией и ее коллекцией
/// </summary>
public partial class FormBoatCollection : Form
{
    /// <summary>
    /// Компания
    /// </summary>
    private AbstractCompany? _company = null;
    /// <summary>
    /// Конструктор
    /// </summary>
    public FormBoatCollection()
    {
        InitializeComponent();
    }
    /// <summary>
    /// Выбор компании
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ComboBoxSelectorCompany_SelectedIndexChanged(object sender, EventArgs e)
    {
        switch (comboBoxSelectorCompany.Text)
        {
            case "Хранилище":
                _company = new Harbor(pictureBox.Width,
                pictureBox.Height, new MassiveGenericObjects<DrawningBoat>());
                break;
        }
    }

    /// <summary>
    /// Создание объекта класса-перемещения
    /// </summary>
    /// <param name="type">Тип создаваемого объекта</param>
    private void CreateObject(string type)
    {
        if (_company == null)
        {
            return;
        }
        Random random = new();
        DrawningBoat drawningBoat;
        switch (type)
        {
            case nameof(DrawningBoat):
                drawningBoat = new DrawningBoat(random.Next(100, 300),
                random.Next(1000, 3000), GetColor(random));
                break;
            case nameof(DrawningMotorBoat):
                // TODO вызов диалогового окна для выбора цвета
                drawningBoat = new DrawningMotorBoat(random.Next(100,
                300), random.Next(1000, 3000),
                Color.FromArgb(random.Next(0, 256),
                random.Next(0, 256), random.Next(0, 256)),
                Color.FromArgb(random.Next(0, 256),
                random.Next(0, 256), random.Next(0, 256)),
                Convert.ToBoolean(random.Next(0, 2)),
                Convert.ToBoolean(random.Next(0, 2)));
                break;
            default:
                return;
        }
        if (_company + drawningBoat != -1)
        {
            MessageBox.Show("Объект добавлен");
            pictureBox.Image = _company.Show();
        }
        else
        {
            MessageBox.Show("Не удалось добавить объект");
        }
    }
    /// <summary>
    /// Получение цвета
    /// </summary>
    /// <param name="random">Генератор случайных чисел</param>
    /// <returns></returns>
    private static Color GetColor(Random random)
    {
        Color color = Color.FromArgb(random.Next(0, 256), random.Next(0,
        256), random.Next(0, 256));
        ColorDialog dialog = new();
        if (dialog.ShowDialog() == DialogResult.OK)
        {
            color = dialog.Color;
        }
        return color;
    }

    /// <summary>
    /// Добавление лодки
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ButtonAddBoat_Click(object sender, EventArgs e) => CreateObject(nameof(DrawningBoat));
    /// <summary>
    /// Добавление моторной лодки
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ButtonAddMotorBoat_Click(object sender, EventArgs e) => CreateObject(nameof(DrawningMotorBoat));
    /// <summary>
    /// Удаление лодки
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ButtonRemoveBoat_Click(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(maskedTextBoxPosition.Text) || _company == null)
        {
            return;
        }
        if (MessageBox.Show("Удалить объект?", "Удаление",
        MessageBoxButtons.YesNo, MessageBoxIcon.Question) != DialogResult.Yes)
        {
            return;
        }
        int pos = Convert.ToInt32(maskedTextBoxPosition.Text);
        if (_company - pos != null)
        {
            MessageBox.Show("Объект удален");
            pictureBox.Image = _company.Show();
        }
        else
        {
            MessageBox.Show("Не удалось удалить объект");
        }

    }
    /// <summary>
    /// Передача объекта в другую форму
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ButtonGoToCheck_Click(object sender, EventArgs e)
    {
        if (_company == null)
        {
            return;
        }
        DrawningBoat? boat = null;
        int counter = 100;
        while (boat == null)
        {
            boat = _company.GetRandomObject();
            counter--;
            if (counter <= 0)
            {
                break;
            }
        }
        if (boat == null)
        {
            return;
        }
        FormMotorBoat form = new()
        {
            SetBoat = boat
        };
        form.ShowDialog();
    }
    /// <summary>
    /// Перерисовка коллекции
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ButtonRefresh_Click(object sender, EventArgs e)
    {
        if (_company == null)
        {
            return;
        }
        pictureBox.Image = _company.Show();
    }
}

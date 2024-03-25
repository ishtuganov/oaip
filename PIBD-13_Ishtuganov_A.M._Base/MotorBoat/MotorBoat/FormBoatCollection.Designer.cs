namespace MotorBoat
{
    partial class FormBoatCollection
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            groupBoxTools = new GroupBox();
            buttonRefresh = new Button();
            buttonGoToCheck = new Button();
            buttonRemoveBoat = new Button();
            maskedTextBoxPosition = new MaskedTextBox();
            buttonAddMotorBoat = new Button();
            buttonAddBoat = new Button();
            comboBoxSelectorCompany = new ComboBox();
            pictureBox = new PictureBox();
            groupBoxTools.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // groupBoxTools
            // 
            groupBoxTools.Controls.Add(buttonRefresh);
            groupBoxTools.Controls.Add(buttonGoToCheck);
            groupBoxTools.Controls.Add(buttonRemoveBoat);
            groupBoxTools.Controls.Add(maskedTextBoxPosition);
            groupBoxTools.Controls.Add(buttonAddMotorBoat);
            groupBoxTools.Controls.Add(buttonAddBoat);
            groupBoxTools.Controls.Add(comboBoxSelectorCompany);
            groupBoxTools.Dock = DockStyle.Right;
            groupBoxTools.Location = new Point(630, 0);
            groupBoxTools.Name = "groupBoxTools";
            groupBoxTools.Size = new Size(170, 483);
            groupBoxTools.TabIndex = 0;
            groupBoxTools.TabStop = false;
            groupBoxTools.Text = "Инструменты";
            // 
            // buttonRefresh
            // 
            buttonRefresh.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            buttonRefresh.Location = new Point(6, 401);
            buttonRefresh.Name = "buttonRefresh";
            buttonRefresh.Size = new Size(158, 33);
            buttonRefresh.TabIndex = 6;
            buttonRefresh.Text = "Обновить";
            buttonRefresh.UseVisualStyleBackColor = true;
            buttonRefresh.Click += ButtonRefresh_Click;
            // 
            // buttonGoToCheck
            // 
            buttonGoToCheck.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            buttonGoToCheck.Location = new Point(6, 319);
            buttonGoToCheck.Name = "buttonGoToCheck";
            buttonGoToCheck.Size = new Size(158, 33);
            buttonGoToCheck.TabIndex = 5;
            buttonGoToCheck.Text = "Передать на тесты";
            buttonGoToCheck.UseVisualStyleBackColor = true;
            buttonGoToCheck.Click += ButtonGoToCheck_Click;
            // 
            // buttonRemoveBoat
            // 
            buttonRemoveBoat.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            buttonRemoveBoat.Location = new Point(6, 227);
            buttonRemoveBoat.Name = "buttonRemoveBoat";
            buttonRemoveBoat.Size = new Size(158, 32);
            buttonRemoveBoat.TabIndex = 4;
            buttonRemoveBoat.Text = "Удалить лодку";
            buttonRemoveBoat.UseVisualStyleBackColor = true;
            buttonRemoveBoat.Click += ButtonRemoveBoat_Click;
            // 
            // maskedTextBoxPosition
            // 
            maskedTextBoxPosition.Location = new Point(6, 198);
            maskedTextBoxPosition.Mask = "00";
            maskedTextBoxPosition.Name = "maskedTextBoxPosition";
            maskedTextBoxPosition.Size = new Size(158, 23);
            maskedTextBoxPosition.TabIndex = 3;
            maskedTextBoxPosition.ValidatingType = typeof(int);
            // 
            // buttonAddMotorBoat
            // 
            buttonAddMotorBoat.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            buttonAddMotorBoat.Location = new Point(6, 112);
            buttonAddMotorBoat.Name = "buttonAddMotorBoat";
            buttonAddMotorBoat.Size = new Size(158, 38);
            buttonAddMotorBoat.TabIndex = 2;
            buttonAddMotorBoat.Text = "Добавление моторной лодки";
            buttonAddMotorBoat.UseVisualStyleBackColor = true;
            buttonAddMotorBoat.Click += ButtonAddMotorBoat_Click;
            // 
            // buttonAddBoat
            // 
            buttonAddBoat.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            buttonAddBoat.Location = new Point(6, 71);
            buttonAddBoat.Name = "buttonAddBoat";
            buttonAddBoat.Size = new Size(158, 35);
            buttonAddBoat.TabIndex = 1;
            buttonAddBoat.Text = "Добавление лодки";
            buttonAddBoat.UseVisualStyleBackColor = true;
            buttonAddBoat.Click += ButtonAddBoat_Click;
            // 
            // comboBoxSelectorCompany
            // 
            comboBoxSelectorCompany.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            comboBoxSelectorCompany.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBoxSelectorCompany.FormattingEnabled = true;
            comboBoxSelectorCompany.Items.AddRange(new object[] { "Хранилище" });
            comboBoxSelectorCompany.Location = new Point(6, 22);
            comboBoxSelectorCompany.Name = "comboBoxSelectorCompany";
            comboBoxSelectorCompany.Size = new Size(158, 23);
            comboBoxSelectorCompany.TabIndex = 0;
            comboBoxSelectorCompany.SelectedIndexChanged += ComboBoxSelectorCompany_SelectedIndexChanged;
            // 
            // pictureBox
            // 
            pictureBox.Dock = DockStyle.Fill;
            pictureBox.Location = new Point(0, 0);
            pictureBox.Name = "pictureBox";
            pictureBox.Size = new Size(630, 483);
            pictureBox.TabIndex = 1;
            pictureBox.TabStop = false;
            // 
            // FormBoatCollection
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 483);
            Controls.Add(pictureBox);
            Controls.Add(groupBoxTools);
            Name = "FormBoatCollection";
            Text = "Коллекция лодок";
            groupBoxTools.ResumeLayout(false);
            groupBoxTools.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBoxTools;
        private Button buttonAddBoat;
        private ComboBox comboBoxSelectorCompany;
        private Button buttonAddMotorBoat;
        private PictureBox pictureBox;
        private Button buttonGoToCheck;
        private Button buttonRemoveBoat;
        private MaskedTextBox maskedTextBoxPosition;
        private Button buttonRefresh;
    }
}
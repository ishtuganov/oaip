namespace MotorBoat
{
    partial class FormMotorBoat
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
            pictureBoxMotorBoat = new PictureBox();
            buttonLeft = new Button();
            buttonDown = new Button();
            buttonRight = new Button();
            buttonUp = new Button();
            comboBoxStrategy = new ComboBox();
            buttonStrategyStep = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBoxMotorBoat).BeginInit();
            SuspendLayout();
            // 
            // pictureBoxMotorBoat
            // 
            pictureBoxMotorBoat.Dock = DockStyle.Fill;
            pictureBoxMotorBoat.Location = new Point(0, 0);
            pictureBoxMotorBoat.Name = "pictureBoxMotorBoat";
            pictureBoxMotorBoat.Size = new Size(861, 447);
            pictureBoxMotorBoat.TabIndex = 0;
            pictureBoxMotorBoat.TabStop = false;
            // 
            // buttonLeft
            // 
            buttonLeft.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonLeft.BackgroundImage = Properties.Resources.leftArrow;
            buttonLeft.BackgroundImageLayout = ImageLayout.Stretch;
            buttonLeft.Location = new Point(734, 400);
            buttonLeft.Name = "buttonLeft";
            buttonLeft.Size = new Size(35, 35);
            buttonLeft.TabIndex = 2;
            buttonLeft.UseVisualStyleBackColor = true;
            buttonLeft.Click += ButtonMove_Click;
            // 
            // buttonDown
            // 
            buttonDown.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonDown.BackgroundImage = Properties.Resources.downArrow;
            buttonDown.BackgroundImageLayout = ImageLayout.Stretch;
            buttonDown.Location = new Point(772, 400);
            buttonDown.Name = "buttonDown";
            buttonDown.Size = new Size(35, 35);
            buttonDown.TabIndex = 3;
            buttonDown.UseVisualStyleBackColor = true;
            buttonDown.Click += ButtonMove_Click;
            // 
            // buttonRight
            // 
            buttonRight.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonRight.BackgroundImage = Properties.Resources.rightArrow;
            buttonRight.BackgroundImageLayout = ImageLayout.Stretch;
            buttonRight.Location = new Point(810, 400);
            buttonRight.Name = "buttonRight";
            buttonRight.Size = new Size(35, 35);
            buttonRight.TabIndex = 4;
            buttonRight.UseVisualStyleBackColor = true;
            buttonRight.Click += ButtonMove_Click;
            // 
            // buttonUp
            // 
            buttonUp.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonUp.BackgroundImage = Properties.Resources.upArrow;
            buttonUp.BackgroundImageLayout = ImageLayout.Stretch;
            buttonUp.Location = new Point(772, 362);
            buttonUp.Name = "buttonUp";
            buttonUp.Size = new Size(35, 35);
            buttonUp.TabIndex = 5;
            buttonUp.UseVisualStyleBackColor = true;
            buttonUp.Click += ButtonMove_Click;
            // 
            // comboBoxStrategy
            // 
            comboBoxStrategy.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBoxStrategy.FormattingEnabled = true;
            comboBoxStrategy.Items.AddRange(new object[] { "К центру", "К краю" });
            comboBoxStrategy.Location = new Point(724, 12);
            comboBoxStrategy.Name = "comboBoxStrategy";
            comboBoxStrategy.Size = new Size(121, 23);
            comboBoxStrategy.TabIndex = 7;
            // 
            // buttonStrategyStep
            // 
            buttonStrategyStep.Location = new Point(774, 41);
            buttonStrategyStep.Name = "buttonStrategyStep";
            buttonStrategyStep.Size = new Size(75, 23);
            buttonStrategyStep.TabIndex = 8;
            buttonStrategyStep.Text = "Шаг";
            buttonStrategyStep.UseVisualStyleBackColor = true;
            buttonStrategyStep.Click += buttonStrategyStep_Click;
            // 
            // FormMotorBoat
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(861, 447);
            Controls.Add(buttonStrategyStep);
            Controls.Add(comboBoxStrategy);
            Controls.Add(buttonUp);
            Controls.Add(buttonRight);
            Controls.Add(buttonDown);
            Controls.Add(buttonLeft);
            Controls.Add(pictureBoxMotorBoat);
            Name = "FormMotorBoat";
            Text = "Моторная лодка";
            ((System.ComponentModel.ISupportInitialize)pictureBoxMotorBoat).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private PictureBox pictureBoxMotorBoat;
        private Button buttonLeft;
        private Button buttonDown;
        private Button buttonRight;
        private Button buttonUp;
        private ComboBox comboBoxStrategy;
        private Button buttonStrategyStep;
    }
}
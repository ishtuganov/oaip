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
            buttonCreate = new Button();
            buttonLeft = new Button();
            buttonDown = new Button();
            buttonRight = new Button();
            buttonUp = new Button();
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
            // buttonCreate
            // 
            buttonCreate.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
            buttonCreate.Location = new Point(12, 412);
            buttonCreate.Name = "buttonCreate";
            buttonCreate.Size = new Size(75, 23);
            buttonCreate.TabIndex = 1;
            buttonCreate.Text = "Создать";
            buttonCreate.UseVisualStyleBackColor = true;
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
            // 
            // FormMotorBoat
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(861, 447);
            Controls.Add(buttonUp);
            Controls.Add(buttonRight);
            Controls.Add(buttonDown);
            Controls.Add(buttonLeft);
            Controls.Add(buttonCreate);
            Controls.Add(pictureBoxMotorBoat);
            Name = "FormMotorBoat";
            Text = "Моторная лодка";
            ((System.ComponentModel.ISupportInitialize)pictureBoxMotorBoat).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private PictureBox pictureBoxMotorBoat;
        private Button buttonCreate;
        private Button buttonLeft;
        private Button buttonDown;
        private Button buttonRight;
        private Button buttonUp;
    }
}
namespace PWR_CALCULATOR
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            comboBox1 = new ComboBox();
            text_wattstoDbm = new Label();
            textBox1 = new TextBox();
            text_dbm = new Label();
            difference_dBm = new Label();
            difference_W = new Label();
            text_Msred = new Label();
            text_W = new Label();
            copy_dBm = new Button();
            copy_W = new Button();
            label1 = new Label();
            SuspendLayout();
            // 
            // comboBox1
            // 
            comboBox1.DropDownHeight = 150;
            comboBox1.DropDownWidth = 80;
            comboBox1.Font = new Font("Arial Nova Cond Light", 9F, FontStyle.Regular, GraphicsUnit.Point);
            comboBox1.FormattingEnabled = true;
            comboBox1.IntegralHeight = false;
            comboBox1.Items.AddRange(new object[] { "1", "2", "3", "4", "5", "6", "10", "20", "25", "40", "45", "50", "100" });
            comboBox1.Location = new Point(11, 12);
            comboBox1.Margin = new Padding(8, 0, 8, 0);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(68, 30);
            comboBox1.TabIndex = 0;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            comboBox1.SelectionChangeCommitted += comboBox1_SelectionChangeCommitted;
            // 
            // text_wattstoDbm
            // 
            text_wattstoDbm.AutoSize = true;
            text_wattstoDbm.Font = new Font("Arial Nova Cond Light", 9F, FontStyle.Regular, GraphicsUnit.Point);
            text_wattstoDbm.Location = new Point(92, 15);
            text_wattstoDbm.Margin = new Padding(2, 0, 2, 0);
            text_wattstoDbm.Name = "text_wattstoDbm";
            text_wattstoDbm.Size = new Size(10, 22);
            text_wattstoDbm.TabIndex = 3;
            text_wattstoDbm.Text = "\r\n";
            text_wattstoDbm.Click += watts_Click;
            // 
            // textBox1
            // 
            textBox1.Font = new Font("Arial Nova Cond Light", 9F, FontStyle.Regular, GraphicsUnit.Point);
            textBox1.Location = new Point(11, 51);
            textBox1.Margin = new Padding(2, 4, 2, 4);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(68, 29);
            textBox1.TabIndex = 4;
            textBox1.TextChanged += textBox1_TextChanged;
            textBox1.KeyPress += textBox1_KeyPress;
            // 
            // text_dbm
            // 
            text_dbm.AutoSize = true;
            text_dbm.Font = new Font("Arial Nova Cond Light", 9F, FontStyle.Regular, GraphicsUnit.Point);
            text_dbm.Location = new Point(6, 84);
            text_dbm.Margin = new Padding(2, 0, 2, 0);
            text_dbm.Name = "text_dbm";
            text_dbm.Size = new Size(235, 22);
            text_dbm.TabIndex = 5;
            text_dbm.Text = "DIFFERENCE WITH RATED (dBm) :";
            text_dbm.Click += label1_Click;
            // 
            // difference_dBm
            // 
            difference_dBm.AutoSize = true;
            difference_dBm.BackColor = SystemColors.Control;
            difference_dBm.Font = new Font("Arial Nova Cond", 9F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            difference_dBm.Location = new Point(20, 114);
            difference_dBm.Margin = new Padding(2, 0, 2, 0);
            difference_dBm.Name = "difference_dBm";
            difference_dBm.Size = new Size(10, 22);
            difference_dBm.TabIndex = 6;
            difference_dBm.Text = "\r\n";
            difference_dBm.Click += label2_Click;
            // 
            // difference_W
            // 
            difference_W.AutoSize = true;
            difference_W.Font = new Font("Arial Nova Cond", 9F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            difference_W.Location = new Point(20, 182);
            difference_W.Margin = new Padding(2, 0, 2, 0);
            difference_W.Name = "difference_W";
            difference_W.Size = new Size(0, 22);
            difference_W.TabIndex = 7;
            // 
            // text_Msred
            // 
            text_Msred.AutoSize = true;
            text_Msred.Font = new Font("Arial Nova Cond Light", 9F, FontStyle.Regular, GraphicsUnit.Point);
            text_Msred.Location = new Point(92, 54);
            text_Msred.Margin = new Padding(2, 0, 2, 0);
            text_Msred.Name = "text_Msred";
            text_Msred.Size = new Size(114, 22);
            text_Msred.TabIndex = 8;
            text_Msred.Text = "MEASURED (W)";
            text_Msred.Click += label4_Click;
            // 
            // text_W
            // 
            text_W.AutoSize = true;
            text_W.Font = new Font("Arial Nova Cond Light", 9F, FontStyle.Regular, GraphicsUnit.Point);
            text_W.Location = new Point(6, 157);
            text_W.Margin = new Padding(2, 0, 2, 0);
            text_W.Name = "text_W";
            text_W.Size = new Size(219, 22);
            text_W.TabIndex = 9;
            text_W.Text = "DIFFERENCE WITH RATED (W) :";
            text_W.Click += text_W_Click;
            // 
            // copy_dBm
            // 
            copy_dBm.BackColor = SystemColors.Control;
            copy_dBm.BackgroundImageLayout = ImageLayout.None;
            copy_dBm.Font = new Font("Arial Nova Cond Light", 10F, FontStyle.Regular, GraphicsUnit.Point);
            copy_dBm.ForeColor = SystemColors.ActiveCaptionText;
            copy_dBm.ImageAlign = ContentAlignment.TopCenter;
            copy_dBm.Location = new Point(243, 77);
            copy_dBm.Margin = new Padding(2, 4, 2, 4);
            copy_dBm.Name = "copy_dBm";
            copy_dBm.Size = new Size(54, 34);
            copy_dBm.TabIndex = 11;
            copy_dBm.Text = "copy";
            copy_dBm.TextImageRelation = TextImageRelation.TextBeforeImage;
            copy_dBm.UseVisualStyleBackColor = false;
            copy_dBm.Click += copy_dBm_Click;
            // 
            // copy_W
            // 
            copy_W.BackColor = SystemColors.Control;
            copy_W.BackgroundImageLayout = ImageLayout.None;
            copy_W.Font = new Font("Arial Nova Cond Light", 10F, FontStyle.Regular, GraphicsUnit.Point);
            copy_W.ForeColor = SystemColors.ActiveCaptionText;
            copy_W.ImageAlign = ContentAlignment.TopCenter;
            copy_W.Location = new Point(241, 157);
            copy_W.Margin = new Padding(2, 4, 2, 4);
            copy_W.Name = "copy_W";
            copy_W.Size = new Size(56, 34);
            copy_W.TabIndex = 12;
            copy_W.Text = "copy";
            copy_W.TextImageRelation = TextImageRelation.TextAboveImage;
            copy_W.UseVisualStyleBackColor = false;
            copy_W.Click += copy_W_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Calibri", 8F, FontStyle.Italic, GraphicsUnit.Point);
            label1.Location = new Point(6, 237);
            label1.Name = "label1";
            label1.Size = new Size(213, 57);
            label1.TabIndex = 12;
            label1.Text = "pwrCal v1.0 { internal use only }\r\nAbraham\r\n\r\n";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(12F, 29F);
            AutoScaleMode = AutoScaleMode.Font;
            AutoSizeMode = AutoSizeMode.GrowAndShrink;
            AutoValidate = AutoValidate.EnableAllowFocusChange;
            BackgroundImageLayout = ImageLayout.None;
            ClientSize = new Size(309, 280);
            Controls.Add(label1);
            Controls.Add(copy_W);
            Controls.Add(copy_dBm);
            Controls.Add(text_W);
            Controls.Add(text_Msred);
            Controls.Add(difference_W);
            Controls.Add(difference_dBm);
            Controls.Add(text_dbm);
            Controls.Add(textBox1);
            Controls.Add(text_wattstoDbm);
            Controls.Add(comboBox1);
            Font = new Font("Arial Nova Cond", 12F, FontStyle.Regular, GraphicsUnit.Point);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            Margin = new Padding(8, 0, 8, 0);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "pwrCal";
            TopMost = true;
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ComboBox comboBox1;
        private Label text_wattstoDbm;
        private TextBox textBox1;
        private Label text_dbm;
        private Label difference_dBm;
        private Label difference_W;
        private Label text_Msred;
        private Label text_W;
        private Button copy_dBm;
        private Button copy_W;
        private Label label1;
    }
}
namespace PWR_CALCULATOR
{
    public partial class Form1 : Form

    {
        public Form1()
        {
            InitializeComponent();


        }
        string w_val;
        string inputVal;
        double ratedPwr;
        string copydbm;
        string WATT;
        double W;



        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

            w_val = comboBox1.GetItemText(comboBox1.SelectedItem);
            double watt_Val = (Convert.ToDouble(w_val)) * 1000;
            W = Convert.ToDouble(w_val);
            double i = 10 * (Math.Log10(watt_Val));
            double j = Math.Round(i, 4);
            ratedPwr = j;
            string rated_dBm = Convert.ToString(j);
            text_wattstoDbm.Text = comboBox1.GetItemText(comboBox1.SelectedItem) + "W = " + rated_dBm + " dBm";

        }

        private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
        {

        }

        private void watts_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {


            if (textBox1.Text != String.Empty)
            {

                inputVal = textBox1.Text;
                double input = (Convert.ToDouble(inputVal)) * 1000;
                double input2 = (Convert.ToDouble(inputVal));
                double ii = 10 * (Math.Log10(input));
                double jj = Math.Round(ii, 4);
                double difference = jj - ratedPwr;
                double round_off = Math.Round(difference, 4);
                copydbm = Convert.ToString(round_off);
                string pwr = copydbm;
                double diff_W = input2 - W;
                double roundOff_W = Math.Round(diff_W, 2);
                WATT = Convert.ToString(roundOff_W);
                difference_dBm.Text = pwr + " dBm";
                difference_W.Text = WATT + " W";

            }

            if (textBox1.Text == String.Empty)
            {
                difference_W.Text = "";
                difference_dBm.Text = "";
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            char ch = e.KeyChar;

            if (ch == 46 && textBox1.Text.IndexOf('.') != -1)
            {
                e.Handled = true;
                return;

            }

            if (!Char.IsDigit(ch) && ch != 8 && ch != 46)
            {
                e.Handled = true;
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void copy_dBm_Click(object sender, EventArgs e)
        {

            if (copydbm != null)
            {
                if (difference_dBm.Text != null)
                {
                    Clipboard.SetDataObject(copydbm);
                }
            }
            else
                difference_dBm.Text = String.Empty;
        }

        private void copy_W_Click(object sender, EventArgs e)
        {
            if (difference_W.Text != "")
            {
                Clipboard.SetDataObject(WATT);
            }
            else
                difference_W.Text = String.Empty;
        }

        private void text_W_Click(object sender, EventArgs e)
        {

        }
    }
}